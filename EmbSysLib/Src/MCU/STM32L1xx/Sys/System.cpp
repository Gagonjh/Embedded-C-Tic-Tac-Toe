//*******************************************************************
/*!
\file   System.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\brief  Controller specific implementation of class cSystem
*/

//*******************************************************************
#include "MCU/System.h"

//-------------------------------------------------------------------
#include "stm32l1xx.h"

//*******************************************************************
//
// cSystem
//
//*******************************************************************
//-------------------------------------------------------------------
unsigned char cSystem::cntInterrupt = 0;

//-------------------------------------------------------------------
cSystem::cSystem( unsigned char disableInterrupts )
{
  disableWatchdog();
  if( disableInterrupts )
  {
    disableInterrupt();
  }
}

//-------------------------------------------------------------------
void cSystem::start( void )
{
  enableInterrupt();
}

//-------------------------------------------------------------------
void cSystem::disableInterrupt( void )
{
  __set_PRIMASK(1); // __disable_irq();
  cntInterrupt++;
}

//-------------------------------------------------------------------
void cSystem::enableInterrupt( void )
{
  if(cntInterrupt > 0)
  {
    cntInterrupt--;
  }
  if(cntInterrupt == 0)
  {
     __set_PRIMASK(0); //__enable_irq();
  }
}

//-------------------------------------------------------------------
void cSystem::enterISR( void )
{
  cntInterrupt++;
}

//-------------------------------------------------------------------
void cSystem::leaveISR( void )
{
  if( cntInterrupt > 0 )
  {
    cntInterrupt--;
  }
}

//-------------------------------------------------------------------
/*
void cSystem::run( void )
{
  // nothing to do
}
*/

//-------------------------------------------------------------------
void cSystem::enableWatchdog( MODE mode )
{
  DWORD pr  = 0;
  DWORD rlr = 0;

  // timeout = LSI(40kHz) / (4*2^pr * pl)
  switch( mode )
  {
    default:
    case WD_TIMEOUT_16ms:   pr = 0; rlr =  160; break; // 40kHz/4*16ms
    case WD_TIMEOUT_32ms:   pr = 0; rlr =  320; break; // 40kHz/4*32ms
    case WD_TIMEOUT_65ms:   pr = 0; rlr =  650; break; // 40kHz/4*65ms
    case WD_TIMEOUT_130ms:  pr = 0; rlr = 1300; break; // 40kHz/4*130ms
    case WD_TIMEOUT_260ms:  pr = 0; rlr = 2600; break; // 40kHz/4*260ms
    case WD_TIMEOUT_520ms:  pr = 1; rlr = 2600; break; // 40kHz/8*520ms
    case WD_TIMEOUT_1000ms: pr = 2; rlr = 2500; break; // 40kHz/16*1000ms
    case WD_TIMEOUT_2000ms: pr = 3; rlr = 2500; break; // 40kHz/32*2000ms
  }

  IWDG->KR  = 0x5555;
  IWDG->PR  = pr;
  IWDG->KR  = 0x5555;
  IWDG->RLR = rlr;
  IWDG->KR  = 0xAAAA;
  IWDG->KR  = 0xCCCC;
}

//-------------------------------------------------------------------
void cSystem::disableWatchdog( void )
{
  // The watchdog can NOT be disabled by software
}

//-------------------------------------------------------------------
void cSystem::feedWatchdog( void )
{
  IWDG->KR  = 0xAAAA;
}

//-------------------------------------------------------------------
void cSystem::reset( void )
{
  __disable_irq();
  enableWatchdog( WD_TIMEOUT_16ms );

  while(1);
}

//-------------------------------------------------------------------
void cSystem::delayMicroSec( unsigned short delay )
{
  // Calibration:
  delay *= 6.0;
  for(;delay>0;delay--)
  {
//    asm volatile("nop");
  }
}

//-------------------------------------------------------------------
void cSystem::delayMilliSec( unsigned short delay )
{
  for(;delay>0;delay--)
    delayMicroSec(1000);
}

//*******************************************************************
//
// SystemInit
//
//*******************************************************************
/*!
This function is a summary of "system_stm32l1xx.c" generated by 
"STM32L1xx_Clock_Configuration_V1.1.0.xls"

\see STMicroelectronics, AN3309 Clock configuration tool for 
STM32L1xx microcontrollers, Doc ID 18200 Rev 2, January 2012
*/
void SystemInit( void )
{
  // Clock control register
  RCC->CR   |=      RCC_CR_MSION;     // MSI clock enable: MSI oscillator ON

  // Clock configuration register
  RCC->CFGR &= ~(   RCC_CFGR_MCOPRE   // reset ...
                  | RCC_CFGR_MCOSEL
                  | RCC_CFGR_PPRE1
                  | RCC_CFGR_PPRE2
                  | RCC_CFGR_HPRE
                  | RCC_CFGR_SW );

  // Clock control register
  RCC->CR   &= ~(   RCC_CR_HSION      // reset ...
                  | RCC_CR_HSEON
                  | RCC_CR_PLLON
                  | RCC_CR_CSSON );
  RCC->CR   &= ~(   RCC_CR_HSEBYP );  // reset ...

  // Clock configuration register
  RCC->CFGR &= ~(   RCC_CFGR_PLLMUL   // reset ...
                  | RCC_CFGR_PLLDIV
                  | RCC_CFGR_PLLSRC );

  // Clock interrupt register
  RCC->CIR   =  0;                    // Disable all interrupts

  //*****************************************************************
  // Configure:
  // - System clock frequency
  // - AHB/APBx prescalers
  // - Flash settings
  //*****************************************************************

  //-----------------------------------------------------------------
  #if defined (_HSE_BYPASS_ON )
    RCC->CR |= (RCC_CR_HSEON | RCC_CR_HSEBYP);
  #elif defined (_HSE_BYPASS_OFF )
    RCC->CR |= (RCC_CR_HSEON );
  #else
    #error "_HSE_BYPASS not defined"
  #endif

  // Clock control register
  // Needed in ADC (only?):
  RCC->CR |= RCC_CR_HSION;

  // Wait for HSE is ready or timeout
  for( unsigned i = 0; i < HSE_STARTUP_TIMEOUT; i++ )
  {
    if( RCC->CR & RCC_CR_HSERDY ) 
      break;
  }

  if( RCC->CR & RCC_CR_HSERDY )
  {
    // Flash Acess Control Register
    FLASH->ACR |= FLASH_ACR_ACC64;      // 64-bit access: enable
    FLASH->ACR |= FLASH_ACR_PRFTEN;     // Prefetch: enable
    FLASH->ACR |= FLASH_ACR_LATENCY;    // Latency: one wait state

    // Advanced Peripheral Bus Enable Register
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;  // Power interface clock: enable

    // Power Control Register
    PWR->CR = PWR_CR_VOS_0;             // Voltage scaling range selection: range 1 (1.8 V)
    while( PWR->CSR & PWR_CSR_VOSF );   // Wait until voltage regulator is ready

    // Clock Configuration Register
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;    // AHB prescaler:                   HCLK  = SYSCLK
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;   // APB high-speed prescaler (APB2): PCLK2 = HCLK
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;   // APB low-speed  prescaler (APB1): PCLK1 = HCLK

    RCC->CFGR |= (  RCC_CFGR_PLLSRC_HSE // PLL entry clock source: HSE
                  | RCC_CFGR_PLLMUL12   // PLL multiplication factor: PLLVCO = PLL clock entry x 12
                  | RCC_CFGR_PLLDIV3);  // PLL output division: PLL clock output = PLLVCO / 3

    // Clock control register
    RCC->CR |= RCC_CR_PLLON;            // PLL enable: ON
    while( !(RCC->CR & RCC_CR_PLLRDY) );// Wait until PLL is ready

    // Clock Configuration Register
    RCC->CFGR |= RCC_CFGR_SW_PLL;       // System clock switch: PLL used as system clock

    // Wait for system clock switch is ready
    while( (RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL ); 
  }

  else
  {
    // Error: Wrong clock configuration
  }

  // System Control Block
  SCB->VTOR = FLASH_BASE | 0x00; // Vector Table Relocation in Internal FLASH
}

//EOF

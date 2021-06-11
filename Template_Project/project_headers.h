//Author:     Joshua Hahn  
//Projekt:    Gardienen Steuerung
//Version:    1.0
//Datum:      11.06.2021

#ifndef project_headers_H
#define project_headers_H

//*******************************************************************
#include "../EmbSysLib/Src/lib.h"
#include "Module/RTOS.h"

//*******************************************************************
#if defined _MCU_TYPE_STM32L1XX
  #include "configSTM32L1xx.h"
#elif defined _MCU_TYPE_STM32F7XX
  #include "configSTM32F7xx.h"
#elif defined _MCU_TYPE_LPC1758
  #include "configLPC1758.h"
#elif defined _MCU_TYPE_VIRTUAL
  #include "configVirtual.h"
#else
  #error "Device type not defined"
#endif

#endif
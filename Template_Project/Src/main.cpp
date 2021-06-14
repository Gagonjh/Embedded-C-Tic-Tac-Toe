#include "./project_headers.h"
#include "Module/RTOS.h"
#include "configSTM32F7xx.h"


//*******************************************************************
class cTask_Example : public cTaskHandler::Task
{
  public:
    //---------------------------------------------------------------
    unsigned cnt;
    //---------------------------------------------------------------
    cTask_Example(cTaskHandler &taskHandler)
    : Task(taskHandler)
    {
      cnt = 0;
    }

  private:
    //---------------------------------------------------------------
    virtual void update(void)
    {
      cnt++;
    }
};

//*******************************************************************
class cRtosTask_Example : public cRTOS::Task
{
  public:
    //---------------------------------------------------------------
    cRtosTask_Example(cRTOS &rtosIn )

    : cRTOS::Task( rtosIn, 500/* stack size*/ )

    {
      sec = 0;
      Start();
    }

    //---------------------------------------------------------------
    virtual ~cRtosTask_Example()
    {
    }

    //---------------------------------------------------------------
    virtual void update( )
    {
      while( 1 )
      {
        Pause( 10 );
        if( timer.timeout() )
        {
          sec+=0.1f;
        }
      }
    }

    //---------------------------------------------------------------
    virtual void OnStop(void)
    {
    }

    //---------------------------------------------------------------
    virtual void OnStart(void)
    {
      timer.start( 100 );
    }

    //---------------------------------------------------------------
    float   sec;

    cRTOS::Timer timer;
};


//*******************************************************************
cTaskHandler  taskHandler(&timer);

cTask_Example task_Example(taskHandler);

//*******************************************************************
cRTOS_RR<3> rtos( 100/*time per task [ms]*/ );

cRtosTask_Example  rtos_task_Example( rtos );

//*******************************************************************
int main(void)
{
  int num = 0;

  #ifdef USE_GRAPHIC_DISPLAY
    disp.setBackColor(cHwDisplayGraphic::Navy);
    disp.clear();
  #endif

  while(1)
  {
    switch( enc.get() )
    {
        case cDevControlEncoder::LEFT:     num -= 1; break;
        case cDevControlEncoder::RIGHT:    num += 1; break;
        case cDevControlEncoder::CTRL_DWN: num  = 0; break;
        default:                                     break;
    }

    cHwRTC::Properties prop;
    rtc.get( prop );

//    disp.printf(1,0,20,"Timer-Task: %d",   task_Example.cnt );
//    disp.printf(2,0,20,"RTOS-Task:  %.1f", rtos_task_Example.sec );
//    disp.printf(3,0,20,"BTN:%d Enc:%2d RTC:%2d", btn.get(),num, prop.second );

    if( btn.getEvent() == cDevDigital::ACTIVATED )
    {
      led.toggle();
    }

    dacA.set( adcA.get() );


    #ifdef USE_GRAPHIC_DISPLAY
      cDevControlPointer::cData event = pointer.get();
			WORD x = event.posX-50 < 0 ? 0 : event.posX-50;
			WORD y = event.posY-50 < 0 ? 0 : event.posY-50;
			if(event.posX<390 && event.posX > 100 && event.posY < 390 && event.posY > 100) {
				disp.drawFrame(x,y,100,100,2, cHwDisplayGraphic::Red );
			}
				
//      disp.drawFrame(x,y,100,100,2, cHwDisplayGraphic::Red );
      disp.drawText( 440,20, 18, "x:%3d y:%3d ctrl:0x%02x",  event.posX, event.posY, event.flags );
			
			
			Field f(disp);
			f.drawField();
      disp.refresh();
    #endif
  }
}

//EOF

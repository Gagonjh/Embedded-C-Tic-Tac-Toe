#include "project_headers.h"
#include "./configSTM32F7xx.h"

int main(void)
{
  #ifdef USE_GRAPHIC_DISPLAY
		Field field(disp);
    disp.setBackColor(cHwDisplayGraphic::Navy);
    disp.clear();
  #endif

  while(1)
  {
    #ifdef USE_GRAPHIC_DISPLAY
      cDevControlPointer::cData event = pointer.get();
			field.drawField();
			if(event.posX<390 && event.posX > 100 && event.posY < 390 && event.posY > 100) {
				WORD x = event.posX-50 < 0 ? 0 : event.posX-50;
				WORD y = event.posY-50 < 0 ? 0 : event.posY-50;
				disp.drawFrame(x,y,100,100,2, cHwDisplayGraphic::Red );
			}
				
//      disp.drawText( 440,20, 18, "x:%3d y:%3d ctrl:0x%02x",  event.posX, event.posY, event.flags );
			
			

      disp.refresh();
    #endif
  }
}

//EOF

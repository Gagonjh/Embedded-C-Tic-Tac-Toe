#include "project_headers.h"
#include "./configSTM32F7xx.h"

int main(void)
{
  #ifdef USE_GRAPHIC_DISPLAY
		Field field(disp);
		Pages pages(disp,0,"Test");
    disp.clear();
  #endif

  while(1)
  {
    #ifdef USE_GRAPHIC_DISPLAY
		//daten der toeucheingabe
			cDevControlPointer::cData event = pointer.get();
			pages.drawpage();
		
		
		
		
		
		
		/*Testfunktionen von Start
			//Ausgabe des Testspielfeldes
			field.drawField();
		//Augabe von quadraten auf dem Display im gwählten bereich der Touch eingabe
			if(event.posX<390 && event.posX > 100 && event.posY < 390 && event.posY > 100) {
				WORD x = event.posX-50 < 0 ? 0 : event.posX-50;
				WORD y = event.posY-50 < 0 ? 0 : event.posY-50;
				disp.drawFrame(x,y,100,100,2, cHwDisplayGraphic::Red );
			}
				
//      disp.drawText( 440,20, 18, "x:%3d y:%3d ctrl:0x%02x",  event.posX, event.posY, event.flags );
			*/
			

      disp.refresh();
    #endif
  }
}

//EOF

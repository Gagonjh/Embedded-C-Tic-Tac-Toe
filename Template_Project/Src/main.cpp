/*! 
 *  \brief     Main Klasse des Projektes
 *  \details   This class is used to demonstrate a number of section commands.
 *  \author    Joshua Hahn
 *  \author    Yasin Calli
 *  \date      08.06.2021
 */

#include "./project_headers.h"
#include "./configSTM32F7xx.h"

cDevDisplayGraphic& disp1 = disp;
uint8_t gameMode = 1;

int main(void)
{
		Cells defaultCells;
		Game* game;
		disp.refresh();
		Pages& pages_Instance = Pages::instance();

		short posX = -1;
		short posY = -1;
		short page = -1;
		short gamestate = -2;
		//Fix falsche Startfarbe
		disp1.setBackColor(Style::instance().color_Backround);
		disp1.setTextColor(Style::instance().color_Font);
    disp.clear();

  while(1)
  {
    #ifdef USE_GRAPHIC_DISPLAY
		//daten der toucheingabe
			cDevControlPointer::cData event = pointer.get();
			if(event.flags == event.CTRL_DWN &&(posX == -1)&& (posY == -1))
			{
				posX = event.posX;
				posY = event.posY;
			}
			else
			{
				posX = -1;
				posY = -1;
			}
			
			if(page == 1)
			{
				if(gamestate == -2)
				{
					game = new Game();
					gamestate = -1;
				}
				else if(gamestate >= 0)
				{
					disp.drawText(460,240, 18, gamestate == 0 ? "Unentschieden!":"Spieler %d gewinnt!", gamestate);
					//history überschreiben
					//ausgabe gewinner
				}
				else if (gamestate == -1)
				{
					gamestate = game -> ttt_classic(posX,posY);
				}
			}
			else if(page!= 1 && gamestate != -2)
			{
				//destructor
				gamestate = -2;
			}
			
/*
			//TEST: Augabe von quadraten auf dem Display im gw�hlten bereich der Touch eingabe
			if(posX<750 && posX > 50 && posY < 750 && posY > 50) {
				WORD x = event.posX-50 < 0 ? 0 : posX-50;
				WORD y = event.posY-50 < 0 ? 0 : posY-50;
				disp.drawFrame(x,y,100,100,2, cHwDisplayGraphic::Red );
				//disp.drawText(440,150,18, "%d %d",posX,posY);
			}
			else
			{
				//disp.drawText(440,150,18, "%d %d",posX,posY);
				//disp.drawText(440,190,18, "%d %d",event.posX,event.posY);
			}
*/		
//      disp.drawText( 440,20, 18, "x:%3d y:%3d ctrl:0x%02x",  event.posX, event.posY, event.flags );
		//menueinstance.drawpage();
		
		page = pages_Instance.display_current_page(posX,posY);
    disp.refresh();
    #endif
  }
}

//EOF

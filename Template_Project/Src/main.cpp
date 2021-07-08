/*! 
 *  \brief     Main Klasse des Projektes
 *  \details   This class is used to demonstrate a number of section commands.
 *  \author    Joshua Hahn
 *  \author    Yasin Calli
 *  \date      08.06.2021
 */

#include "./Project_Headers.h"
#include "./configSTM32F7xx.h"

cDevDisplayGraphic& disp1 = disp;
uint8_t gameMode = 1;

int main(void)
{
		Cells defaultCells;
		Game* game;
		disp.refresh();
		Pages& pages_Instance = Pages::instance();
		
		uint8_t ranDOOM = 0;
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
		ranDOOM = (ranDOOM+1)%69;
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
			
			//Game
			if(page == 1)
			{
				if(gamestate == -2)
				{
					game = new Game();
					gamestate = -1;
				}
				else if(gamestate >= 0 && Page_Game::instance().restart_state != 2)
				{
					Page_History::instance().newWinner(gamestate); //!gewinner schreiben
					disp.drawText(480,180, 18, gamestate == 0 ? "Unentschieden!":"Spieler %d gewinnt!", gamestate);
					Page_Game::instance().restart_state = 1; 	//! 1 restart Button aktiviert
					Pages::instance().draw_button(iButtons_cor_G[1][0],iButtons_cor_G[1][2],iButtons_cor_G[1][3]-iButtons_cor_G[1][2],iButtons_cor_G[1][1]-iButtons_cor_G[1][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Revanche!");
					//history überschreiben
					gamestate = -3;
				}
				else if (gamestate == -1)
				{
					gamestate = game -> ttt_classic(posX,posY,ranDOOM);
				}
				else if( Page_Game::instance().restart_state == 2)
				{
					gamestate = -2;
					Page_Game::instance().restart_state = 0; 	//! 0 restart Button deaktiviert
					delete game;
				}
			}
			else if((page!= 1 && gamestate != -2)) //! 2 restart des games
			{
				gamestate = -2;
				Page_Game::instance().restart_state = 0; 	//! 0 restart Button deaktiviert
				delete game;
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

			
		//Ausgabe der Page
		//disp.drawBitmap(20,20,30,30,Symbole::instance().test);
		
		
		page = pages_Instance.display_current_page(posX,posY);
    disp.refresh();
    #endif
  }
}

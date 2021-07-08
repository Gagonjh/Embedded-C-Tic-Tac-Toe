/*! 
 *  \brief     	
 *  \details   
 *  \author			Yasin Calli 
 *  \author    	Joshua Hahn
 */

#include "./Project_Headers.h"

short Game::ttt_classic(short posX,short posY, uint8_t ranDOOM)
{
		Page_Game::instance().output_Current_Player(controller -> getcurrentPlayer() );	//! Ausgabe des aktiven Spielers
	if(posX<390 && posX > 100 && posY < 390 && posY > 100 && controller -> getcurrentPlayer() != 2) 
		{
			bool isInputValid = controller -> handleUserInput(posX, posY);
			disp1.refresh();
			return controller -> getGameState();
		}
		//AI move
		if(gameMode==1 && controller -> getcurrentPlayer() == 2)
				{
					if(waitAi == 20)
					{
						controller -> aiMove(ranDOOM);
						waitAi = 0;
					}
					else
					{
						waitAi++;
					}
					return controller -> getGameState();
				}

	return -1;
}
Game::Game()
{
	controller = new Controller;
	waitAi = 0;
}

Game::~Game()
{
	delete controller;
}

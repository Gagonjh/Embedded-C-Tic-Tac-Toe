/*! 
 *  \brief     	
 *  \details   
 *  \author			Yasin Calli 
 *  \author    	Joshua Hahn
 */

#include "./Project_Headers.h"

short Game::ttt_classic(short posX,short posY, uint8_t ranDOOM)
{
	if(posX<390 && posX > 100 && posY < 390 && posY > 100) 
		{
			bool isInputValid = controller -> handleUserInput(posX, posY);
			disp1.refresh();
			if(gameMode==1 && isInputValid)
				{
						controller -> aiMove(ranDOOM);
				}
			return controller -> getGameState();
		}
	return -1;
}
Game::Game()
{
	controller = new Controller;
}

Game::~Game()
{
	delete controller;
}

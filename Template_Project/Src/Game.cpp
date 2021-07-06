#include "./project_headers.h"

Game::Game(BYTE gameMode)
{
	gameMode = gameMode;
}

void Game::newGame()
{
	Controller controller;
	this->controller = controller;
}

short Game::ttt_classic(short posX,short posY)
{
	if(posX<390 && posX > 100 && posY < 390 && posY > 100) 
		{
			bool isInputValid = controller.handleUserInput(posX, posY);
			disp1.refresh();
			if(gameMode==1 && isInputValid)
				{
						controller.aiMove();
				}
			return controller.getGameState();
		}
	return -1;
}

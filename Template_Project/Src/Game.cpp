#include "./project_headers.h"

Game::Game(short gameMode,Controller controller, Field field):controller(controller),field(field)
{
	this->gameMode = gameMode;
	this->field.drawField();
	field.drawField();
	disp1.refresh();
}

void Game::ttt_classic(short eventPosX,short eventPosY, bool isPressed)
{
	if(isPressed && posX == -1 && posY == -1)
		{
			posX = eventPosX;
			posY = eventPosY;
		}
	else
		{
			posX = -1;
			posY = -1;
		}
	if(posX<390 && posX > 100 && posY < 390 && posY > 100) 
		{
			controller.control(posX, posY);
			short state = controller.getGameState();
			disp1.refresh();
			if(gameMode==1) 
				{
						controller.aiMove();
				}
		}
	disp1.refresh();
}

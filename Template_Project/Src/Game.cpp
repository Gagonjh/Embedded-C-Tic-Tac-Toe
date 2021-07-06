#include "./project_headers.h"

Game::Game(short gameMode,Controller controller, Field field):controller(controller),field(field)
{
	this->gameMode = gameMode;
	this->field.drawField();
	field.drawField();
	disp1.refresh();
}

short Game::ttt_classic(short eventPosX,short eventPosY)
{
	if(posX<390 && posX > 100 && posY < 390 && posY > 100) 
		{
			controller.control(posX, posY);
			disp1.refresh();
			if(gameMode==1)
				{
						controller.aiMove();
				}
			return controller.getGameState();
		}
	return -1;
}

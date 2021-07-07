/*! 
 *  \brief     	
 *  \details   
 *  \author			Yasin Calli 
 *  \author    	Joshua Hahn
 */

#include "./Project_Headers.h"

Controller::Controller()
{
	field = new Field;
	cells = new Cells;
	field -> drawField();
	currentPlayer=1;
	round=0;
};

Controller::~Controller()
{
	delete field;
	delete cells;
}

bool Controller::handleUserInput(short posX, short posY)
{
	for(BYTE i = 0; i<9; i++)
		{
			Coordinates cellCoords = {cells -> cells[i].x,cells -> cells[i].y};
			short xDiff = abs(cellCoords.x - posX);
			short yDiff = abs(cellCoords.y - posY);
			if(xDiff < 50 && yDiff<50) 
				{
					if(cells -> cells[i].player==0)
						{
							cells -> cells[i].player = this->currentPlayer;
							field -> drawToken(cells -> cells[i]);
							this->currentPlayer=this->currentPlayer%2+1;
							round++;
							return true;
						}
				}
		}
	return false;
};

/**
 * Check if game is over.
 *
 * @return -1 if nothing is decided yet, 0 if it's a draw or 1 or 2 if player 1 or player 2 has won.
 */
short Controller::getGameState()
{
	short state = 0;
	if(this->cells -> rowIsComplete()) 
		{
			state = this->currentPlayer == 1 ? 2 : 1;
		}
	else if(round==9)
		{
			state = 0;
		} 
	else 
		{
			state = -1;
		}
	return state;
}

void Controller::aiMove()
{
	while(1)
	{
		if(round == 9)
		{
			break;
		}
		int value = rand()%9;
		if(this->cells -> cells[value].player==0)
		{
			this->handleUserInput(cells -> cells[value].x,cells -> cells[value].y);
			break;
		}
	}
}

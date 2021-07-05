#include "./project_headers.h"

Controller::Controller(Cells cellsToControl, Field field):cells(cellsToControl),field(field)
{
	currentPlayer=1;
	round=0;
};

void Controller::control(short posX, short posY)
{
				if(posX<390 && posX > 100 && posY < 390 && posY > 100) 
					{
						for(int i = 0; i<9; i++)
							{
								Coordinates cellCoords = {cells.cells[i].x,cells.cells[i].y};
								short xDiff = abs(cellCoords.x - posX);
								short yDiff = abs(cellCoords.y - posY);
								if(xDiff < 50 && yDiff<50) 
									{
										if(cells.cells[i].player==0)
											{
												Token playerToken(cellCoords,this->currentPlayer);
												field.drawToken(playerToken);
												cells.cells[i].player = this->currentPlayer;
												this->currentPlayer=this->currentPlayer%2+1;
												round++;
											}
									}
							}
					}
};

/**
 * Check if game is over.
 *
 * @return -1 if nothing is decided yet, 0 if it's a draw or 1 or 2 if player 1 or player 2 has won.
 */
short Controller::getGameState()
{
	short state = 0;
	if(this->cells.rowIsComplete()) 
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

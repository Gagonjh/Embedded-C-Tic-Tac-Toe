#include "./project_headers.h"

short currentPlayer=1;
short round=0;

Controller::Controller(cDevDisplayGraphic& display, Cells cellsToControl, short cellsCount, Field field):display(display),cells(cellsToControl), cellsCount(cellsCount), field(field){};

void Controller::control(short posX, short posY)
{
		if(this->cellsCount == 9)
			{
				if(posX<390 && posX > 100 && posY < 390 && posY > 100) 
					{
						for(int i = 0; i<cellsCount; i++)
							{
								Coordinates cellCoords = {cells.cells[i].x,cells.cells[i].y};
								short xDiff = abs(cellCoords.x - posX);
								short yDiff = abs(cellCoords.y - posY);
								if(xDiff < 50 && yDiff<50) 
									{
										if(cells.cells[i].player==0)
											{
												Token playerToken(cellCoords,currentPlayer);
												field.drawToken(playerToken);
												cells.cells[i].player = currentPlayer;
												currentPlayer=currentPlayer%2+1;
												round++;
											}
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
short Controller::isGameOver()
{
	if(this->cells.rowIsComplete(display)) 
		{
			return currentPlayer;
		}
	else if(round==9)
		{
			return 0;
		} 
	else 
		{
			return -1;
		}
}

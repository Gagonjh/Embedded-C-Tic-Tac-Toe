#include "./project_headers.h"

void Cells::initializeCells()
{
	cells= new Coordinates[9];
	Coordinates newCells[9] = {
												{115,115,0},
												{245,115,0},
												{375,115,0},
												{115,245,0},
												{245,245,0},
												{375,245,0},
												{115,375,0},
												{245,375,0},
												{375,375,0}
										};
	for(int i = 0; i<9; i++)
	{
				cells[i] = newCells[i];
	}
}

void Cells::initializeDefaultRows()
{
	topRow = new short[3];
	centerRow = new short[3];
	bottomRow = new short[3];
	leftColumn = new short[3];
	centerColumn = new short[3];
	rightColumn = new short[3];
	downDiagonal = new short[3];
	upDiagonal = new short[3];
	for(short i = 0; i<3; i++)
	{
		topRow[i] = i;
		centerRow[i] = 3+i;
		bottomRow[i] = 6+i;
		leftColumn[i] = 0+3*i;
		centerColumn[i] = (i*3)+1;
		rightColumn[i] = (i*3)+2;
		downDiagonal[i] = i*(3+1);
		upDiagonal[i] = 6-(i*2);
	}
}

// Weitere gr��en to be implemented
Cells::Cells()
{
	initializeCells();
	initializeDefaultRows();
};

bool Cells::rowIsComplete(cDevDisplayGraphic& display)
{
	short rowValues[8] = {0,0,0,0,0,0,0,0};
	for(int i = 0;i<3;i++)
	{
		rowValues[0] += cells[topRow[i]].player == 0 ? 0 : cells[topRow[i]].player+2;
		rowValues[1] += cells[centerRow[i]].player == 0 ? 0 : cells[centerRow[i]].player+2;
		rowValues[2] += cells[bottomRow[i]].player == 0 ? 0 : cells[bottomRow[i]].player+2;
		rowValues[3] += cells[leftColumn[i]].player == 0 ? 0 : cells[leftColumn[i]].player+2;
		rowValues[4] += cells[centerColumn[i]].player == 0 ? 0 : cells[centerColumn[i]].player+2;
		rowValues[5] += cells[rightColumn[i]].player == 0 ? 0 : cells[rightColumn[i]].player+2;
		rowValues[6] += cells[upDiagonal[i]].player == 0 ? 0 : cells[upDiagonal[i]].player+2;
		rowValues[7] += cells[downDiagonal[i]].player == 0 ? 0 : cells[downDiagonal[i]].player+2;
	}
/*
				display.drawText( 440,1*20, 18, "Row value %d", topRow[0]);
				display.drawText( 440,2*20, 18, "Row value %d", centerRow[0]);
				display.drawText( 440,3*20, 18, "Row value %d", bottomRow[0]);
				display.drawText( 440,4*20, 18, "Row value %d", leftColumn[0]);
				display.drawText( 440,5*20, 18, "Row value %d", centerColumn[0]);
				display.drawText( 440,6*20, 18, "Row value %d", rightColumn[0]);
				display.drawText( 440,7*20, 18, "Row value %d", downDiagonal[0]);
				display.drawText( 440,8*20, 18, "Row value %d", upDiagonal[0]);
*/
	for(int i=0; i<8; i++) 
		{
				display.drawText( 440,1*20, 18, "Row value %d", rowValues[0]);
				display.drawText( 440,2*20, 18, "Row value %d", rowValues[1]);
				display.drawText( 440,3*20, 18, "Row value %d", rowValues[2]);
				display.drawText( 440,4*20, 18, "Row value %d", rowValues[3]);
				display.drawText( 440,5*20, 18, "Row value %d", rowValues[4]);
				display.drawText( 440,6*20, 18, "Row value %d", rowValues[5]);
				display.drawText( 440,7*20, 18, "Row value %d", rowValues[6]);
				display.drawText( 440,8*20, 18, "Row value %d", rowValues[7]);
			if(rowValues[i] == 9 || rowValues[i] == 12) 
				{
					return true;
				}
		}
	return false;
}

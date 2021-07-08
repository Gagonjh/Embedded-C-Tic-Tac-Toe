/*! 
 *  \brief     	Speichert den Zustand des Spielfeldes
 *  \details   	Speicher die Informationen ueber die Reihen und Spielsteine die auf dem Feld liegen.
 *  \author			Yasin Calli 
 *  \author    	Joshua Hahn
 */

#include "./Project_Headers.h"

/*!
	\brief Destruktor der Cells Klasse
	\details Loescht alle nach der Erstellung erzeugten Koordinaten und Reiheninformationen aus dem Speicher.
*/
Cells::~Cells()
{
	delete cells;
	delete topRow;
	delete centerRow;
	delete bottomRow;
	delete leftColumn;
	delete centerColumn;
	delete rightColumn;
	delete downDiagonal;
	delete upDiagonal;
}

/*!
	\brief Erstellt die Spielfeldinformationen
	\details Erstellt ein neues Koordinatenfeld und initialisiert diesen.
	\sa Coordinates
*/
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
	for(BYTE i = 0; i<9; i++)
	{
				cells[i] = newCells[i];
	}
}

/*!
	\brief Erstellt die Reiheninformationen
	\details Erstellt mehrere BYTE Felder, welche Informationen ueber die Spielsteinfolge der Spieler speichert.
*/
void Cells::initializeDefaultRows()
{
	topRow = new BYTE[3];
	centerRow = new BYTE[3];
	bottomRow = new BYTE[3];
	leftColumn = new BYTE[3];
	centerColumn = new BYTE[3];
	rightColumn = new BYTE[3];
	downDiagonal = new BYTE[3];
	upDiagonal = new BYTE[3];
	for(BYTE i = 0; i<3; i++)
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

/*!
	\brief Konstruktor der Cells Klasse
	\details Initialisiert die Felder und Reiheninformationen.
	\sa Cells::initializeCells(), Cells::initializeDefaultRows()
*/
Cells::Cells()
{
	initializeCells();
	initializeDefaultRows();
};

/*!
	\brief Ueberprueft den Reihenzustand
	\details Ueberprueft ob ein Spieler eine ganze Reihe für sich beanspruchen konnte.
	\return Gibt true zurueck falls eine Reihe komplett ist und false wenn nicht.
	\sa Cells::initializeCells(), Cells::initializeDefaultRows()
*/
bool Cells::rowIsComplete()
{
	BYTE rowValues[8] = {0,0,0,0,0,0,0,0};
	for(BYTE i = 0;i<3;i++)
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
	for(int i=0; i<8; i++) 
		{
			if(rowValues[i] == 9 || rowValues[i] == 12) 
				{
					return true;
				}
		}
	return false;
}

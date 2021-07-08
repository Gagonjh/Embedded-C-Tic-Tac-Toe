/*! 
 *  \brief     	Steuerklasse der Eingabe und des Spielzustandes
 *  \details   
 *  \author			Yasin Calli 
 *  \author    	Joshua Hahn
 */

#include "./Project_Headers.h"

/*!
	\brief Konstruktor der Controller Klasse.
	\details Erstellt ein neues Field Objekt zum Zeichnen des Spielfeldes und ein neues Cells Objekt um die Werte der einzelnen Felder zu speichern. Weiterhin wird der Spieler der am Zug ist und die Rundenzahl initialisiert.
*/
Controller::Controller()
{
	field = new Field;
	cells = new Cells;
	field -> drawField();
	currentPlayer=1;
	round=0;
};

/*!
	\brief Destruktor der Controller Klasse.
	\details Loescht die Field und Cells Objekte die beim Erstellen erzeugt wurden.
*/
Controller::~Controller()
{
	delete field;
	delete cells;
}

/*!
	\brief Behandelt Spielereingaben
	\details Wertet die Eingabeposition des Spielers aus und setzt enstsprechend die Werte in das Cells Objekt
	\param posX ist die x Koordinate auf dem Bildschirm auf den der/die Spieler/in getippt hat.
	\param posY ist die y Koordinate auf dem Bildschirm auf den der/die Spieler/in getippt hat.
	\param ranDOOM ist ein beliebiger Wert der die KI daran hindert nach jedem Neustart des Systems die gleichen Zuege auszufuehren.
	\return Gibt -1 für eine laufende Partie, 0 für Unentschieden, 1 oder 2 für Spieler 1 oder 2 "hat gewonnen" zurueck.
	\sa getGameState()
*/
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

void Controller::aiMove(uint8_t ranDOOMizer)
{
	while(1)
	{
		if(getGameState()>-1)
		{
			break;
		}
		int value = (rand()+ranDOOMizer)%9;
		if(this->cells -> cells[value].player==0)
		{
			this->handleUserInput(cells -> cells[value].x,cells -> cells[value].y);
			break;
		}
	}
}

//*******************************************************************
// getcurrentPlayer
// \author Joshua Hahn
//*******************************************************************
short Controller::getcurrentPlayer(void)
{
	return currentPlayer;
}

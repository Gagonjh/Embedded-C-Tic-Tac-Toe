#include "./Project_Headers.h"

/*!
	\details Fuehrt den Zug der/des Spieler/s, abhaengig von der getippten Position, und die der KI, abhaengig von einem zusaetzlichen numerischen Wert, aus.
	\param posX ist die x Koordinate auf dem Bildschirm auf den der/die Spieler/in getippt hat.
	\param posY ist die y Koordinate auf dem Bildschirm auf den der/die Spieler/in getippt hat.
	\param ranDOOM ist ein beliebiger Wert der die KI daran hindert nach jedem Neustart des Systems die gleichen Zuege auszufuehren.
	\return Gibt -1 für eine laufende Partie, 0 für Unentschieden, 1 oder 2 für Spieler 1 oder 2 "hat gewonnen" zurueck.
	\sa Controller::getGameState(), Controller::aiMove()
*/
short Game::ttt_classic(short posX,short posY, uint8_t ranDOOM)
{
		Page_Game::instance().output_Current_Player(controller -> getcurrentPlayer() );	//! Ausgabe des aktiven Spielers
	if(posX<390 && posX > 100 && posY < 390 && posY > 100 && (controller -> getcurrentPlayer() != 2 || gameMode != 1)) 
		{
			bool isInputValid = controller -> handleUserInput(posX, posY);
			disp1.refresh();
			return controller -> getGameState();
		}
		//KI Zug
		if(gameMode==1 && controller -> getcurrentPlayer() == 2)
				{
					if(waitAi == 40)
					{
						controller -> aiMove(ranDOOM);
						waitAi = 0;
					}
					else
					{
						waitAi++;
					}
					return controller -> getGameState();
				}

	return -1;
}

//! Kontruktor der Game Klasse
/*!
	Erstellt einen neuen Controller und intialisiert die KI-Zugverzoegerung.
*/
Game::Game()
{
	controller = new Controller;
	waitAi = 0;
}

//! Destruktor der Game Klasse
/*!
	Loescht den Controller der bei der Initialisierung neu erzeugt wurde.
*/
Game::~Game()
{
	delete controller;
}

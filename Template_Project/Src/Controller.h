/*! 
 *  \brief     	
 *  \details   
 *  \author			Yasin Calli 
 *  \author    	Joshua Hahn
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "./datatypes.h"
#include "./Cells.h"
#include "./Field.h"

class Controller {
	private:
		/*!
			\brief Der Spieler der momentan am Zug ist.
		*/
		short currentPlayer;
		/*!
			\brief Die momentane Runde in der Partie.
		*/
		short round;
		/*!
			\brief Die Informationen ueber die Felder auf dem Spielfeld.
		*/
		Cells* cells;
		/*!
			\brief Die visuelle Darstellung des Spielfeldes.
		*/
		Field* field;
	public:
		Controller();
		~ Controller ();
		void aiMove(uint8_t);
		bool handleUserInput(short, short);
		short getGameState();
		short getcurrentPlayer(void);
};

#endif

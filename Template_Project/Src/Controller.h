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
		short currentPlayer;
		short round;
		Cells* cells;
		Field* field;
	public:
		Controller();
		~ Controller ();
		void aiMove();
		bool handleUserInput(short, short);
		short getGameState();
};

#endif

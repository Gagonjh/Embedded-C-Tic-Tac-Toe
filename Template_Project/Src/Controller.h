#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "./datatypes.h"
#include "./Cells.h"
#include "./Field.h"

class Controller {
	private:
		short currentPlayer;
		short round;
		Cells cells;
		Field field;
	public:
		Controller(Cells, Field);
		void aiMove();
		void control(short, short);
		short getGameState();
};

#endif

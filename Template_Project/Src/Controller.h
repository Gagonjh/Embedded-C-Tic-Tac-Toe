#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "./datatypes.h"
#include "./Cells.h"
#include "./Field.h"

extern short currentPlayer;
extern short round;

class Controller {
	private:
		cDevDisplayGraphic& display;
		Cells cells;
		short cellsCount;
		Field field;
	public:
		Controller(cDevDisplayGraphic&, Cells, short, Field);
		void control(short, short);
		short isGameOver();
};

#endif

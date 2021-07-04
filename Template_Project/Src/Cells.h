#ifndef CELLS_H
#define CELLS_H
#include "./datatypes.h"

class Cells {
	private:
		void initializeCells();
		void initializeDefaultRows();
	public:
		short* topRow;
		short* centerRow;
		short* bottomRow;
		short* leftColumn;
		short* centerColumn;
		short* rightColumn;
		short* downDiagonal;
		short* upDiagonal;
		Coordinates* cells;
		bool rowIsComplete(cDevDisplayGraphic& display);
		Cells();
};

#endif

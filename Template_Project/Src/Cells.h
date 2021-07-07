/*! 
 *  \brief     	
 *  \details   
 *  \author			Yasin Calli 
 *  \author    	Joshua Hahn
 */

#ifndef CELLS_H
#define CELLS_H
#include "./datatypes.h"

class Cells {
	private:
		void initializeCells();
		void initializeDefaultRows();
	public:
		BYTE* topRow;
		BYTE* centerRow;
		BYTE* bottomRow;
		BYTE* leftColumn;
		BYTE* centerColumn;
		BYTE* rightColumn;
		BYTE* downDiagonal;
		BYTE* upDiagonal;
		Coordinates* cells;
		bool rowIsComplete();
		Cells();
	
		~ Cells ();
};

#endif

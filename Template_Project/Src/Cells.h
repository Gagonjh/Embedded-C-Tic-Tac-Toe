/*! 
 *  \brief     	Felder auf dem Spielfeld.
 *  \details   	Speichert die Informationen ueber die Spielsteine der Spieler auf den Feldern.
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
		/*!
			\brief Zustand der oberen Reihe.
		*/
		BYTE* topRow;
		/*!
			\brief Zustand der mittleren Reihe.
		*/
		BYTE* centerRow;
		/*!
			\brief Zustand der unteren Reihe.
		*/
		BYTE* bottomRow;
		/*!
			\brief Zustand der linken Spalte.
		*/
		BYTE* leftColumn;
		/*!
			\brief Zustand der mittleren Spalte.
		*/
		BYTE* centerColumn;
		/*!
			\brief Zustand der rechten Spalte.
		*/
		BYTE* rightColumn;
		/*!
			\brief Zustand der fallenden Diagonalen.
		*/
		BYTE* downDiagonal;
		/*!
			\brief Zustand der steigenden Diagonalen.
		*/
		BYTE* upDiagonal;
		/*!
			\brief Koordinaten der Felder.
		*/
		Coordinates* cells;
		bool rowIsComplete();
		Cells();
	
		~ Cells ();
};

#endif

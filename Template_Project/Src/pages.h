//Author:     			Joshua Hahn  
//Projekt:    			Tic Tac Toe
//Letzte Änderung:  15.06.2021

#ifndef PAGES_H
#define PAGES_H

	
	class Field
{
	public:
	cDevDisplayGraphic& disp1;
	
	Field(cDevDisplayGraphic&);
	void drawField();
};
#endif
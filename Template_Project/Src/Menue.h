//Author:     			Joshua Hahn  
//Projekt:    			Tic Tac Toe
//Datum:						16.06.2021

#ifndef MENUE_H
#define MENUE_H

	
class Menue : public Pages
{
		public:
			
			//Konstruktor
			Menue(cDevDisplayGraphic&,int,char*);
		
			void drawpage(void);
};

#endif

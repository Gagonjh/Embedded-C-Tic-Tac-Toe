//Author:     			Joshua Hahn  
//Projekt:    			Tic Tac Toe
//Datum:						21.06.2021

#ifndef SETTINGS_H
#define SETTINGS_H

extern short int iButtons_cor_S[10][4];

class Settings : public Pages
{
		public:
      
			
		
			//Konstruktor
			Settings(cDevDisplayGraphic&,int,char*);
		
			void drawpage(void);
};

#endif

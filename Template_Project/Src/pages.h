//Author:     			Joshua Hahn  
//Projekt:    			Tic Tac Toe
//Letzte Änderung:  15.06.2021

#ifndef PAGES_H
#define PAGES_H

	
class Pages
{
		public:
			cDevDisplayGraphic& disp1;
		
			unsigned int iColor_Mode;
			unsigned int iColor_backround;
			unsigned int iColor_font;
			unsigned int iColor_boxes;
			char* cTitel;
			
			//Konstruktor
			Pages(cDevDisplayGraphic&,int,char*);
			//Methoden
			void changeColorMode(int);
			
			void drawpage(void);
		
			void siteSpecialcontent(void);
			
			void siteHeader(short int,short int,short int,short int);
			
			void draw_button(short int ,short int ,short int ,short int ,short int,short int,short int,short int,short int,short int, char*);
			
};

/*
class Pages
{
	public:
		
};
*/
#endif

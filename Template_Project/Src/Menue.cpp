//Author:     			Joshua Hahn  
//Projekt:    			Tic Tac Toe
//Datum:					  16.06.2021

#include "./project_headers.h"

Menue::Menue(cDevDisplayGraphic& konst_disp,int cmod, char* titel):Pages(konst_disp,cmod,titel)
{
}

void Menue::drawpage()
{
	disp1.clear();
  disp1.setBackColor(iColor_backround);
	siteHeader(0,0,24,16);
	draw_button(80,220,60,280,15,1,iColor_boxes,0x067D,24,16,"Spielen");
	draw_button(460,220,60,280,15,1,iColor_boxes,0x067D,24,16,"Highscore");
	draw_button(260,300,60,280,15,1,iColor_boxes,0x067D,24,16,"Einstellungen");
}

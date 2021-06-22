//Author:     			Joshua Hahn  
//Projekt:    			Tic Tac Toe
//Datum:					  21.06.2021

#include "./project_headers.h"
 short int iButtons_cor_S[10][4] =
	{
				{80,360,220,280}, 	//Button 1 :Menue
				{0,0,0,0}, 	//Button 2 :
				{0,0,0,0}, 	//Button 3 :
				{0,0,0,0}, 					//Button 4 :
				{0,0,0,0}, 					//Button 5 :
				{0,0,0,0}, 					//Button 6 :
				{0,0,0,0}, 					//Button 7 : 
				{0,0,0,0}, 					//Button 8 : 
				{0,0,0,0}, 					//Button 9 :
				{0,0,0,0} 					//Button 10:
			};//[*][0]=x start, [*][1]=x end, [*][2]=y start & [*][3]=y end 

Settings::Settings(cDevDisplayGraphic& konst_disp,int cmod, char* titel):Pages()
{

}

void Settings::drawpage()
{
	disp1.clear();
  disp1.setBackColor(iColor_backround);
	siteHeader(0,0,24,16,"Settings");
	draw_button(iButtons_cor_S[0][0],iButtons_cor_S[0][2],iButtons_cor_S[0][3]-iButtons_cor_S[0][2],iButtons_cor_S[0][1]-iButtons_cor_S[0][0],15,1,iColor_boxes,0x067D,24,16,"Spielen");
}

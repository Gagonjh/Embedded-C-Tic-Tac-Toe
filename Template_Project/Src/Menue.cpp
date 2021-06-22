//Author:     			Joshua Hahn  
//Projekt:    			Tic Tac Toe
//Datum:					  16.06.2021

#include "./project_headers.h"
 short int iButtons_cor_M[10][4] =
	{
				{80,360,220,280}, 	//Button 1 :Spielen
				{460,740,220,280}, 	//Button 2 :Highscore
				{260,540,300,360}, 	//Button 3 :Einstellungen
				{0,0,0,0}, 					//Button 4 :
				{0,0,0,0}, 					//Button 5 :
				{0,0,0,0}, 					//Button 6 :
				{0,0,0,0}, 					//Button 7 : 
				{0,0,0,0}, 					//Button 8 : 
				{0,0,0,0}, 					//Button 9 :
				{0,0,0,0} 					//Button 10:
			};//[*][0]=x start, [*][1]=x end, [*][2]=y start & [*][3]=y end 


void Menue::drawpage()
{
	disp1.clear();
  disp1.setBackColor(iColor_backround);
	siteHeader(0,0,24,16,"Hauptmenue");
	//draw_button(iButtons_cor[0][0],220,60,280,15,1,iColor_boxes,0x067D,24,16,"Spielen");
	draw_button(iButtons_cor_M[0][0],iButtons_cor_M[0][2],iButtons_cor_M[0][3]-iButtons_cor_M[0][2],iButtons_cor_M[0][1]-iButtons_cor_M[0][0],15,1,iColor_boxes,0x067D,24,16,"Spielen");
	draw_button(iButtons_cor_M[1][0],iButtons_cor_M[1][2],iButtons_cor_M[1][3]-iButtons_cor_M[1][2],iButtons_cor_M[1][1]-iButtons_cor_M[1][0],15,1,iColor_boxes,0x067D,24,16,"Highscore");
	draw_button(iButtons_cor_M[2][0],iButtons_cor_M[2][2],iButtons_cor_M[2][3]-iButtons_cor_M[2][2],iButtons_cor_M[2][1]-iButtons_cor_M[2][0],15,1,iColor_boxes,0x067D,24,16,"Einstellungen");
}

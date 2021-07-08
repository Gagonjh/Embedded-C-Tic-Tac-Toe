/*! 
 *  \brief     	
 *  \details   	
 *  \author    	Joshua Hahn
 *  \date      	16.06.2021
 */

#include "./Project_Headers.h"
 short int iButtons_cor_M[10][5] =
	{
				{80,360,220,280,1}, 	//Button 1 :Spielen
				{460,740,220,280,2}, 	//Button 2 :Highscore
				{260,540,300,360,3}, 	//Button 3 :Einstellungen
				{0,0,0,0,0}, 					//Button 4 :
				{0,0,0,0,0}, 					//Button 5 :
				{0,0,0,0,0}, 					//Button 6 :
				{0,0,0,0,0}, 					//Button 7 : 
				{0,0,0,0,0}, 					//Button 8 : 
				{0,0,0,0,0}, 					//Button 9 :
				{0,0,0,0,0} 					//Button 10:
			};//[*][0]=x start, [*][1]=x end, [*][2]=y start & [*][3]=y end 


void Page_Menue::drawpage()
{
  disp1.setBackColor(Style::instance().color_Backround);
	disp1.setTextColor(Style::instance().color_Font);
	siteHeader(0,0,24,16,"Hauptmenue");
	//draw_button(iButtons_cor[0][0],220,60,280,15,1,iColor_boxes,0x067D,24,16,"Spielen");
	draw_button(iButtons_cor_M[0][0],iButtons_cor_M[0][2],iButtons_cor_M[0][3]-iButtons_cor_M[0][2],iButtons_cor_M[0][1]-iButtons_cor_M[0][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Spielen");
	draw_button(iButtons_cor_M[1][0],iButtons_cor_M[1][2],iButtons_cor_M[1][3]-iButtons_cor_M[1][2],iButtons_cor_M[1][1]-iButtons_cor_M[1][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Spiel Historie");
	draw_button(iButtons_cor_M[2][0],iButtons_cor_M[2][2],iButtons_cor_M[2][3]-iButtons_cor_M[2][2],iButtons_cor_M[2][1]-iButtons_cor_M[2][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Einstellungen");
}

short int Page_Menue::buttonOnPagePressed(int posX,int posY)
{
	short int p = -1;
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_M,0);
	}
		if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_M,1);
	}
		if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_M,2);
	}
	return p;
}

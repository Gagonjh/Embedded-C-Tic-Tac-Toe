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
	draw_button(iButtons_cor_M[1][0],iButtons_cor_M[1][2],iButtons_cor_M[1][3]-iButtons_cor_M[1][2],iButtons_cor_M[1][1]-iButtons_cor_M[1][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Highscore");
	draw_button(iButtons_cor_M[2][0],iButtons_cor_M[2][2],iButtons_cor_M[2][3]-iButtons_cor_M[2][2],iButtons_cor_M[2][1]-iButtons_cor_M[2][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Einstellungen");
	

	
	
//Test
	short startx = 80;
	short starty = 80;
	
	//Hammer
	//1.Linie
	disp1.drawLine(startx+17,starty+21,startx+73,starty+21,18,Style::instance().color_Player_1);
	//2. Linie
	disp1.drawLine(startx+45,starty+28,startx+45,starty+80,20,Style::instance().color_Player_1);
	//Kreis
	disp1.drawCircle(startx+73,starty+12,11,Style::instance().color_Backround);
	
	
	startx = 160;
	starty = 80;
	//Sichel
	//Kreis 1
	disp1.drawCircle(startx+45,starty+35,30,Style::instance().color_Player_2);
	//Kreis 2
	disp1.drawCircle(startx+40,starty+30,24,Style::instance().color_Backround);
	//Kreis 3
	disp1.drawCircle(startx+20,starty+45,19,Style::instance().color_Backround);
	//Kreis 4
	disp1.drawCircle(startx+33,starty+54,11,Style::instance().color_Backround);
	//Liniel
	disp1.drawLine(startx+45,starty+58,startx+45,starty+80,14,Style::instance().color_Player_2);
	
	//
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

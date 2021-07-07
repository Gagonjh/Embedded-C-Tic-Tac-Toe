/*! 
 *  \brief     	
 *  \details   	
 *  \author    	Joshua Hahn
 *  \author			Yasin Calli
 *  \date      	21.06.2021
 */

#include "./Project_Headers.h"
 short int iButtons_cor_GS[10][5] =
	{
				{565,795,415,475,0}, 	//Button 1 :Hauptmenü
				{0,0,0,0,0}, 					//Button 2 :
				{0,0,0,0,0}, 					//Button 3 :
				{0,0,0,0,0}, 					//Button 4 :
				{0,0,0,0,0}, 					//Button 5 :
				{0,0,0,0,0}, 					//Button 6 :
				{0,0,0,0,0}, 					//Button 7 : 
				{0,0,0,0,0}, 					//Button 8 : 
				{0,0,0,0,0}, 					//Button 9 :
				{0,0,0,0,0} 					//Button 10:
			};//[*][0]=x start, [*][1]=x end, [*][2]=y start & [*][3]=y end 


void Page_Game::drawpage()
{
  disp1.setBackColor(Style::instance().color_Backround);
	disp1.setTextColor(Style::instance().color_Font);
	draw_button(iButtons_cor_GS[0][0],iButtons_cor_GS[0][2],iButtons_cor_GS[0][3]-iButtons_cor_GS[0][2],iButtons_cor_GS[0][1]-iButtons_cor_GS[0][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Hauptmenu");
}

short int Page_Game::buttonOnPagePressed(int posX,int posY)
{
	short int p = -1;
	if(p == -1)
	{
			p = Page_Game::instance().isPressed(posX,posY,iButtons_cor_GS,0);
	}
	return p;
}

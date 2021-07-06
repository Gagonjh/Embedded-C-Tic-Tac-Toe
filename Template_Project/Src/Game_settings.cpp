/*! 
 *  \brief     Dient der Ausgabe auf dem Display
 *  \details   Die Klasse dient als Parent für die einzelnen Ansichten. Sie stellt darüber hinaus funktionalitäten für die Child Klassen bereit und regelt den Aufruf dieser. Sie ist somit das Bindeglied zwischen der Ausgabe und dem funktionalen teil des Programmes.
 *  \author    Joshua Hahn, Yasin Calli
 *  \date      21.06.2021
 */

#include "./project_headers.h"
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


void Game_Settings::drawpage()
{
  disp1.setBackColor(Style::instance().color_Backround);
	disp1.setTextColor(Style::instance().color_Font);
	draw_button(iButtons_cor_GS[0][0],iButtons_cor_GS[0][2],iButtons_cor_GS[0][3]-iButtons_cor_GS[0][2],iButtons_cor_GS[0][1]-iButtons_cor_GS[0][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Hauptmenu");
}

short int Game_Settings::buttonOnPagePressed(int posX,int posY)
{
	short int p = -1;
	if(p == -1)
	{
			p = Game_Settings::instance().isPressed(posX,posY,iButtons_cor_GS,0);
	}
	return p;
}

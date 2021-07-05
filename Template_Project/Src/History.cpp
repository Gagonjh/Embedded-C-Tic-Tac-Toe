/*! 
 *  \brief     Dient der Ausgabe auf dem Display
 *  \details   Die Klasse dient als Parent f�r die einzelnen Ansichten. Sie stellt dar�ber hinaus funktionalit�ten f�r die Child Klassen bereit und regelt den Aufruf dieser. Sie ist somit das Bindeglied zwischen der Ausgabe und dem funktionalen teil des Programmes.
 *  \author    Joshua Hahn
 *  \date      21.06.2021
 */

#include "./project_headers.h"
 short int iButtons_cor_H[10][5] =
	{
				{685,795,415,475,0}, 	//Button 1 :Hauptmen�
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


void History::drawpage()
{
	disp1.clear();
  disp1.setBackColor(Style::instance().color_Backround);
	siteHeader(0,0,24,16,"Letzte Spiele");
	draw_button(iButtons_cor_S[0][0],iButtons_cor_S[0][2],iButtons_cor_S[0][3]-iButtons_cor_S[0][2],iButtons_cor_S[0][1]-iButtons_cor_S[0][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"H");
}

short int History::buttonOnPagePressed(int posX,int posY)
{
	short int p = -1;
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,0);
	}
	return p;
}

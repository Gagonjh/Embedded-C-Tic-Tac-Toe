/*! 
 *  \brief     Dient der Ausgabe auf dem Display
 *  \details   Die Klasse dient als Parent für die einzelnen Ansichten. Sie stellt darüber hinaus funktionalitäten für die Child Klassen bereit und regelt den Aufruf dieser. Sie ist somit das Bindeglied zwischen der Ausgabe und dem funktionalen teil des Programmes.
 *  \author    Joshua Hahn
 *  \date      21.06.2021
 */

#include "./project_headers.h"
 short int iButtons_cor_S[10][5] =
	{
				{685,795,415,475,0}, 	//! Button 1 :Hauptmenü
				{300,350,120,170,-2}, //! Button 2 :Color Theme 1 weiß
				{410,460,120,170,-2}, //! Button 3 :Color Theme 0 schwarz
				{520,560,120,170,-2}, //! Button 4 :Color Theme 2 RU
				{0,0,0,0,0}, 					//! Button 5 :
				{0,0,0,0,0}, 					//! Button 6 :
				{0,0,0,0,0}, 					//! Button 7 : 
				{0,0,0,0,0}, 					//! Button 8 : 
				{0,0,0,0,0}, 					//! Button 9 :
				{0,0,0,0,0} 					//! Button 10:
			};//[*][0]=x start, [*][1]=x end, [*][2]=y start & [*][3]=y end | -2 = Ein button auf der seite mit funktion


void Settings::drawpage()
{
  disp1.setBackColor(Style::instance().color_Backround);
	disp1.setTextColor(Style::instance().color_Font);
	siteHeader(0,0,24,16,"Settings");
	draw_button(iButtons_cor_S[0][0],iButtons_cor_S[0][2],iButtons_cor_S[0][3]-iButtons_cor_S[0][2],iButtons_cor_S[0][1]-iButtons_cor_S[0][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"H");

//Draw Color Change Buttons
	disp1.drawText(40,120,"Farbschema:");
	disp1.drawCircle(300,120,50,Style::instance().color_Field);
	disp1.drawCircle(300,120,40,0xFFFF);
	disp1.drawCircle(410,120,50,Style::instance().color_Field);
	disp1.drawCircle(410,120,40,0x7BCF);
	disp1.drawCircle(520,120,50,Style::instance().color_Field);
	disp1.drawCircle(520,120,40,0x98A2);
}

short int Settings::buttonOnPagePressed(int posX,int posY)
{
	short int p = -1;
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,0);
	}
	
	//Button 1
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,1);
			if(p == -2)
			{
				Style::instance().changeActiveColorTheme(1);
				disp1.drawCircle(300,120,50,0x17E0);
			}
	}
	
	//Button 2
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,2);
			if(p == -2)
			{
				Style::instance().changeActiveColorTheme(0);
				disp1.drawCircle(410,120,50,0x17E0);
			}
	}
	
	//Button 3
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,3);
			if(p == -2)
			{
				Style::instance().changeActiveColorTheme(2);
				disp1.drawCircle(520,120,50,0x17E0);
			}
	}
	
	//Return to default value
	if(p==-2)
	{
		p = -1;
	}
	return p;
}

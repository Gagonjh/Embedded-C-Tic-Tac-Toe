/*! 
 *  \author    	Joshua Hahn
 *  \date      	16.06.2021
 */

#include "./Project_Headers.h"

 short int iButtons_cor_M[3][5] =
	{
				{80,360,220,280,1}, 	//Button 1 :Spielen
				{460,740,220,280,2}, 	//Button 2 :Highscore
				{260,540,300,360,3}, 	//Button 3 :Einstellungen
	};//[*][0]=x start, [*][1]=x end, [*][2]=y start, [*][3]=y end, [*][4]= Page oder -2

/*!
	\brief Gibt den Inhalt der Seite aus
	\details Setzt die Notwendigen Farbwerte in der EmbSysLib. Und Zeichnet die Button mit der Vererbten funktion aus Pages. Überschreibt Pages::drawpage()
	\sa Pages::draw_button()
	\sa Pages::drawpage()
*/
void Page_Menue::drawpage()
{
  disp1.setBackColor(Style::instance().color_Backround);
	disp1.setTextColor(Style::instance().color_Font);
	siteHeader(0,0,24,16,"Hauptmenue");
	draw_button(iButtons_cor_M[0][0],iButtons_cor_M[0][2],iButtons_cor_M[0][3]-iButtons_cor_M[0][2],iButtons_cor_M[0][1]-iButtons_cor_M[0][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Spielen");
	draw_button(iButtons_cor_M[1][0],iButtons_cor_M[1][2],iButtons_cor_M[1][3]-iButtons_cor_M[1][2],iButtons_cor_M[1][1]-iButtons_cor_M[1][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Spiel Historie");
	draw_button(iButtons_cor_M[2][0],iButtons_cor_M[2][2],iButtons_cor_M[2][3]-iButtons_cor_M[2][2],iButtons_cor_M[2][1]-iButtons_cor_M[2][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Einstellungen");
}

/*!
	\brief Prüft ob ein Button gedrückt ist.
	\details Nutzt die Vererbte funktion aus der Pages isPressed um sagen zu können ob ein Button gedrückt ist. Falls ja wird die gewünschte Funktionaität aufgerufen.
	\param X Koordinate der Touch Eingabe.
	\param Y Koordinate der Touch Eingabe.
	\return Gibt die Seite zurück auf die gewechselt werden soll. 
	\sa Pages::isPressed()
*/
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

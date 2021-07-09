/*! 
 *  \author    Joshua Hahn
 *  \date      21.06.2021
 *  \file 
 */

#include "./Project_Headers.h"

 short int iButtons_cor_H[1][5] =
	{
				{565,795,415,475,0}, 	//Button 1 :Hauptmenü	
	};//[*][0]=x start, [*][1]=x end, [*][2]=y start, [*][3]=y end, [*][4]= Page oder -2

/*!
	\brief Private Konstruktor der Klasse.
	\details Initalisiert den das Gewinner Array und den Offset.
*/
Page_History::Page_History()
{
	winner = new short[18];
	short temp[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(short i = 0; i<18; i++)
	{
				winner[i] = temp[i];
	}
	hOffset=0;
}

/*!
	\brief Destruktor für die Klasse.
	\details Löscht die Gewinner wird normalerweise nicht aufgerufen da die Klasse ein Singelton ist. Der Formhalber enthalten weil winner mit New deklariert ist.
*/
Page_History::~Page_History() 
{
	delete winner;
}

/*!
	\brief Speichert Gewinner
	\details Der übergebene Gewinner wird im Array+Offset gespeichert das Offset wird erhöht.
	\param Letzter Gewinner des Spiels (0 = Unendschieden/Nicht Erfasst,1 = Spieler 1,2 = Spieler 2)
*/
void Page_History::newWinner(short winnerLastRound)
{
	winner[hOffset] = winnerLastRound;
	hOffset = (hOffset+1)%18;
}

/*!
	\brief Gibt den Inhalt der Seite aus
	\details Setzt die Notwendigen Farbwerte in der EmbSysLib. Und Zeichnet die Button mit der Vererbten funktion aus Pages. Überschreibt Pages::drawpage()
	\sa Pages::draw_button()
	\sa Pages::drawpage()
*/
void Page_History::drawpage()
{
	disp1.clear();
  disp1.setBackColor(Style::instance().color_Backround);
	siteHeader(0,0,24,16,"Letzte Spiele");
	draw_button(iButtons_cor_S[0][0],iButtons_cor_S[0][2],iButtons_cor_S[0][3]-iButtons_cor_S[0][2],iButtons_cor_S[0][1]-iButtons_cor_S[0][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Hauptmenu");
	int gameNum = 18;
	for(int i=0; i <= 8;i++)
	{
		disp1.drawText(70,70+40*i,10," Gewinner %d: %d",gameNum,winner[(i+hOffset)%18]);
		gameNum--;
	}
	
	disp1.drawLine(400,50,400,480,10,Style::instance().color_Boxes);
	
	for(short i=9; i <= 17;i++)
	{
		disp1.drawText(470,70+40*(i-9),10," Gewinner %d: %d",gameNum,winner[(i+hOffset)%18]);
		gameNum--;
	}
}

/*!
	\brief Prüft ob ein Button gedrückt ist.
	\details Nutzt die Vererbte funktion aus der Pages isPressed um sagen zu können ob ein Button gedrückt ist. Falls ja wird die gewünschte Funktionaität aufgerufen.
	\param X Koordinate der Touch Eingabe.
	\param Y Koordinate der Touch Eingabe.
	\return Gibt die Seite zurück auf die gewechselt werden soll. 
	\sa Pages::isPressed()
*/
short int Page_History::buttonOnPagePressed(int posX,int posY)
{
	short int p = -1;
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,0);
	}
	return p;
}

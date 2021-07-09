/*! 
 *  \brief     	
 *  \details   	
 *  \author    	Joshua Hahn
 *  \author			Yasin Calli
 *  \date      	21.06.2021
 */

#include "./Project_Headers.h"

short int iButtons_cor_G[2][5] =
{
				{565,795,415,475,0}, 	//Button 1 :Hauptmenü
				{520,720,220,280,-2}, //Button 2 :Game Restart
};//[*][0]=x start, [*][1]=x end, [*][2]=y start, [*][3]=y end, [*][4]= Page oder -2

/*!
	\brief Private Konstruktor der Klasse.
	\details Initalisiert den Restart State.
*/
Page_Game::Page_Game() 
{
			restart_state = 0;
}	

/*!
	\brief Gibt den Inhalt der Seite aus
	\details Setzt die Notwendigen Farbwerte in der EmbSysLib. Und Zeichnet die Button mit der Vererbten funktion aus Pages.
	\sa Pages::draw_button()
*/
void Page_Game::drawpage()
{
  disp1.setBackColor(Style::instance().color_Backround);
	disp1.setTextColor(Style::instance().color_Font);
	draw_button(iButtons_cor_G[0][0],iButtons_cor_G[0][2],iButtons_cor_G[0][3]-iButtons_cor_G[0][2],iButtons_cor_G[0][1]-iButtons_cor_G[0][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Hauptmenu");
}

/*!
	\brief Prüft ob ein Button gedrückt ist.
	\details Nutzt die Vererbte funktion aus der Pages isPressed um sagen zu können ob ein Button gedrückt ist. Falls ja wird die gewünschte funktionaität aufgerufen.
	\param X Koordinate der Touch Eingabe.
	\param Y Koordinate der Touch Eingabe.
	\return Gibt die Seite zurück auf die gewechselt werden soll. 
	\sa Pages::isPressed()
*/
short int Page_Game::buttonOnPagePressed(int posX,int posY)
{
	short int p = -1;
	if(p == -1)
	{
			p = Page_Game::instance().isPressed(posX,posY,iButtons_cor_G,0);
	}
	if(p == -1 && restart_state == 1)
	{
			p = Page_Game::instance().isPressed(posX,posY,iButtons_cor_G,1);
			if(p == -2)
			{
			Page_Game::instance().restart_state = 2;
			}
	}
	//! Falls man nicht auf eine Seite Springen soll wird eine -2 erwartet diese wird auf -1 zurückgesetzt damit die anderen button nicht mehr ausgewertet werden.
	if(p==-2)
	{
		p = -1;
		disp1.clear();
		Page_Game::instance().drawpage();
	}
	return p;
}

/*!
	\brief Gibt den Spieler aus.
	\details Gibt während des Spiels immer den Aktiven Spieler aus damit der Spieler weiß wer am zug ist.
	\param Spieler der Ausgegeben werden soll
*/
void Page_Game::output_Current_Player(short player)
{
				disp1.drawText(470,50,18,"Es spielt Player: %d",player);
}

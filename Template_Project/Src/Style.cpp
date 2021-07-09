/*! 
 *  \brief     	Definiert das Farbthema der Anwendung
 *  \details   	Die Klasse stellt unterschiedliche Farbthemen für den Nutzer zur Wahl zur verfügung. Die Klasse ist ein Singleton somit gibt es nur eine Instanz auf die man mit Style::instance(). zugreifen kann.
 *  \author    	Joshua Hahn
 *  \date      	21.06.2021
 */
 
#include "./Project_Headers.h"

/*!
	\brief Private Konstruktor der Klasse.
	\details Initalisiert die Unterschiedlichen Farbmodi für die zu verfügung stehen
*/
Style::Style() 
{
//! Dunkles Farbthema Case 0
			dark_Color_Backround = 0x530C;
			dark_Color_Font = 0xFFFF;
			dark_Color_Boxes = 0x94F4;
			dark_Color_Player_1 = 0x1F62;
			dark_Color_Player_2 = 0x137D;
			dark_Color_Field = 0xE982;
			
//! Helles Farbthema Case 1
			light_Color_Backround = 0xFFFF;
			light_Color_Font = 0x0000;
			light_Color_Boxes = 0xB591;
			light_Color_Player_1 = 0xE640;
			light_Color_Player_2 = 0x9619;
			light_Color_Field = 0x881C;
		
//! Mütterchen Russland Case 2
			ru_Color_Backround = 0x98A2;
			ru_Color_Font = 0xF666;
			ru_Color_Boxes = 0x94B2;
			ru_Color_Player_1 = 0xF666;
			ru_Color_Player_2 = 0xF666;
			ru_Color_Field = 0x528A;
	
//! Definition des Defaults als Dunkles Farbthema
			color_Backround = dark_Color_Backround;
			color_Font = dark_Color_Font;
			color_Boxes = dark_Color_Boxes;
			color_Player_1 = dark_Color_Player_1;
			color_Player_2 = dark_Color_Player_2;
			color_Field = dark_Color_Field;
			
			Symbole::instance().setPlayerSim(0,1);
			color_Mode = 0;
}			

/*!
	\brief Setzt Aktive Farbe
	\details Wertet den übergegbenen gewünschen Farbmodus aus und überschreibt die public werte für den zugriff auserhalb der Klasse Style.
	\param cmode stellt den neuen Fabrmodus da.
	\param posY ist die y Koordinate auf dem Bildschirm auf den der/die Spieler/in getippt hat.
*/
void Style::changeActiveColorTheme(short int cmode)
{
	color_Mode = cmode;
	switch(cmode) 
			{
				case 0:
					color_Backround = dark_Color_Backround;
					color_Font = dark_Color_Font;
					color_Boxes = dark_Color_Boxes;
					color_Player_1 = dark_Color_Player_1;
					color_Player_2 = dark_Color_Player_2;
					color_Field = dark_Color_Field;
					Symbole::instance().setPlayerSim(0,1);
				break;
				case 1:
					color_Backround = light_Color_Backround;
					color_Font = light_Color_Font;
					color_Boxes = light_Color_Boxes;
					color_Player_1 = light_Color_Player_1;
					color_Player_2 = light_Color_Player_2;
					color_Field = light_Color_Field;
					Symbole::instance().setPlayerSim(0,1);
				break;
				case 2:
					color_Backround = ru_Color_Backround;
					color_Font = ru_Color_Font;
					color_Boxes = ru_Color_Boxes;
					color_Player_1 = ru_Color_Player_1;
					color_Player_2 = ru_Color_Player_2;
					color_Field = ru_Color_Field;
					Symbole::instance().setPlayerSim(2,3);
				break;
				default:
				break;
			}
	disp1.setBackColor(color_Backround);
	disp1.setTextColor(color_Font);
}

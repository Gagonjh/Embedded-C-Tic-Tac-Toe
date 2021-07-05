/*! 
 *  \brief     Dient der Ausgabe auf dem Display
 *  \details   Die Klasse dient als Parent für die einzelnen Ansichten. Sie stellt darüber hinaus funktionalitäten für die Child Klassen bereit und regelt den Aufruf dieser. Sie ist somit das Bindeglied zwischen der Ausgabe und dem funktionalen teil des Programmes.
 *  \author    Joshua Hahn
 *  \date      21.06.2021
 */

#ifndef STYLE_H
#define STYLE_H

class Style
{
		public:
			//Konstruktor und übergabe der Instanz
				static Style& instance()
			{
				static Style _instance;
				return _instance;
			}
			~Style() {}
			
		//Public Methoden
			void changeActiveColorTheme(short int);
		//Public Variablen
			int color_Backround;
			int color_Font;
			int color_Boxes;
			int color_Player_1;
			int color_Player_2;
			int color_Field;
		
		private:
			//dark 0
			int dark_Color_Backround;
			int dark_Color_Font;
			int dark_Color_Boxes ;
			int dark_Color_Player_1;
			int dark_Color_Player_2 ;
			int dark_Color_Field;
			int dark_Color_Border;
		//Light 1
			int light_Color_Backround;
			int light_Color_Font;
			int light_Color_Boxes;
			int light_Color_Player_1;
			int light_Color_Player_2;
			int light_Color_Field;
		//Mother Russia 2
			int ru_Color_Backround;
			int ru_Color_Font;
			int ru_Color_Boxes;
			int ru_Color_Player_1;
			int ru_Color_Player_2;
			int ru_Color_Field;
		
			Style();// verhindert, dass ein Objekt von außerhalb von N erzeugt wird.
                    // protected, wenn man von der Klasse noch erben möchte
			Style( const Style& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
				
			Style & operator = (const Style &); //Verhindert weitere Instanz durch Kopie
			
			//Private Variablen
			
};

#endif

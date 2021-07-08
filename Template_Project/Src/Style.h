/*! 
 *  \brief     	
 *  \details   	
 *  \author    	Joshua Hahn
 *  \date      	21.06.2021
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
			short color_Backround;
			short color_Font;
			short color_Boxes;
			short color_Player_1;
			short color_Player_2;
			short color_Field;
			short color_Mode;
		
		private:
			//dark 0
			short dark_Color_Backround;
			short dark_Color_Font;
			short dark_Color_Boxes ;
			short dark_Color_Player_1;
			short dark_Color_Player_2 ;
			short dark_Color_Field;
			short dark_Color_Border;
		//Light 1
			short light_Color_Backround;
			short light_Color_Font;
			short light_Color_Boxes;
			short light_Color_Player_1;
			short light_Color_Player_2;
			short light_Color_Field;
		//Mother Russia 2
			short ru_Color_Backround;
			short ru_Color_Font;
			short ru_Color_Boxes;
			short ru_Color_Player_1;
			short ru_Color_Player_2;
			short ru_Color_Field;
		
			Style();// verhindert, dass ein Objekt von außerhalb von N erzeugt wird.
                    // protected, wenn man von der Klasse noch erben möchte
			Style( const Style& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
				
			Style & operator = (const Style &); //Verhindert weitere Instanz durch Kopie
			
			//Private Variablen
			
};

#endif

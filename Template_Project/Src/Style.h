/*! 
*  \brief     	Definiert das Farbthema der Anwendung (Singelton)
*  \details   	Die Klasse stellt unterschiedliche Farbthemen für den Nutzer zur Wahl zur verfügung. Die Klasse ist ein Singleton somit gibt es nur eine Instanz auf die man mit Style::instance(). zugreifen kann.
*  \author    	Joshua Hahn
*  \date      	21.06.2021
*/

#ifndef STYLE_H
#define STYLE_H

class Style
{
//Konstruktor und Destruktor
	public:
			//! Zugriff auf die Instanz der Klasse von Außerhalb
				static Style& instance()
			{
				static Style _instance;
				return _instance;
			}
			//! Destruktor Definition und Deklaration
			~Style() {}
				
	private:
			Style();
			//! Verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
			Style( const Style& );
			//! Verhindert weitere Instanz durch Kopie	
			Style & operator = (const Style &);

//Variabeln
	public:
			short color_Backround;
			short color_Font;
			short color_Boxes;
			short color_Player_1;
			short color_Player_2;
			short color_Field;
			short color_Mode;
	
		private:
			//! Dunkle Hintergrundfarbe (Anthrazit)
			short dark_Color_Backround;			
			//!	Dunkle Text Farbe (Weiß)
			short dark_Color_Font;					
			//!	Dunkle Umrandungsfarbe (Hellgrau)
			short dark_Color_Boxes ;				
			//!	Dunkle Spieler 1 Farbe (Grün)
			short dark_Color_Player_1;			
			//!	Dunkle Spieler 2 Farbe (Blau)
			short dark_Color_Player_2 ;			
			//!	Dunkle Feld Farbe (Orange)
			short dark_Color_Field;					
		
			//! Helle Hintergrundfarbe (Weiß)
			short light_Color_Backround;		
			//!	Helle Text Farbe (Schwarz)
			short light_Color_Font;					
			//!	Helle Umrandungsfarbe (Lila)
			short light_Color_Boxes;				
			//!	Helle Spieler 1 Farbe (Gelb)
			short light_Color_Player_1;			
			//!	Helle Spieler 2 Farbe (Hellblau)
			short light_Color_Player_2;			
			//!	Helle Feld Farbe (Lila)
			short light_Color_Field;				

			//! Mütterchen Russlands Hintergrundfarbe (Bordeaux Rot)
			short ru_Color_Backround;				
			//!	Mütterchen Russlands Text Farbe (Gold Gelb)
			short ru_Color_Font;						
			//!	Mütterchen Russlands Umrandungsfarbe (Anthrazit)
			short ru_Color_Boxes;						
			//!	Mütterchen Russlands Spieler 1 Farbe (Gold Gelb)
			short ru_Color_Player_1;				
			//!	Mütterchen Russlands Spieler 2 Farbe (Gold Gelb)
			short ru_Color_Player_2;				
			//!	Mütterchen Russlands Feld Farbe (Hellgrau)
			short ru_Color_Field;
		
//Methoden			
		public:

			void changeActiveColorTheme(short int);
			
};

#endif

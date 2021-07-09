/*!
 *  \class     Page_Game
 *  \brief     Spielseite (Singelton)
 *  \details   Gibt die Spielseite aus und hat die Funktionalität um eine Revanche zu erstellen.
 *  \author    Joshua Hahn
 *  \date      21.06.2021
 */

#ifndef PAGE_Game_H
#define PAGE_Game_H

//!Koordinaten und Weiterleitungsanweisung für die Seite.
extern short int iButtons_cor_G[2][5];

class Page_Game : public Pages
{
//Konstruktor und Destruktor
		public:
			//! Zugriff auf die Instanz der Klasse von Außerhalb.
				static Page_Game& instance()
			{
				static Page_Game _instance;
				return _instance;
			}
			//! Destruktor Definition und Deklaration.
			~Page_Game() {}
				
		private:	
			Page_Game();
			//! Verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann.
			Page_Game( const Page_Game& );
			//! Verhindert weitere Instanz durch Kopie.
			Page_Game & operator = (const Page_Game &);
				
//Variabeln
		public:
			//! Dient als Schnitstelle zwischen dem Button Revance! und einer externen funktion die diese Variable abruft.
			short restart_state;

//Methoden	
		public:
		void output_Current_Player(short);
		void drawpage(void);
		short int buttonOnPagePressed(int,int);		
};

#endif

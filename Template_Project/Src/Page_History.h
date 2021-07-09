/*! 
 *  \brief     Die Letzten Spiele (Singelton)
 *  \details   Gibt die Seite mit den Letzten Spielen aus und stellt die notwendige Funktionalität zur verfügung um diese zu verwalten.
 *  \author    Joshua Hahn
 *  \date      05.07.2021
 */

#ifndef PAGE_HISTORY_H
#define PAGE_HISTORY_H

//!Koordinaten und Weiterleitungsanweisung für die Seite.
extern short int iButtons_cor_H[1][5];

class Page_History : public Pages
{
//Konstruktor und Destruktor
		public:
			//! Zugriff auf die Instanz der Klasse von Außerhalb.
			static Page_History& instance()
			{
				static Page_History _instance;
				return _instance;
			}
			//! Destruktor Definition
			~Page_History();
		private:
			Page_History();
			//! Verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann.
			Page_History( const Page_History& );
			//! Verhindert weitere Instanz durch Kopie.
			Page_History & operator = (const Page_History &);
		
//Variabeln
		private:
			//! Offset zum auslesen des Arrays mit dem Gewinnern
			short hOffset;
			//! Array mit den Daten welcher Spieler wann gewonnen hat
			short* winner;
		
//Methoden
		public:
			void drawpage(void);
			void newWinner(short);
			short int buttonOnPagePressed(int,int);	
};

#endif

/*! 
 *  \brief     Einstellungen des Programms. (Singelton)
 *  \details   Bietet dem Nutzer die Möglichkeit zwischen mehreren Farbthemas und Spielmodi zu wählen.
 *  \author    Joshua Hahn
 *  \date      21.06.2021
 */

#ifndef PAGE_SETTINGS_H
#define PAGE_SETTINGS_H

//!Koordinaten und Weiterleitungsanweisung für die Seite.
extern short int iButtons_cor_S[6][5];

class Page_Settings : public Pages
{
//Konstruktor und Destruktor
		public:
			//Konstruktor und übergabe der Instanz
				static Page_Settings& instance()
			{
				static Page_Settings _instance;
				return _instance;
			}
			~Page_Settings() {}
		private:
			//! Standard Konstruktor
			Page_Settings() {} ;
			//! Verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann.	
			Page_Settings( const Page_Settings& );
			//! Verhindert weitere Instanz durch Kopie.
			Page_Settings & operator = (const Page_Settings &);

//Methoden
		public:
			void drawpage(void);
			short int buttonOnPagePressed(int,int);
				
		private:
			void highlight_selected_colormode_button();
			void highlight_selected_game_mode();
};

#endif

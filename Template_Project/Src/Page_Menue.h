/*! 
 *  \brief     	Das Hauptmenü. (Singelton)
 *  \details   	Gibt das Hauptmenü mit den Notwendigen Buttons aus und prüft ob diese gedrückt wurden.
 *  \author    	Joshua Hahn
 *  \date      	16.06.2021
 */

#ifndef PAGE_MENUE_H
#define PAGE_MENUE_H

//!Koordinaten und Weiterleitungsanweisung für die Seite.
extern short int iButtons_cor_M[3][5];

class Page_Menue : public Pages
{
//Konstruktor und Destruktor
		public:
			//! Zugriff auf die Instanz der Klasse von Außerhalb.
			static Page_Menue& instance()
			{
				static Page_Menue _instance;
				return _instance;
			}
			//! Destruktor Definition und Deklaration.
			~Page_Menue() {}

		private:
			//! Standard Konstruktor
			Page_Menue() {} ;
      //! Verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann.
			Page_Menue( const Page_Menue& );
			//! Verhindert weitere Instanz durch Kopie.	
			Page_Menue & operator = (const Page_Menue &);

//Methoden				
		public:
			void drawpage(void);
			short int buttonOnPagePressed(int,int);			
};
#endif

/*!
 *  \brief     	Dient der Ausgabe auf dem Display (Singelton)
 *  \details   	Die Klasse dient als Parent für die einzelnen Ansichten. Sie stellt darüber hinaus funktionalitäten für die Child Klassen bereit und regelt den Aufruf dieser. Sie ist somit das Bindeglied zwischen der Ausgabe und dem funktionalen teil des Programmes.
 *	\author    	Joshua Hahn
 *  \author			Yasin Calli 
 *  \date      	15.06.2021
*/

#ifndef PAGES_H
#define PAGES_H
	
class Pages
{
//Konstruktor und Destruktor
	public:
		//! Zugriff auf die Instanz der Klasse von Außerhalb.
		static Pages& instance()
		{
				static Pages _instance;
				return _instance;
		}
		//! Destruktor Definition und Deklaration.
		~Pages() {}
	protected:
			Pages();
			//! Verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann.
			Pages( const Pages& );
			//! Verhindert weitere Instanz durch Kopie.
			Pages & operator = (const Pages &);
	
//Variabeln
	public:
			unsigned int iCurrent_Page;
	private:
			//!Aktuelle Seite
			short int page;
			//! Aktuelle Seite bei letzten Aufruf
			short int lastPage;
				
//Methoden
	public:
			void drawpage(void);
			void siteHeader(short int,short int,short int,short int,char*);
			void draw_button(short int ,short int ,short int ,short int ,short int,short int,short int,short int,short int,short int, char*);
			short int display_current_page(int, int);
			short int isPressed(int,int,short int[][5],int);
};
#endif

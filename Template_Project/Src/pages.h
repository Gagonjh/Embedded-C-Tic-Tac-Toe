//Author:     			Joshua Hahn  
//Projekt:    			Tic Tac Toe
//Datum:					  15.06.2021

#ifndef PAGES_H
#define PAGES_H
	
class Pages
{
	
	private:
		short int page; //Aktuelle Seite
		short int lastPage; //Seite des letzten Aufrufs
	public:

		
			unsigned int iCurrent_Page;
	
			//Konstruktor
				static Pages& instance()
			{
				static Pages _instance;
				return _instance;
			}
			~Pages() {}
			//Methoden
			
			void drawpage(void);
			
			void siteHeader(short int,short int,short int,short int,char*);
			
			void draw_button(short int ,short int ,short int ,short int ,short int,short int,short int,short int,short int,short int, char*);
				
			short int display_current_page(int, int);
			
			short int isPressed(int,int,short int[][5],int);
				
		protected:
			Pages();// verhindert, dass ein Objekt von außerhalb von N erzeugt wird.
                    // protected, wenn man von der Klasse noch erben möchte
			Pages( const Pages& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
				
			Pages & operator = (const Pages &); //Verhindert weitere Instanz durch Kopie
		  

		
};

/*
class Pages
{
	public:
		
};
*/
#endif

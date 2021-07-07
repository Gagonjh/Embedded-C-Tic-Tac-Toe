/*! 
 *  \brief     
 *  \details   
 *  \author    Joshua Hahn
 *  \date      05.07.2021
 */

#ifndef PAGE_HISTORY_H
#define PAGE_HISTORY_H

extern short int iButtons_cor_H[10][5];

class Page_History : public Pages
{
		public:
			//Konstruktor und übergabe der Instanz
				static Page_History& instance()
			{
				static Page_History _instance;
				return _instance;
			}
			~Page_History() {}
			
		//Public Methoden
			void drawpage(void);
				
			short int buttonOnPagePressed(int,int);
		
		private:
			
			Page_History() {
			} ;// verhindert, dass ein Objekt von außerhalb von N erzeugt wird.
                    // protected, wenn man von der Klasse noch erben möchte
			Page_History( const Page_History& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
				
			Page_History & operator = (const Page_History &); //Verhindert weitere Instanz durch Kopie
};

#endif

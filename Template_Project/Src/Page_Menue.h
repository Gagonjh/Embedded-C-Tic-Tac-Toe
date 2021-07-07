/*! 
 *  \brief     
 *  \details   
 *  \author    Joshua Hahn
 *  \date      16.06.2021
 */

#ifndef PAGE_MENUE_H
#define PAGE_MENUE_H

extern short int iButtons_cor_M[10][5];

class Page_Menue : public Pages
{
		public:
						//Konstruktor
				static Page_Menue& instance()
			{
				static Page_Menue _instance;
				return _instance;
			}
			~Page_Menue() {}
		
			void drawpage(void);
			
			short int buttonOnPagePressed(int,int);
			
			private:
			
			Page_Menue() {
			} ;// verhindert, dass ein Objekt von außerhalb von N erzeugt wird.
                    // protected, wenn man von der Klasse noch erben möchte
			Page_Menue( const Page_Menue& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
				
			Page_Menue & operator = (const Page_Menue &); //Verhindert weitere Instanz durch Kopie
};

#endif

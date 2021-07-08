/*! 
 *  \brief     
 *  \details   
 *  \author    Joshua Hahn
 *  \date      05.07.2021
 */

#ifndef PAGE_Game_H
#define PAGE_Game_H

extern short int iButtons_cor_GS[10][5];

class Page_Game : public Pages
{
		public:
			//Konstruktor und übergabe der Instanz
				static Page_Game& instance()
			{
				static Page_Game _instance;
				return _instance;
			}
			~Page_Game() {}
				
		void output_Current_Player(short);
			
		
		short restart_state;
		//Public Methoden
			void drawpage(void);
				
			short int buttonOnPagePressed(int,int);
		
		private:	
		
			Page_Game();// verhindert, dass ein Objekt von außerhalb von N erzeugt wird.
                    // protected, wenn man von der Klasse noch erben möchte
			Page_Game( const Page_Game& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
				
			Page_Game & operator = (const Page_Game &); //Verhindert weitere Instanz durch Kopie
			
};

#endif

/*! 
 *  \brief     
 *  \details   
 *  \author    Joshua Hahn
 *  \date      05.07.2021
 */

#ifndef HISTORY_H
#define HISTORY_H

extern short int iButtons_cor_H[10][5];

class History : public Pages
{
		public:
			//Konstruktor und übergabe der Instanz
				static History& instance()
			{
				static History _instance;
				return _instance;
			}
			~History() {}
			
		//Public Methoden
			void drawpage(void);
				
			short int buttonOnPagePressed(int,int);
		
		private:
			
			History() {
			} ;// verhindert, dass ein Objekt von außerhalb von N erzeugt wird.
                    // protected, wenn man von der Klasse noch erben möchte
			History( const History& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
				
			History & operator = (const History &); //Verhindert weitere Instanz durch Kopie
};

#endif

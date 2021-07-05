/*! 
 *  \brief     Dient der Ausgabe auf dem Display
 *  \details   Die Klasse dient als Parent für die einzelnen Ansichten. Sie stellt darüber hinaus funktionalitäten für die Child Klassen bereit und regelt den Aufruf dieser. Sie ist somit das Bindeglied zwischen der Ausgabe und dem funktionalen teil des Programmes.
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

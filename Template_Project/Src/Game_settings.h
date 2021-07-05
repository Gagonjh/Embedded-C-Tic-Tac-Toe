/*! 
 *  \brief     Dient der Ausgabe auf dem Display
 *  \details   Die Klasse dient als Parent f�r die einzelnen Ansichten. Sie stellt dar�ber hinaus funktionalit�ten f�r die Child Klassen bereit und regelt den Aufruf dieser. Sie ist somit das Bindeglied zwischen der Ausgabe und dem funktionalen teil des Programmes.
 *  \author    Joshua Hahn
 *  \date      05.07.2021
 */

#ifndef Game_SETTINGS_H
#define Game_SETTINGS_H

extern short int iButtons_cor_GS[10][5];

class Game_Settings : public Pages
{
		public:
			//Konstruktor und �bergabe der Instanz
				static Game_Settings& instance()
			{
				static Game_Settings _instance;
				return _instance;
			}
			~Game_Settings() {}
			
		//Public Methoden
			void drawpage(void);
				
			short int buttonOnPagePressed(int,int);
		
		private:
			
			Game_Settings() {
			} ;// verhindert, dass ein Objekt von au�erhalb von N erzeugt wird.
                    // protected, wenn man von der Klasse noch erben m�chte
			Game_Settings( const Game_Settings& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
				
			Game_Settings & operator = (const Game_Settings &); //Verhindert weitere Instanz durch Kopie
};

#endif

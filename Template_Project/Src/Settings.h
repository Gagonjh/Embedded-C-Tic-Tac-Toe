/*! 
 *  \brief     Dient der Ausgabe auf dem Display
 *  \details   Die Klasse dient als Parent f�r die einzelnen Ansichten. Sie stellt dar�ber hinaus funktionalit�ten f�r die Child Klassen bereit und regelt den Aufruf dieser. Sie ist somit das Bindeglied zwischen der Ausgabe und dem funktionalen teil des Programmes.
 *  \author    Joshua Hahn
 *  \date      21.06.2021
 */

#ifndef SETTINGS_H
#define SETTINGS_H

extern short int iButtons_cor_S[10][5];

class Settings : public Pages
{
		public:
			//Konstruktor und �bergabe der Instanz
				static Settings& instance()
			{
				static Settings _instance;
				return _instance;
			}
			~Settings() {}
			
		//Public Methoden
			void drawpage(void);
				
			short int buttonOnPagePressed(int,int);
		
		private:
			Settings() {} ;// verhindert, dass ein Objekt von au�erhalb von N erzeugt wird.
			void highlight_selected_colormode_button(short int);
				
		// protected, wenn man von der Klasse noch erben m�chte
			Settings( const Settings& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
			Settings & operator = (const Settings &); //Verhindert weitere Instanz durch Kopie
};

#endif

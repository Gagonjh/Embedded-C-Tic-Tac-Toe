/*! 
 *  \brief     
 *  \details   
 *  \author    Joshua Hahn
 *  \date      21.06.2021
 */

#ifndef PAGE_SETTINGS_H
#define PAGE_SETTINGS_H

extern short int iButtons_cor_S[10][5];

class Page_Settings : public Pages
{
		public:
			//Konstruktor und übergabe der Instanz
				static Page_Settings& instance()
			{
				static Page_Settings _instance;
				return _instance;
			}
			~Page_Settings() {}
			
		//Public Methoden
			void drawpage(void);
				
			short int buttonOnPagePressed(int,int);
		
		private:
			Page_Settings() {} ;// verhindert, dass ein Objekt von außerhalb von N erzeugt wird.
			void highlight_selected_colormode_button();
			void highlight_selected_game_mode();
		// protected, wenn man von der Klasse noch erben möchte
			Page_Settings( const Page_Settings& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
			Page_Settings & operator = (const Page_Settings &); //Verhindert weitere Instanz durch Kopie
};

#endif

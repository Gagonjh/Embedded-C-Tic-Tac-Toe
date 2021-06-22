//Author:     			Joshua Hahn  
//Projekt:    			Tic Tac Toe
//Datum:						16.06.2021

#ifndef MENUE_H
#define MENUE_H

extern short int iButtons_cor_M[10][4];

class Menue : public Pages
{
		public:
      
						//Konstruktor
				static Menue& instance()
			{
				static Menue _instance;
				return _instance;
			}
			~Menue() {}
		
			void drawpage(void);
			
			
			private:
			Menue() {
			} ;// verhindert, dass ein Objekt von außerhalb von N erzeugt wird.
                    // protected, wenn man von der Klasse noch erben möchte
			Menue( const Menue& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
				
			Menue & operator = (const Menue &); //Verhindert weitere Instanz durch Kopie
};

#endif

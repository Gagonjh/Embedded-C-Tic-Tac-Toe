/*! 
 *  \brief     
 *  \details   
 *  \author    	Joshua Hahn
 *  \date      	05.07.2021
 *  \bug				Speicher von Keil ist voll sobalt man größere Bitmaps erstellt.
 */
 
 #ifndef SYMBOLE_H
#define SYMBOLE_H

class Symbole
{
//Konstruktor und Destruktor
		public:
			//! Zugriff auf die Instanz der Klasse von Außerhalb
			static Symbole& instance()
			{
				static Symbole _instance;
				return _instance;
			}
			//! Destruktor Definition und Deklaration
			~Symbole() {}
				
		private:
			Symbole();
			//! Verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
			Symbole( const Symbole& );
			//! Verhindert weitere Instanz durch Kopie
			Symbole & operator = (const Symbole &);

//Variabeln
		private:
			//! Symbole Player 1
			short simP1;
			//! Symbole Player 2
			short simP2;
		
//Methoden	
		public:
			void drawPiece(short,short,short);
			void setPlayerSim(short,short);
				
		private:			
	
			void drawSickle(short,short,short);
			void drawHammer(short,short,short);
			void drawCircle(short,short,short);
			void drawX(short,short,short);
};
#endif

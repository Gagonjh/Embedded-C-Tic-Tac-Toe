/*! 
 *  \brief     
 *  \details   
 *  \author    	Joshua Hahn
 *  \date      	05.07.2021
 *  \bug				Speicher von Keil ist voll sobalt man größere erstellt
 */
 
 #ifndef SYMBOLE_H
#define SYMBOLE_H

class Symbole
{
		public:
			//Konstruktor und übergabe der Instanz
				static Symbole& instance()
			{
				static Symbole _instance;
				return _instance;
			}
			~Symbole() {}
				
		void drawPiece(short,short,short);
		void setPlayerSim(short,short);
				
		private:
				
			short simP1;
			short simP2;
		
			Symbole();// verhindert, dass ein Objekt von außerhalb von N erzeugt wird.
                    // protected, wenn man von der Klasse noch erben möchte
			Symbole( const Symbole& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
				
			Symbole & operator = (const Symbole &); //Verhindert weitere Instanz durch Kopie
			
			void drawSickle(short,short,short);
			void drawHammer(short,short,short);
			void drawCircle(short,short,short);
			void drawX(short,short,short);
};
#endif

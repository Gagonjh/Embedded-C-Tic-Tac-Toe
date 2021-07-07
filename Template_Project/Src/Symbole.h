/*! 
 *  \brief     
 *  \details   
 *  \author    	Joshua Hahn
 *  \date      	05.07.2021
 *  \bug				Speicher von Keil ist voll sobalt man gr��ere erstellt
 */
 
 #ifndef SYMBOLE_H
#define SYMBOLE_H

class Symbole
{
		public:
			//Konstruktor und �bergabe der Instanz
				static Symbole& instance()
			{
				static Symbole _instance;
				return _instance;
			}
			~Symbole() {}
				
			const static WORD sym_home[];
			const static WORD test[];
		
		private:
			
			Symbole(){
			};// verhindert, dass ein Objekt von au�erhalb von N erzeugt wird.
                    // protected, wenn man von der Klasse noch erben m�chte
			Symbole( const Symbole& );//verhindert, dass eine weitere Instanz via Kopier-Konstruktor erstellt werden kann
				
			Symbole & operator = (const Symbole &); //Verhindert weitere Instanz durch Kopie

};
#endif

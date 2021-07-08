/*! 
 *  \brief     	Bildet das Feld und die Spielsteine ab.
 *  \details   	Zeigt das Spielfeld und die Spielsteine auf dem Bildschirm an.
 *  \author			Yasin Calli 
 */


#ifndef FIELD_H
#define FIELD_H
	
class Field
{
	public:
		void drawField();
		void drawToken(Coordinates);
};
#endif

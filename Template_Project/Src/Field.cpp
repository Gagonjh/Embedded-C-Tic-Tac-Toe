/*! 
 *  \brief     	
 *  \details   	Die Aufgabe dieser Klasse ist das Zeichnen des Spielfeldes und der Spielsteine.
 *  \author			Yasin Calli 
 */


#include "./Project_Headers.h"
	
Cells cells();
	
void Field::drawField()
{
	disp1.drawFrame(50,50,390,390,2, Style::instance().color_Field );
	for(WORD i = 180; i<440; i+=130) {
		disp1.drawLine(i,50,i,440,2,Style::instance().color_Field);
		disp1.drawLine(50,i,440,i,2,Style::instance().color_Field);
	}
}

void Field::drawToken(Coordinates token)
{
	Symbole::instance().drawPiece(token.x,token.y,token.player);
}

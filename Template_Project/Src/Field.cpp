#include "./Project_Headers.h"

/*!
	\brief Zeichnet das Feld.
	\details Erstellt ein 3x3 groﬂes Feld auf dem Bildschirm.
*/
void Field::drawField()
{
	disp1.drawFrame(50,50,390,390,2, Style::instance().color_Field );
	for(WORD i = 180; i<440; i+=130) {
		disp1.drawLine(i,50,i,440,2,Style::instance().color_Field);
		disp1.drawLine(50,i,440,i,2,Style::instance().color_Field);
	}
}

/*!
	\brief Zeichnet das Feld.
	\details Zeichnet den Spielstein des Spielers der dran ist auf das Spielfeld.
	\param token enthaelt Koordinaten und die zugehoerigen Spielerinformationen.
	\sa Symbole::instance().drawPiece()
*/
void Field::drawToken(Coordinates token)
{
	Symbole::instance().drawPiece(token.x,token.y,token.player);
}

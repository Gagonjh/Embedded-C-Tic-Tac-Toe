/*! 
 *  \brief     
 *  \details   
 *  \author    Joshua Hahn
 *  \date      05.07.2021
 */
 
 
#include "./Project_Headers.h"

/*!
	\brief Private Konstruktor der Klasse.
	\details Initalisiert die Standart Symbole die verwendet werden von der Field.cpp .
	\sa Field::drawToken()
*/
Symbole::Symbole()
{
	simP1 = 0;
	simP2 = 1;
}

/*!
	\brief Setzt Spieler Zeichen.
	\details Setzt für beide Spieler die Zeichen die übergeben worden sind.
	\param Nummer des Symboles für Player 1.
	\param Nummer des Symboles für Player 2.
	\sa Symbole::drawPiece()
*/
void Symbole::setPlayerSim(short p1,short p2)
{
	simP1 = p1;
	simP2 = p2;
}

/*!
	\brief Gibt das Spieler Zeichen aus.
	\details Die Funktion ruft die entsprechende Methode für das Zeichen was dem übergebenen Spiele zugeteilt ist auf.
	\param X Coordinate des übergebenen Feldes.
	\param Y Coordinate des übergebenen Feldes.
	\param Der Aktive Spieler der Ausgewertet werden soll.
	\sa Symbole::drawSickle()
	\sa Symbole::drawHammer()
	\sa Symbole::drawCircle()
	\sa Symbole::drawX()
*/
void Symbole::drawPiece(short corX,short corY,short player)
{
	short activeSimColor = 0;
	short activeSim = 0;
	if(player == 1)
	{
		activeSim = simP1; 		
		activeSimColor = Style::instance().color_Player_1;
	}
	else
	{
		activeSim = simP2;
		activeSimColor = Style::instance().color_Player_2;
	}
	switch(activeSim) 
			{
				case 0:
					Symbole::drawX(corX,corY,activeSimColor);
				break;
				case 1:
					drawCircle(corX,corY,activeSimColor);
				break;
				case 2:
					drawSickle(corX,corY,activeSimColor);
				break;
				case 3:
					drawHammer(corX,corY,activeSimColor);
				break;
				default:
					break;
			}
}

/*!
	\brief Gibt eine Sichel als Spieler Symbol aus.
	\details Weißt den Spieler der diese als Spielsymbol hat als Teil der Bauernklasse aus.
	\param X Coordinate des übergebenen Feldes.
	\param Y Coordinate des übergebenen Feldes.
	\param Spieler Farbe wird von drawPiece übergeben.
	\sa Symbole::drawPiece()
*/
void Symbole::drawSickle(short corX,short corY,short color)
{
	//!Wegen der Kompatiblität zur ursprüglichen Funktion drawCircle wird die Coordinate angepasst.
	corX = corX - 45;
	corY = corY - 45;
	//Kreis 1
	disp1.drawCircle(corX+45,corY+35,30,color);
	//Kreis 2
	disp1.drawCircle(corX+40,corY+30,24,Style::instance().color_Backround);
	//Kreis 3
	disp1.drawCircle(corX+20,corY+45,19,Style::instance().color_Backround);
	//Kreis 4
	disp1.drawCircle(corX+33,corY+54,11,Style::instance().color_Backround);
	//Liniel
	disp1.drawLine(corX+45,corY+58,corX+45,corY+80,14,color);
}

/*!
	\brief Gibt einen Hammer als Spieler Symbol aus.
	\details Weißt den Spieler der dieses Spielsymbol hat als Teil der Arbeiterklasse aus.
	\param X Coordinate des übergebenen Feldes.
	\param Y Coordinate des übergebenen Feldes.
	\param Spieler Farbe wird von drawPiece übergeben.
	\sa Symbole::drawPiece()
*/
void Symbole::drawHammer(short corX,short corY,short color)
{
	//!Wegen der Kompatiblität zur ursprüglichen Funktion drawCircle wird die Coordinate angepasst.
	corX = corX - 45;
	corY = corY - 45;
	//1.Linie
	disp1.drawLine(corX+17,corY+21,corX+73,corY+21,18,color);
	//2. Linie
	disp1.drawLine(corX+45,corY+28,corX+45,corY+80,20,color);
	//Kreis
	disp1.drawCircle(corX+73,corY+12,11,Style::instance().color_Backround);
}

/*!
	\brief Gibt einen hohlen Kreis aus
	\details Dient als eines der 2 Standartsymbole für Tic Tac Toe
	\param X Coordinate des übergebenen Feldes
	\param Y Coordinate des übergebenen Feldes
	\param Spieler Farbe wird von drawPiece übergeben
	\sa Symbole::drawPiece()
*/
void Symbole::drawCircle(short corX,short corY,short color)
{
	disp1.drawCircle(corX,corY,45,color);
	disp1.drawCircle(corX,corY,35,Style::instance().color_Backround);
}

/*!
	\brief Gibt ein X aus.
	\details Dient als eines der 2 Standartsymbole für Tic Tac Toe
	\param X Coordinate des übergebenen Feldes
	\param Y Coordinate des übergebenen Feldes
	\param Spieler Farbe wird von drawPiece übergeben
	\sa Symbole::drawPiece()
*/
void Symbole::drawX(short corX,short corY,short color)
{
	//!Wegen der Kompatiblität zur ursprüglichen Funktion drawCircle wird die Coordinate angepasst.
	corX = corX - 45;
	corY = corY - 45;
	disp1.drawLine(corX+7,corY+7,corX+83,corY+83,10,color);
	disp1.drawLine(corX+7,corY+83,corX+83,corY+7,10,color);
}

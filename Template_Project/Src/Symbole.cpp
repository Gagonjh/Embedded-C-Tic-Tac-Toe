/*! 
 *  \brief     
 *  \details   
 *  \author    Joshua Hahn
 *  \date      05.07.2021
 */
 
 
#include "./Project_Headers.h"

Symbole::Symbole()
{
	simP1 = 0;
	simP2 = 1;
}

void Symbole::setPlayerSim(short p1,short p2)
{
	simP1 = p1;
	simP2 = p2;
}

void Symbole::drawPiece(short corX,short corY,short player)
{
	short activeSimColor = 0;
	short activeSim = 0;
	if(player == 1)
	{
		activeSim = simP1; 		//! Auswahl des Symboles
		activeSimColor = Style::instance().color_Player_1;	//! Auswahl der Farbe
	}
	else
	{
		activeSim = simP2;		//! Auswahl des Symboles
		activeSimColor = Style::instance().color_Player_2;	//! Auswahl der Farbe
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

void Symbole::drawSickle(short corX,short corY,short color)
{
	//!Wegen der Kompatiblität zur ursprüglichen Funktion drawCircle
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

void Symbole::drawHammer(short corX,short corY,short color)
{
	//!Wegen der Kompatiblität zur ursprüglichen Funktion drawCircle
	corX = corX - 45;
	corY = corY - 45;
	//1.Linie
	disp1.drawLine(corX+17,corY+21,corX+73,corY+21,18,color);
	//2. Linie
	disp1.drawLine(corX+45,corY+28,corX+45,corY+80,20,color);
	//Kreis
	disp1.drawCircle(corX+73,corY+12,11,Style::instance().color_Backround);
}

void Symbole::drawCircle(short corX,short corY,short color)
{
	disp1.drawCircle(corX,corY,45,color);
	disp1.drawCircle(corX,corY,35,Style::instance().color_Backround);
}

void Symbole::drawX(short corX,short corY,short color)
{
	//!Wegen der Kompatiblität zur ursprüglichen Funktion drawCircle
	corX = corX - 45;
	corY = corY - 45;
	disp1.drawLine(corX+7,corY+7,corX+83,corY+83,10,color);
	disp1.drawLine(corX+7,corY+83,corX+83,corY+7,10,color);
}

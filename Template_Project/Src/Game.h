/*! 
 \brief     	Fuehrt Zuege aus.
 \details   	Steuert die KI und den gesamtablauf eines Zuges.
 \author			Yasin Calli 
 \author    	Joshua Hahn
*/


#ifndef GAME_H
#define GAME_H

class Game
{
	private:
		/*!
			\brief Die Steuerung der Partie. Kontrolliert KI, Spielereingabe und Spielzustand.
			\sa Controller
		*/
		Controller* controller;
	public:
		//! Zugverzoegerung der KI
		/*!
			Ein wert der in jedem durchlauf hochgezaehlt wird und den KI-Zug zeitlich verzögert.
		*/
		short unsigned waitAi;
		short ttt_classic(short,short,uint8_t);
	Game();
	~ Game ();
	
};

#endif

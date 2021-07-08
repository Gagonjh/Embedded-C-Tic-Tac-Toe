/*! 
 *  \brief     	
 *  \details   
 *  \author			Yasin Calli 
 *  \author    	Joshua Hahn
 */


#ifndef GAME_H
#define GAME_H

class Game
{
	private:
		Controller* controller;
	public:
		short unsigned waitAi;
		short ttt_classic(short,short,uint8_t);
	Game();
	~ Game ();
	
};

#endif

#ifndef GAME_H
#define GAME_H

class Game
{
	private:
		Controller controller;
		BYTE gameMode;
	public:
		void newGame();
		short ttt_classic(short,short);
		Game(BYTE);
};

#endif

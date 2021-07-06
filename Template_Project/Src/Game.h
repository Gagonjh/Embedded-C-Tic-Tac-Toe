#ifndef GAME_H
#define GAME_H

class Game
{
	private:
		short posX;
		short posY;
		Controller controller;
		short gameMode;
		Cells defaultCells;
		Field field;
	public:
		short ttt_classic(short,short);
		Game(short,Controller, Field);
};

#endif

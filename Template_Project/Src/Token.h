#ifndef TOKEN_H
#define TOKEN_H
#include "datatypes.h"

class Token
{
	public:
		const Coordinates coordinates;
		const short player;
		Token(Coordinates, short);
};

#endif

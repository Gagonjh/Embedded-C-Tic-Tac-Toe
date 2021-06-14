#line 1 "Src\\Token.cpp"
#line 1 "Src\\Token.h"
#line 1 "Src\\datatypes.h"



typedef struct coordinates {
	int x;
	int y;
	short player;
} Coordinates;

#line 4 "Src\\Token.h"

class Token
{
	public:
		const Coordinates coordinates;
		const short player;
		Token(Coordinates, short);
};

#line 2 "Src\\Token.cpp"

Token::Token(Coordinates coordinates, short player):coordinates(coordinates),player(player){};

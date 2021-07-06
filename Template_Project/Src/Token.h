/*! 
 *  \brief     Dient der Ausgabe auf dem Display
 *  \details   Diese Klasse enthält die informationen über den Spieler und die Position des platzierten Spielsteins.
 *  \author    Yasin Calli
 *  \date      06.07.2021
 */

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

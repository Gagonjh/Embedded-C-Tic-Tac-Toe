/*! 
 *  \brief     
 *  \details   Koodinaten
 *  \author    Yasin Calli
 *  \date      06.07.2021
 */

#ifndef DATATYPES_H
#define DATATYPES_H

#include <inttypes.h>

typedef struct coordinates {
	uint16_t x;
	uint16_t y;
	uint8_t player;
} Coordinates;

#endif

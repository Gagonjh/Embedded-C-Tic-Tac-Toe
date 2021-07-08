/*! 
 *  \brief     Datentypen.
 *  \details   Enthaelt die Datentypen: Koordinaten.
 *  \author    Yasin Calli
 *  \date      06.07.2021
 */

#ifndef DATATYPES_H
#define DATATYPES_H

#include <inttypes.h>

/*!
	\brief Koordinaten Datentyp.
	\details Enthaelt x und y Koordinaten und informationen ueber den Spieler.
*/
typedef struct coordinates {
	uint16_t x;
	uint16_t y;
	uint8_t player;
} Coordinates;

#endif

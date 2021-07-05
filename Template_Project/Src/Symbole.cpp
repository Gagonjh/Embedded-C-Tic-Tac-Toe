/*! 
 *  \brief     Dient der Ausgabe auf dem Display
 *  \details   Die Klasse dient als Parent f�r die einzelnen Ansichten. Sie stellt dar�ber hinaus funktionalit�ten f�r die Child Klassen bereit und regelt den Aufruf dieser. Sie ist somit das Bindeglied zwischen der Ausgabe und dem funktionalen teil des Programmes.
 *  \author    Joshua Hahn
 *  \date      05.07.2021
 */
 
 
#include "./project_headers.h"

/*
static unsigned char sym_home[] = {
   0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x0f, 0x00, 0x80, 0x19, 0x00,
   0xc0, 0x30, 0x00, 0x60, 0x60, 0x00, 0x30, 0xc0, 0x00, 0xf8, 0xff, 0x01,
   0x10, 0x80, 0x00, 0xd0, 0xb9, 0x00, 0xd0, 0xb9, 0x00, 0x10, 0x80, 0x00,
   0xf0, 0xff, 0x00, 0x10, 0x80, 0x00, 0xd0, 0x81, 0x00, 0x50, 0xb9, 0x00,
   0x50, 0xb9, 0x00, 0x50, 0x81, 0x00, 0xf0, 0xff, 0x00, 0x00, 0x00, 0x00 };
*/
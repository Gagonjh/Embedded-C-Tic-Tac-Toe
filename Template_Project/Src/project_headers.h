/*!  	
 *  \author    	Joshua Hahn
 *  \author			Yasin Calli
 *  \date      	21.06.2021
 */

#ifndef PROJECT_HEADERS_H
#define PROJECT_HEADERS_H

#include "../../EmbSysLib/Src/lib.h"
#include "../../EmbSysLib/Src/Com/Device/Display/devDisplayGraphic.h"
#include "./datatypes.h"
#include "./Controller.h"
#include "./Cells.h"
#include "./Game.h"
#include "./Field.h"
#include "./Pages.h"
#include "./Page_Menue.h"
#include "./Page_Settings.h"
#include "./Symbole.h"
#include "./Page_Game.h"
#include "./Page_History.h"
#include "./Style.h"


extern cDevDisplayGraphic& disp1;
extern uint8_t gameMode;

#endif

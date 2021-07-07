/*! 
 *  \brief     	
 *  \details   
 *  \author			Yasin Calli 
 */


#include "./Project_Headers.h"
	
Cells cells();
	
void Field::drawField()
{
	disp1.drawFrame(50,50,390,390,2, Style::instance().color_Field );
	for(WORD i = 180; i<440; i+=130) {
		disp1.drawLine(i,50,i,440,2,Style::instance().color_Field);
		disp1.drawLine(50,i,440,i,2,Style::instance().color_Field);
	}
}

void Field::drawToken(Coordinates token)
{
	switch(token.player)
	{
		case 1:
			disp1.drawCircle(token.x,token.y, 45, Style::instance().color_Player_1);
			break;
		case 2:
			disp1.drawCircle(token.x,token.y, 45, Style::instance().color_Player_2);
			break;
	}
}

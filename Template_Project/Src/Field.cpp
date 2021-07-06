#include "./project_headers.h"
	
Cells cells();
	
void Field::drawField()
{
	disp1.drawFrame(50,50,390,390,2, cHwDisplayGraphic::Red );
	for(WORD i = 180; i<440; i+=130) {
		disp1.drawLine(i,50,i,440,2,cHwDisplayGraphic::Red);
		disp1.drawLine(50,i,440,i,2,cHwDisplayGraphic::Red);
	}
}

void Field::drawToken(Coordinates token)
{
	switch(token.player)
	{
		case 1:
			disp1.drawCircle(token.x,token.y, 45, cHwDisplayGraphic::Red);
			break;
		case 2:
			disp1.drawCircle(token.x,token.y, 45, cHwDisplayGraphic::Cyan);
			break;
	}
}

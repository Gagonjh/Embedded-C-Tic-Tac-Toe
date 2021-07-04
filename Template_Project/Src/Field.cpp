#include "./project_headers.h"
	
Field::Field(cDevDisplayGraphic& konst_disp):disp1(konst_disp){}

Cells cells();
	
void Field::drawField()
{
	disp1.drawFrame(50,50,390,390,2, cHwDisplayGraphic::Red );
	for(int i = 180; i<440; i+=130) {
		disp1.drawLine(i,50,i,440,2,cHwDisplayGraphic::Red);
		disp1.drawLine(50,i,440,i,2,cHwDisplayGraphic::Red);
	}
}

void Field::drawToken(Token token)
{
	switch(token.player)
	{
		case 1:
			disp1.drawCircle(token.coordinates.x,token.coordinates.y, 45, cHwDisplayGraphic::Red);
			disp1.drawCircle(token.coordinates.x,token.coordinates.y, 42, cHwDisplayGraphic::Navy);
			break;
		case 2:
			disp1.drawCircle(token.coordinates.x,token.coordinates.y, 45, cHwDisplayGraphic::Cyan);
			disp1.drawCircle(token.coordinates.x,token.coordinates.y, 42, cHwDisplayGraphic::Navy);
			break;
	}
}

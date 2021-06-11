#include "./project_headers.h"

void Field::drawField()
{
		disp.drawFrame(50,50,390,390,2, cHwDisplayGraphic::Red );
	for(int i = 180; i<440; i+=130) {
		disp.drawLine(i,50,i,440,2,cHwDisplayGraphic::Red);
		disp.drawLine(50,i,440,i,2,cHwDisplayGraphic::Red);
	}
};

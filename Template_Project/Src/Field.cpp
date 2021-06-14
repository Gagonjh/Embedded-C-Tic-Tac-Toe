#include "./project_headers.h"
	
	Field::Field(cDevDisplayGraphic& konst_disp):disp1(konst_disp){}

	void Field::drawField()
{
		disp1.drawFrame(50,50,390,390,2, cHwDisplayGraphic::Red );
	for(int i = 180; i<440; i+=130) {
		disp1.drawLine(i,50,i,440,2,cHwDisplayGraphic::Red);
		disp1.drawLine(50,i,440,i,2,cHwDisplayGraphic::Red);
	}
}
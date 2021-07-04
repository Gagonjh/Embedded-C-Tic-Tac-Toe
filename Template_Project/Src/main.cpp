#include "project_headers.h"
#include "./configSTM32F7xx.h"

cDevDisplayGraphic& disp1 = disp;

int main(void)
{
  #ifdef USE_GRAPHIC_DISPLAY
		Field field(disp);
    disp.setBackColor(cHwDisplayGraphic::Navy);
    disp.clear();
		Cells defaultCells;
		Controller controller(disp1,defaultCells, 9, field);
		short posX=0;
		short posY=0;
		short isNotGameOver = 1;
		while(1)
		{
			while(isNotGameOver == 1)
			{
					cDevControlPointer::cData event = pointer.get();
					if(event.flags == event.CTRL_DWN && posX == -1 && posY == -1)
						{
							posX = event.posX;
							posY = event.posY;
						}
					else
						{
							posX = -1;
							posY = -1;
						}
					field.drawField();
					//disp1.drawText( 440,120, 18, "%d %d", posX, posY);
					if(posX !=-1 && posY != -1) 
						{
							controller.control(posX, posY);
						}
					//disp1.drawText( 440,150, 18, "currentPlayer %d", currentPlayer);
					disp.refresh();
					if(controller.isGameOver()!=-1)
					{
						isNotGameOver = 0;
					}
			}
			disp1.drawText( 440,200, 18, "Game over");
		}
	#endif
}

//EOF

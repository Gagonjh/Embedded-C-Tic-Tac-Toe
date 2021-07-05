#include "project_headers.h"
#include "./configSTM32F7xx.h"

cDevDisplayGraphic& disp1 = disp;

int main(void)
{
  #ifdef USE_GRAPHIC_DISPLAY
		short winningPlayer=0;
		short posX=0;
		short posY=0;
		short isGameOver=1;
		while(1)
		{
			Cells defaultCells;
			Field field(disp);
			Controller controller(defaultCells, field);
			disp.setBackColor(cHwDisplayGraphic::Navy);
			disp.clear();
			isGameOver = 0;
			field.drawField();
			disp.refresh();
			while(isGameOver == 0)
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
					if(posX !=-1 && posY != -1) 
						{
							controller.control(posX, posY);
							short state = controller.getGameState();
							switch(state)
							{
								case -1: isGameOver=0; break;
								case 	0: isGameOver=1; winningPlayer=0; break;
								case  1: isGameOver=1; winningPlayer=1; break;
								case  2: isGameOver=1; winningPlayer=2; break;
							}
							disp.refresh();
						}
			}
			if(winningPlayer != 0)
			{
				while(1)
				{
					cDevControlPointer::cData event = pointer.get();
					disp1.drawText( 440,220, 18, "Player %d has won!", winningPlayer);
					disp1.drawText( 440,250, 18, "Game over");
					disp.refresh();
					if(event.flags == event.CTRL_DWN) break;
				}
			}
		}
	#endif
}

//EOF

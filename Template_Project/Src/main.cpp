#include "project_headers.h"
#include "./configSTM32F7xx.h"

cDevDisplayGraphic& disp1 = disp;

int main(void)
{
		short gameMode=1;
		Cells defaultCells;
		Field field;
		Controller controller(defaultCells, field);
		Game game(gameMode,controller,field);
		disp.refresh();
  #ifdef USE_GRAPHIC_DISPLAY
		while(1)
			{
				cDevControlPointer::cData event = pointer.get();
				game.ttt_classic(event.posX,event.posY, event.flags==event.CTRL_DWN);
			}
	#endif
}

//EOF

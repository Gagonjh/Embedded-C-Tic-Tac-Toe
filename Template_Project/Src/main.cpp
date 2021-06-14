#include "project_headers.h"
#include "./configSTM32F7xx.h"
WORD cells[3][3][3] = {
												{
													{115,115,0},
													{245,115,0},
													{375,115,0}
												},
												{
													{115,245,0},
													{245,245,0},
													{375,245,0}
												},
												{
													{115,375,0},
													{245,375,0},
													{375,375,0}
												}
											};
int main(void)
{
	short currentPlayer = 0;
  #ifdef USE_GRAPHIC_DISPLAY
		Field field(disp);
    disp.setBackColor(cHwDisplayGraphic::Navy);
    disp.clear();
  #endif

  while(1)
  {
    #ifdef USE_GRAPHIC_DISPLAY
      cDevControlPointer::cData event = pointer.get();
			field.drawField();
			if(event.posX<390 && event.posX > 100 && event.posY < 390 && event.posY > 100) 
					{
						for(int i = 0; i<3; i++) 
						{
							for(int j = 0; j<3; j++) 
							{
								Coordinates cellCoords = {cells[i][j][0],cells[i][j][1]};
								WORD *cellValue = &cells[i][j][2];
								disp.drawText( 440,20, 18, "%d", *cellValue);
								short xDiff = abs(cellCoords.x - event.posX);
								short yDiff = abs(cellCoords.y - event.posY);
								if(xDiff < 50 && yDiff<50) 
									{
										if(*cellValue==0) 
											{
												Token playerToken(cellCoords,currentPlayer);
												field.drawToken(playerToken);
												*cellValue = (WORD) 1;
												disp.drawText( 440,20, 18, "Set value to 1");
												currentPlayer=(currentPlayer+1)%2;
											}
										event.posX = 0;
										event.posY = 0;
									}
								if(event.posX == 0 && event.posY == 0) 
									{
										break;
									}
							}
							if(event.posX == 0 && event.posY == 0) 
								{
									break;
								}
						}
					}
//      disp.drawText( 440,20, 18, "x:%3d y:%3d ctrl:0x%02x",  event.posX, event.posY, event.flags );
			
			

      disp.refresh();
    #endif
  }
}

//EOF

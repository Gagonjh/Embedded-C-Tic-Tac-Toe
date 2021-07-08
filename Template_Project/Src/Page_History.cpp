/*! 
 *  \brief     
 *  \details   
 *  \author    Joshua Hahn
 *  \date      21.06.2021
 */

#include "./Project_Headers.h"
Page_History::Page_History()
{
	winner = new short[18];
	short temp[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(short i = 0; i<18; i++)
	{
				winner[i] = temp[i];
	}
	
	hOffset=0;
}

Page_History::~Page_History() 
{
	delete winner;
}



 short int iButtons_cor_H[10][5] =
	{
				{565,795,415,475,0}, 	//Button 1 :Hauptmenü
				{0,0,0,0,0}, 					//Button 2 :
				{0,0,0,0,0}, 					//Button 3 :
				{0,0,0,0,0}, 					//Button 4 :
				{0,0,0,0,0}, 					//Button 5 :
				{0,0,0,0,0}, 					//Button 6 :
				{0,0,0,0,0}, 					//Button 7 : 
				{0,0,0,0,0}, 					//Button 8 : 
				{0,0,0,0,0}, 					//Button 9 :
				{0,0,0,0,0} 					//Button 10:
			};//[*][0]=x start, [*][1]=x end, [*][2]=y start & [*][3]=y end 

void Page_History::newWinner(short winnerLastRound)
{
	winner[hOffset] = winnerLastRound;
	hOffset = (hOffset+1)%18;
}

void Page_History::drawpage()
{
	disp1.clear();
  disp1.setBackColor(Style::instance().color_Backround);
	siteHeader(0,0,24,16,"Letzte Spiele");
	draw_button(iButtons_cor_S[0][0],iButtons_cor_S[0][2],iButtons_cor_S[0][3]-iButtons_cor_S[0][2],iButtons_cor_S[0][1]-iButtons_cor_S[0][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Hauptmenu");
	int gameNum = 18;
	for(int i=0; i <= 8;i++)
	{
		disp1.drawText(70,70+40*i,10," Gewinner %d: %d",gameNum,winner[(i+hOffset)%18]);
		gameNum--;
	}
	
	disp1.drawLine(400,50,400,480,10,Style::instance().color_Boxes);
	
	for(short i=9; i <= 17;i++)
	{
		disp1.drawText(470,70+40*(i-9),10," Gewinner %d: %d",gameNum,winner[(i+hOffset)%18]);
		gameNum--;
	}
}

short int Page_History::buttonOnPagePressed(int posX,int posY)
{
	short int p = -1;
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,0);
	}
	return p;
}

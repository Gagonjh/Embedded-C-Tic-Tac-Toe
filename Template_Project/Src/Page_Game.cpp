/*! 
 *  \brief     	
 *  \details   	
 *  \author    	Joshua Hahn
 *  \author			Yasin Calli
 *  \date      	21.06.2021
 */

#include "./Project_Headers.h"

Page_Game::Page_Game() 
{
			//Menue& menueinstance = Menue::instance();
			restart_state = 0;	//! Button wird nicht angezeigt und ausgewertet
}	

 short int iButtons_cor_GS[10][5] =
	{
				{565,795,415,475,0}, 	//Button 1 :Hauptmenü
				{460,660,300,360,-2}, //Button 2 :Game Restart
				{0,0,0,0,0}, 					//Button 3 :
				{0,0,0,0,0}, 					//Button 4 :
				{0,0,0,0,0}, 					//Button 5 :
				{0,0,0,0,0}, 					//Button 6 :
				{0,0,0,0,0}, 					//Button 7 : 
				{0,0,0,0,0}, 					//Button 8 : 
				{0,0,0,0,0}, 					//Button 9 :
				{0,0,0,0,0} 					//Button 10:
			};//[*][0]=x start, [*][1]=x end, [*][2]=y start & [*][3]=y end 


void Page_Game::drawpage()
{
  disp1.setBackColor(Style::instance().color_Backround);
	disp1.setTextColor(Style::instance().color_Font);
	draw_button(iButtons_cor_GS[0][0],iButtons_cor_GS[0][2],iButtons_cor_GS[0][3]-iButtons_cor_GS[0][2],iButtons_cor_GS[0][1]-iButtons_cor_GS[0][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Hauptmenu");
}

short int Page_Game::buttonOnPagePressed(int posX,int posY)
{
	short int p = -1;
	if(p == -1)
	{
			p = Page_Game::instance().isPressed(posX,posY,iButtons_cor_GS,0);
	}
	if(p == -1 && restart_state == 1)
	{
			p = Page_Game::instance().isPressed(posX,posY,iButtons_cor_GS,1);
			Page_Game::instance().restart_state = 2;
	}
		//Return to default value
	if(p==-2)
	{
		p = -1;
		disp1.clear();
		Page_Game::instance().drawpage();
	}
	return p;
}

void Page_Game::output_Current_Player(short player)
{
	disp1.drawText(500,200,18,"Es spielt Player: %d",player);
}

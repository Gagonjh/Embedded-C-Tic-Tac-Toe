/*! 
 *  \brief     
 *  \details  	
 *  \author    	Joshua Hahn
 *  \author			Yasin Calli 
 *  \date      	21.06.2021
 */

#include "./Project_Headers.h"
short int iButtons_cor_S[10][5] =
	{
				{565,795,415,475,0}, 	//! Button 1 :Hauptmenü
				{300,350,120,170,-2}, //! Button 2 :Color Theme 1 weiß
				{410,460,120,170,-2}, //! Button 3 :Color Theme 0 schwarz
				{520,560,120,170,-2}, //! Button 4 :Color Theme 2 RU
				{260,480,260,300,-2}, //! Button 5 :vs Spieler
				{500,720,260,300,-2}, //! Button 6 :vs Bot
				{0,0,0,0,0}, 					//! Button 7 : 
				{0,0,0,0,0}, 					//! Button 8 : 
				{0,0,0,0,0}, 					//! Button 9 :
				{0,0,0,0,0} 					//! Button 10:
			};//[*][0]=x start, [*][1]=x end, [*][2]=y start & [*][3]=y end, [*][4]=-2 Ein button auf der seite mit funktion
			
void Settings::highlight_selected_colormode_button()
{
	switch(Style::instance().color_Mode)
	{
		case 0: disp1.drawCircle(410,120,50,0x17E0); break;
		case 1: disp1.drawCircle(300,120,50,0x17E0); break;
		case 2: disp1.drawCircle(520,120,50,0x17E0); break;
		default: break;
	}
}

void Settings::highlight_selected_game_mode()
{
	switch(gameMode)
	{
		case 0: disp1.drawFrame(260,260,220,40,2,0x17E0); break;
		case 1: 	disp1.drawFrame(500,260,220,40,2,0x17E0); break;
		default: break;
	}
}

void Settings::drawpage()
{
  disp1.setBackColor(Style::instance().color_Backround);
	disp1.setTextColor(Style::instance().color_Font);
	siteHeader(0,0,24,16,"Settings");
	draw_button(iButtons_cor_S[0][0],iButtons_cor_S[0][2],iButtons_cor_S[0][3]-iButtons_cor_S[0][2],iButtons_cor_S[0][1]-iButtons_cor_S[0][0],15,1,Style::instance().color_Boxes,Style::instance().color_Field,24,16,"Hauptmenu");
//Draw Color Change Buttons
	disp1.drawText(40,120,"Farbschema:");
	disp1.drawCircle(300,120,50,Style::instance().color_Field);
	disp1.drawCircle(300,120,40,0xFFFF);
	disp1.drawCircle(410,120,50,Style::instance().color_Field);
	disp1.drawCircle(410,120,40,0x7BCF);
	disp1.drawCircle(520,120,50,Style::instance().color_Field);
	disp1.drawCircle(520,120,40,0x98A2);
	highlight_selected_colormode_button();
//Game mode change Buttons
	disp1.drawText(40,270,"Spielmodus:");
	disp1.drawFrame(260,260,220,40,2,Style::instance().color_Field);
	disp1.drawText(280,270,"vs. Spieler");
	disp1.drawFrame(500,260,220,40,2,Style::instance().color_Field);
	disp1.drawText(550,270,"vs. Bot");
	highlight_selected_game_mode();
}

short int Settings::buttonOnPagePressed(int posX,int posY)
{
	short int p = -1;
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,0);
	}
	
	//Button 1
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,1);
			if(p == -2)
			{
				Style::instance().changeActiveColorTheme(1);
			}
	}
	
	//Button 2
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,2);
			if(p == -2)
			{
				Style::instance().changeActiveColorTheme(0);
			}
	}
	
	//Button 3
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,3);
			if(p == -2)
			{
				Style::instance().changeActiveColorTheme(2);
			}
	}
	
	//Button 4
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,4);
			if(p == -2)
			{
				gameMode = 0;
			}
	}
	
	//Button 5
	if(p == -1)
	{
			p = Pages::instance().isPressed(posX,posY,iButtons_cor_S,5);
			if(p == -2)
			{
				gameMode = 1;
			}
	}
	//Return to default value
	if(p==-2)
	{
		p = -1;
		disp1.clear();
		Settings::instance().drawpage();
	}
	return p;
}

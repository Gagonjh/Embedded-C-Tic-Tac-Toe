//Author:     			Joshua Hahn  
//Projekt:    			Tic Tac Toe
//Datum:				  	15.06.2021

#include "./project_headers.h"

Pages::Pages() {
			//Menue& menueinstance = Menue::instance();
			changeColorMode(0);
				
}			
	
void Pages::changeColorMode(int cmode)
	{
		switch(cmode) 
			{
				case 0:
					iColor_backround = 0x530C;
					iColor_font = 0xEE02;
					iColor_boxes = 0x94F4;
				break;
				case 1:
					iColor_backround =0xFFFF;
					iColor_font = 0x067D;
					iColor_boxes = 0x85FA;
				break;
				default:
				break;
			}
	}

void Pages::drawpage(void)
	{
		#ifdef USE_GRAPHIC_DISPLAY
		disp1.clear();
    disp1.setBackColor(iColor_backround);
		siteHeader(0,0,24,16,"Wie bist du hier gelandet?");
		draw_button(80,200,60,200,15,1,iColor_boxes,0x067D,24,16,"Hi");
		#endif
	}

//Creates an box with a one line centerd text 
	//Todo: Onclick funktion for highlight
void Pages::siteHeader(short int box_offset_x,short int box_offset_y,short int font_hight,short int font_length,char* content)
	{
		//short int disp_hight = 480;
		short int disp_length = 800;
		short int box_hight =30;
		
		int titel_length = std::strlen(content);
		float titel_offset = disp_length/2-((titel_length/2)*(font_length));
		
		disp1.drawRectangle(box_offset_x,box_offset_y,disp_length,font_hight+box_hight,iColor_boxes);
		disp1.drawText(box_offset_x+titel_offset,box_offset_y+box_hight/2,titel_length,content);
		}
	
//Makes an Box with round corners
//ToDo: Fehler in der Endcoordinate,Umrandung wäre schön
void Pages::draw_button(short int box_offset_x,short int box_offset_y,short int button_hight,short int button_length,short int r,short int border,short int color,short int color_boarder,short int font_hight,short int font_length,char* content)
{
	short int d = r*2;
	
	if(border == 1)
	{
		draw_button(box_offset_x,box_offset_y,button_hight,button_length,r,0,color_boarder,color_boarder,font_hight,font_length,"");
		box_offset_x=box_offset_x+5;
		box_offset_y=box_offset_y+5;
		button_hight=button_hight-10;
		button_length=button_length-10;
		border = 0;
	}
	
	disp1.drawRectangle(box_offset_x+r,box_offset_y+r,button_length-d,button_hight-d,color);
	//Oben Links
	disp1.drawCircle(box_offset_x+r,box_offset_y+r,r,color);
	//Oben Rechts
	disp1.drawCircle(box_offset_x+button_length-r,box_offset_y+r,r,color);
	//Unten Links
	disp1.drawCircle(box_offset_x+r,box_offset_y+button_hight-r,r,color);
	//Unten Rechts
	disp1.drawCircle(box_offset_x+button_length-r,box_offset_y+button_hight-r,r,color);
	
	//Boxen
	disp1.drawRectangle(box_offset_x,box_offset_y+r,d,button_hight-d,color);
	disp1.drawRectangle(box_offset_x+button_length-d,box_offset_y+r,d,button_hight-d,color);
	disp1.drawRectangle(box_offset_x+r,box_offset_y,button_length-d,d,color);
	disp1.drawRectangle(box_offset_x+r,box_offset_y+button_hight-d,button_length-d,d,color);
	
	if(border == 0)
	{
		int content_length = std::strlen(content);
		float content_offset = button_length/2-((content_length/2)*(font_length));
		disp1.drawText(box_offset_x+content_offset,box_offset_y+button_hight/2-font_hight/2,content_length,content);
	}
	
	//disp1.drawText(box_offset_x+titel_offset,box_offset_y+box_hight/2,titel_length,cTitel);
	
	//Testfunktion: Zeigt die 4 Ecken des eigentlichen quadrates als referenz
	/*
	disp1.drawPixel(box_offset_x,box_offset_y,0xFFFF);
	disp1.drawPixel(box_offset_x+button_length,box_offset_y,0xFFFF);
	disp1.drawPixel(box_offset_x,box_offset_y+button_hight,0xFFFF);
	disp1.drawPixel(box_offset_x+button_length,box_offset_y+button_hight,0xFFFF);
	*/
}
void Pages::choose_page(short int page)
{
	switch(page) 
			{
				case 0:
					
				break;
				case 1:
					iColor_backround =0xFFFF;
					iColor_font = 0x067D;
					iColor_boxes = 0x85FA;
				break;
				default:
				drawpage();
				break;
			}
}

short int Pages::display_current_page(void)
{
	Menue::instance().drawpage();
	return 0;
}

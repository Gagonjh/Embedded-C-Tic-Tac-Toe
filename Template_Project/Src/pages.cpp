/*! 
 *  \author    Joshua Hahn
 *  \date      15.06.2021
 */


#include "./Project_Headers.h"

/*!
	\brief Private Konstruktor der Klasse.
	\details Initalisiert die Aktuelle Seite und die Letzte Seite. Damit Pages funktioniert müssen diese nicht gleich sein. Dies dient dazu das die seite nicht immer Refreshed wird.
*/
Pages::Pages() 
{
			//Menue& menueinstance = Menue::instance();
			page = 0;
			lastPage = -1;
}			

/*!
	\brief Gibt den Inhalt der Seite aus
	\details Setzt die Notwendigen Farbwerte in der EmbSysLib. Und Zeichnet die Button mit der Vererbten funktion aus Pages. Diese spezielle sollte nie erreicht werden und dient nur als Default.
	\sa Pages::draw_button()
*/
void Pages::drawpage(void)
	{
    disp1.setBackColor(Style::instance().color_Backround);
		disp1.setTextColor(Style::instance().color_Font);
		siteHeader(0,0,24,16,"Wie bist du hier gelandet?");
		draw_button(80,200,60,200,15,1,Style::instance().color_Boxes,0x067D,24,16,"Hi");
	}

/*!
	\brief Erstellt eine Kopfzeile mit Text
	\details Der Text ist Zentriert.
	\param Start koordinate X
	\param Start koordinate Y
	\param Höhe des Fonts
	\param Länge eines Zeichens des Fonts
	\param Text der Ausgegeben werden soll
*/
void Pages::siteHeader(short int box_offset_x,short int box_offset_y,short int font_height,short int font_length,char* content)
	{
		//short int disp_height = 480;
		short int disp_length = 800;
		short int box_height =30;
		
		int titel_length = std::strlen(content);
		float titel_offset = disp_length/2-((titel_length/2)*(font_length));
		
		disp1.drawRectangle(box_offset_x,box_offset_y,disp_length,font_height+box_height,Style::instance().color_Boxes);
		disp1.drawText(box_offset_x+titel_offset,box_offset_y+box_height/2,titel_length,content);
		}
	
/*!
	\brief Erstellt eine Kopfzeile mit Text
	\details Der Text ist Zentriert. Die Funktion kann rekursiv Arbeiten um einen Rand um den Button zu erstellen. Die Ecken sind abgerundet.
	\param Start koordinate X.
	\param Start koordinate Y.
	\param Höhe des Buttons.
	\param Länge des Buttons.
	\param Kurven Radius der Abgerundeten Ecken.
	\param Mit oder Ohne Rand 1 = mit.
	\param Farbe des Buttons.
	\param Farbe des Randes des Buttons.
	\param Höhe des Fonts
	\param Länge eines Zeichens des Fonts
	\param Text der Ausgegeben werden soll
*/
void Pages::draw_button(short int box_offset_x,short int box_offset_y,short int button_height,short int button_length,short int r,short int border,short int color,short int color_boarder,short int font_height,short int font_length,char* content)
{
	short int d = r*2;
	
	if(border == 1)
	{
		draw_button(box_offset_x,box_offset_y,button_height,button_length,r,0,color_boarder,color_boarder,font_height,font_length,"");
		box_offset_x=box_offset_x+5;
		box_offset_y=box_offset_y+5;
		button_height=button_height-10;
		button_length=button_length-10;
		border = 0;
	}
	
	disp1.drawRectangle(box_offset_x+r,box_offset_y+r,button_length-d,button_height-d,color);
	//Oben Links
	disp1.drawCircle(box_offset_x+r,box_offset_y+r,r,color);
	//Oben Rechts
	disp1.drawCircle(box_offset_x+button_length-r,box_offset_y+r,r,color);
	//Unten Links
	disp1.drawCircle(box_offset_x+r,box_offset_y+button_height-r,r,color);
	//Unten Rechts
	disp1.drawCircle(box_offset_x+button_length-r,box_offset_y+button_height-r,r,color);
	
	//Boxen
	disp1.drawRectangle(box_offset_x,box_offset_y+r,d,button_height-d,color);
	disp1.drawRectangle(box_offset_x+button_length-d,box_offset_y+r,d,button_height-d,color);
	disp1.drawRectangle(box_offset_x+r,box_offset_y,button_length-d,d,color);
	disp1.drawRectangle(box_offset_x+r,box_offset_y+button_height-d,button_length-d,d,color);
	
	if(border == 0)
	{
		int content_length = std::strlen(content);
		float content_offset = button_length/2-((content_length/2)*(font_length));
		disp1.drawText(box_offset_x+content_offset,box_offset_y+button_height/2-font_height/2,content_length,content);
	}
}

/*!
	\brief Kontrolliert die Seitenausgabe
	\details Prüft ob die Seite schon ausgegeben ist. Gibt die Touch Werte an die Aktuelle Seite aus zur auswertung muss deswegen zyklisch aufgerufen werden.
	\param X Koordinate der Touch Eingabe.
	\param Y Koordinate der Touch Eingabe.
*/
short int Pages::display_current_page(int posX,int posY)
{
	//Auswertung aller Button
	//Seite 0 Hautpmenü
	if(page == 0 && (posX >= 0 || posY >= 0 ))
	{
			page = Page_Menue::instance().buttonOnPagePressed(posX,posY);
	}
	//Seite 1 Spiel Einstellungen/Startseite 
	else if(page == 1 && (posX >= 0 || posY >= 0 ))
	{
			page = Page_Game::instance().buttonOnPagePressed(posX,posY);
	}
	//Seite 2 Spiel Einstellungen/Startseite 
	else if(page == 2 && (posX >= 0 || posY >= 0 ))
	{
			page = Page_History::instance().buttonOnPagePressed(posX,posY);
	}
	//Seite 3 Einstellungen 
	else if(page == 3 && (posX >= 0 || posY >= 0 ))
	{
			page = Page_Settings::instance().buttonOnPagePressed(posX,posY);
	}
	if(page == -1)	//Auffangen von Touches auf leerer fläche
	{
		page = lastPage;
	}
	//Ausgabe der aktuellen seite anhand ihrer Nummer
	if(page != lastPage)
	{
		disp1.clear();
		switch(page) 
			{
				case 0:
					Page_Menue::instance().drawpage();
				break;
				case 1:
					Page_Game::instance().drawpage();
				break;
				case 2:
				Page_History::instance().drawpage();

				break;
				case 3:
					Page_Settings::instance().drawpage();
				break;
				default:
				break;
			}
	}
	lastPage = page;
	return lastPage;
}

/*!
	\brief Prüft ob Fläche gedrückt ist.
	\details Bekommt die Buttons der Seite übergeben und prüft ob die Touch eingabe auf dieser Liegt. gibt dann den letzten Wert des Arrays zurück ([*][4]).
	\param X Koordinate der Touch Eingabe.
	\param Y Koordinate der Touch Eingabe.
	\param Button Array.
	\param Zu Prüfender Button.
*/
short int Pages::isPressed(int posX,int posY,short int buttons_cor[][5],int button)
{
	if((posX > buttons_cor[button][0] && posX < buttons_cor[button][1]) && (posY > buttons_cor[button][2] && posY < buttons_cor[button][3]))
	{
		return buttons_cor[button][4];
	}
	else
	{
		return -1;
	}
}

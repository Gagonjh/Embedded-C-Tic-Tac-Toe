#ifndef FIELD_H
#define FIELD_H


	//extern Field(cDevDisplayGraphic&);
	//extern void drawField();
	
	class Field
{
	public:
	cDevDisplayGraphic& disp1;
	
	Field(cDevDisplayGraphic&);
	void drawField();
};
#endif

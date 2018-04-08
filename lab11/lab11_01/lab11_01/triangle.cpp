#include "triangle.h"

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/08/18
*Modification Date:	04/08/18
*Purpose: Sets input to class triangle private base.
*/
void triangle::setBase(float input)
{
	base = input;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/08/18
*Modification Date:	04/08/18
*Purpose: Sets input to class triangle private height.
*/
void triangle::setHeight(float input)
{
	height = input;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/08/18
*Modification Date:	04/08/18
*Purpose: Return current triangle base - Only use after performing setBase().
*/
float triangle::getBase()
{
	return base;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/08/18
*Modification Date:	04/08/18
*Purpose: Return current triangle height - Only use after performing setHeight().
*/
float triangle::getHeight()
{
	return height;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/08/18
*Modification Date:	04/08/18
*Purpose: Return current triangle area - Only use after performing computeArea().
*/
float triangle::getArea()
{
	return area;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/08/18
*Modification Date:	04/08/18
*Purpose: Calculate current triangle area.
*/
float triangle::computeArea()
{
	area = base * height / 2.0;
	return area;
}

triangle::triangle()
{
}

triangle::~triangle()
{
}

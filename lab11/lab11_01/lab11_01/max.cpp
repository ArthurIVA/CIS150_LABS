#include "max.h"
#include "triangle.h"
/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/08/18
*Modification Date:	04/08/18
*Purpose: Take in array of object triangle with size and determine largest of the set.
*/
int maxTriangle(triangle arrTri[], int size)
{
	int indexLargest = 0;
	float largest = arrTri[0].getArea();

	for (int i = 1; i < size; i++)
	{
		if (arrTri[i].getArea() > largest)
		{
			largest = arrTri[i].getArea();
			indexLargest = i;
		}
	}

	return indexLargest;
}

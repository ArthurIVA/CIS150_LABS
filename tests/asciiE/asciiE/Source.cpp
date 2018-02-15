//Program that prints large format 'E' with ASCII symbols - asterisks
/*

	**********
	*
	*
	*
	**********
	*
	*
	*
	**********

*/
#include <iostream>

using namespace std;

void drawHorizontal() // display the horizontal line of 10 asterisks
{
	for (int i = 0; i < 10; i++)
	{
		cout << "*";
	}
	cout << endl;
}

void drawVertical() // displays the vertical line of 4 asterisks
{
	for (int i = 0; i < 3; i++)
	{
		cout << "*" << endl;
	}
}

/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		02/15/18
*Modification Date:	02/15/18
*Purpose: Call available functions used in generating large format 'E'.
*/

int main()
{
	cout << endl;

	drawHorizontal();
	drawVertical();
	drawHorizontal();
	drawVertical();
	drawHorizontal();

	cout << endl;

	system("pause");
	return 0;
}
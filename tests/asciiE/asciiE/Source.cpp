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

// Function prototypes go here - BEFORE the main
void drawHorizontal(char userChar); //userChar does not need to be identified here, just type char.
void drawVertical(char userChar);  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		02/15/18
*Modification Date:	02/15/18
*Purpose: Call available functions used in generating large format 'E'.
*/

int main()
{

	char userChar;

	cout << endl;

	cout << "Please enter the basic character to be displayed to make a giant 'E' : ";
	cin >> userChar;

	drawHorizontal(userChar);
	drawVertical(userChar);
	drawHorizontal(userChar);
	drawVertical(userChar);
	drawHorizontal(userChar);

	cout << endl;

	system("pause");
	return 0;
}

/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		02/15/18
*Modification Date:	02/15/18
*Purpose: Display the horizontal line of 10 asterisks
*/

void drawHorizontal(char userChar)
{
	for (int i = 0; i < 10; i++)
	{
		cout << userChar;
	}
	cout << endl;
}

/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		02/15/18
*Modification Date:	02/15/18
*Purpose: Displays the vertical line of 4 asterisks
*/ 

void drawVertical(char userChar)
{
	for (int i = 0; i < 3; i++)
	{
		cout << userChar << endl;
	}
}
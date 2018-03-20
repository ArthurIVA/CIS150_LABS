/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		02/12/18
*Modification Date:	02/12/18
*Purpose: Print right triangle with user determined character and height.
*/

#include <iostream>

using namespace std;

int main()
{
	int userH = 0; //user inputted Height
	char userC = 0; //user inputted Character

	cout << "This program will print a right triangle with your desired character and height" << endl;
	cout << endl << "Please enter a character: "; 
	cin >> userC;
	cout << endl << "Please ender a height: ";
	cin >> userH;

	for (int count = 0; count <= userH; count++) //loop regarding height
	{
		for (int userW = 0; userW < count; userW++) //loop regarding width at each line
		{
			cout << userC;
		}
		cout << endl;
    }
	
	cout << endl;

	system("pause");
	return 0;

}
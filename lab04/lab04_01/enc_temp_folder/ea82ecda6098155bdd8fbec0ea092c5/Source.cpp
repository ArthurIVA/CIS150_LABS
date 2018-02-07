/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		02/06/18
*Modification Date:	02/06/18
*Purpose: Get temp, GIVE JUGDEMENT!
*/

#include <iostream>

using namespace std;

int main()
{
	int tempF; //Would use float if the threshhold needed to be more precise.
			   // i.e. inputs like .3 will round down to 0, therefore technically in wrong category.
	cout << "Please enter the current temperature (F) : ";
	cin >> tempF;
	cout << endl;

	if (tempF > 90)
	{
		cout << "Go swimming.";
	}
	else if (tempF > 80)
	{
		cout << "Turn on air conditioning.";
	}
	else if (tempF > 70)
	{
		cout << "Do nothing.";
	}
	else if (tempF > 55)
	{
		cout << "Turn on heat.";
	}
	else if (tempF > 30)
	{
		cout << "Wear a heavy coat.";
	}
	else if (tempF > 0 )
	{
		cout << "Wear gloves";
	}
	else if (tempF <= 0)
	{
		cout << "Stay inside, make a fire.";
	}

	cout << endl << endl;

	system("pause");
	return 0;
}
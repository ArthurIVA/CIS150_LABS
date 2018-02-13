/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		02/06/18
*Modification Date:	02/06/18
*Purpose: Add user inputted integers until a '0' is entered.
*/

//Initial code for addition provided by lab_0404 in git/CIS150_LABS/lab04/lab04_04/lab04_04/Source.cpp - Lines 32-46

#include <iostream>

using namespace std;

int main()
{
	int total = 0;
	int numIn = 1;

	cout << "You are using a While Loop to perform addition" << endl;
	cout << "To finish adding and exit the loop input '0' " << endl << endl;

	while (numIn != 0)
	{
		cout << "Enter a value or 0 to quit: ";
		cin >> numIn;

		while (!cin) //Has issues handling inputs with operators, will still add values even though error is thrown.
		{
			cout << "That was not an integer" << endl << "Enter a value or 0 to quit: ";
			cin.clear(); //clear input
			cin.ignore();
			cin >> numIn; //try again
		}

		total += numIn; //accumulate
	
	}

	cout << endl << "The total is " << total << endl << endl;

	system("pause");
	return 0;
}
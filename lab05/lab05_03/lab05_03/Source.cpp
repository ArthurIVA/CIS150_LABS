/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		02/19/18
*Modification Date:	02/19/18
*Purpose: Print menu allowing two integers to be added or multiplied using SWITCH and DO WHILE.
*/

#include <iostream>

using namespace std;

void menu(); //Function prototype for initial menu offered to user.

int main()
{
	int choice = 0;
	int numOne = 0;
	int numTwo = 0;
	int total = 0;

	menu(); //Calls menu as defined below main()

	while (choice != 4)
	{
		do
		{
			cout << endl << "Please Enter your choice (1-4): ";
			cin >> choice;

			if (!(choice >= 1 && choice <= 4))
			{
				cout << endl << "Invalid Input, Please Try Again: ";
			}
		} while (!(choice >= 1 && choice <= 4));

		switch (choice)
		{
		case 1: //Entering two integer values to use within the other cases.
			cout << endl << "Value Number One: ";
			cin >> numOne;
			cout << "Value Number Two: ";
			cin >> numTwo;
			break;
		case 2: //Adds both values and prints that expression.
			total = numOne + numTwo;
			cout << endl << numOne << " + " << numTwo << " = " << total << endl;
			break;
		case 3: //Multiply both values and prints that expression.
			total = numOne * numTwo;
			cout << endl << numOne << " * " << numTwo << " = " << total << endl;
			break;
		default:
			cout << endl;
			system("pause");
			return 0;
			break;
		}
	}
}

void menu() //Allow modularity of menu. Also to test function prototypes as discussed in class.
{
	cout << "1. Enter Two Integer Values" << endl
		<< "2. Add the two values" << endl
		<< "3. Multiply the two values" << endl
		<< "4. Exit" << endl;
}
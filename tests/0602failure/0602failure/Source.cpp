/*
*Author: Arthur Aigeltinger IV
*Creation Date: 02/20/18
*Modification Date:	02/20/18
*Purpose: Print menu that offers finding the minimum and maximum of two integers.
*/

#include <iostream>
#include <cctype>
#include <cctype>

using namespace std;

//FUNCTION PROTOTYPES
void menu();		//Calls menu to be printed.
void errorMessage();//Calls error message regarding user input.
void exitMessage(); //Calls exit message.
void minInt();		//Determines MAX of two local integers
void maxInt();		//Determines MIN of two local integers

					//Initialize global variables for use within minInt() and maxInt().
int userNum1;
int userNum2;

int main()
{
	char choice = 0;

	menu(); //Draw initial menu.

	do //Decision stage
	{
		cout << endl << "Please select an operation: ";
		cin >> choice;
		choice = toupper(choice); //Apply toupper() of <cctype> to handle lowercases.

		switch (choice)
		{
		case 'A':
		{
			maxInt();
			choice = 0; //Reset choice to return to decision stage.
			break;
		}
		case 'B':
		{
			minInt();
			choice = 0; //Reset choice to return to decision stage.
			break;
		}
		case 'C':
		{
			exitMessage();
			break; //Will skip over return to decision stage and exit loop.
		}
		default:
		{
			errorMessage();
			choice = 0; //Reset choice to return to decision stage.
		}
		}

	} while (choice != 'C');

	system("pause");
	return 0;
}

/*
*Function Author: PROVIDED - Better Formatting: Arthur Aigeltinger IV
*Creation Date: 02/20/18
*Modification Date:	02/20/18
*Purpose: Provides template for initial menu.
*/
void menu()
{
	cout << "-----------------------------------------------------------" << endl
		<< "                          Welcome                          " << endl
		<< "-----------------------------------------------------------" << endl
		<< "            You may choose one of the following            " << endl
		<< endl
		<< "(A) Maximum of two integers" << endl
		<< "(B) Minimum of two integers" << endl
		<< "(C) Quit" << endl
		<< endl
		<< "-----------------------------------------------------------" << endl;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date: 02/20/18
*Modification Date:	02/20/18
*Purpose: Informs user of invalid input.
*/
void errorMessage()
{
	cout << "Invalid Entry, Try Again." << endl;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date: 02/20/18
*Modification Date:	02/20/18
*Purpose: Prints exit message
*/
void exitMessage()
{
	cout << endl << "Thank you for using this program!" << endl;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date: 02/20/18
*Modification Date:	02/20/18
*Purpose: Finds max of two integers
*/
void maxInt()
{
	cout << endl << "Please provide the first number: ";
	cin >> userNum1;
	cout << "Please provide the second number: ";
	cin >> userNum2;

	if (userNum1 > userNum2)
	{
		cout << endl << "The maximum of " << userNum1 << " and " << userNum2 << " is " << userNum1 << endl;
	}
	else
	{
		cout << endl << "The maximum of " << userNum1 << " and " << userNum2 << " is " << userNum2 << endl;
	}
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date: 02/20/18
*Modification Date:	02/20/18
*Purpose: Finds min of two integers
*/
void minInt()
{
	cout << endl << "Please provide the first number: ";
	cin >> userNum1;
	cout << "Please provide the second number: ";
	cin >> userNum2;

	if (userNum1 < userNum2)
	{
		cout << endl << "The minimum of " << userNum1 << " and " << userNum2 << " is " << userNum1 << endl;
	}
	else
	{
		cout << endl << "The minimum of " << userNum1 << " and " << userNum2 << " is " << userNum2 << endl;
	}
}
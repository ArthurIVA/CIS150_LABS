/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		01/23/18
*Modification Date:	01/23/18
*Purpose: Prompt user for two integers and display the sum of the two integers.
*/

#include <iostream>
using namespace std;

int main()
{
	int firstInt;
	int secondInt;
	int totalSolution;

	cout << "This program will ask you to enter two integer values, then they will be added together and returned." << endl << endl;

	cout << "Please enter your first integer: ";
	cin >> firstInt; // assigns first integer value
	cout << endl; // extra space for formatting

	cout << "Please enter your second integer: ";
	cin >> secondInt; // assigns second integer value
	cout << endl; // extra space for formatting

	totalSolution = firstInt + secondInt; // assign total from two integers (does math)

	cout << "The sum of the two integers is: " << totalSolution << endl << endl; // print response with solution.

	system("pause");
	return 0;
	
}
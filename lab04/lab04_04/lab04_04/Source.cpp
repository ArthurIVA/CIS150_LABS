/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		02/11/18
*Modification Date:	02/11/18
*Purpose: 
*/

#include <iostream>
#include <cctype> //Help with user loop selection by handling UPPER case inputs.
#include <ctime> //Create seed based on RTC for number of inputs.

using namespace std;

void forAdd(int num) 
{
	int total = 0;
	int numIn = 0;

	cout << "You are using the For Loop addition" << endl << endl;

	for (int count = 0; count < num; count++)
	{
		cout << "Number " << count + 1 << ": ";
		cin >> numIn;
		total += numIn;
	}

	cout << endl << "The total of your " << num << " numbers is " << total << endl << endl;
}

void whileAdd(int num)
{
	int total = 0;
	int numIn = 0;
	int count = 0;

	cout << "You are using the While Loop addition" << endl << endl;

	while (count < num)
	{
		cout << "Number " << count + 1 << ": ";
		cin >> numIn;
		total += numIn;
		count++;
	}

	cout << endl << "The total of your " << num << " numbers is " << total << endl << endl;
}

void doWhileAdd(int num)
{
	int total = 0;
	int numIn = 0;
	int count = 0;

	cout << "You are using the Do While Loop addition" << endl << endl;

	do
	{
		cout << "Number " << count + 1 << ": ";
		cin >> numIn;
		total += numIn;
		count++;
	} 

	while (count < num);

	cout << endl << "The total of your " << num << " numbers is " << total << endl << endl;
}

int main()
{
	srand(time(nullptr)); //null pointer to use base time as seed for random number gen below.
	int intsToAdd = (rand() % 11) + 5;
	char userSelect = 0;

	cout << "You will be adding " << intsToAdd << " integers together." << endl << endl << "What kind of loop would you like to use to do this?" << endl << endl;
	cout << "(f)or loop" << endl;
	cout << "(w)hile loop" << endl;
	cout << "(d)o while loop" << endl; //Formatting

	while (userSelect != 'f' && userSelect != 'F' && userSelect != 'w' && userSelect != 'W' && userSelect != 'd' && userSelect != 'D') //Exception handling for cases other than provided.
	{
		cout << endl << "Choice Letter: ";
		cin >> userSelect; 
	}

	if (userSelect == 'f' || userSelect == 'F') //Select for loop function
	{
		forAdd(intsToAdd);
	}
	else if (userSelect == 'w' || userSelect == 'W') //Select while loop function
	{
		whileAdd(intsToAdd);
	}
	else if (userSelect == 'd' || userSelect == 'D') //Select do while loop function
	{
		doWhileAdd(intsToAdd);
	}
	
	system("pause");
	return 0;

}
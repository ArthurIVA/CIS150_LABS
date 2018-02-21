/*
*Author:PROVIDED | Modified By:Arthur Aigeltinger IV
*Creation Date:		02/20/18
*Modification Date:	02/20/18
*Purpose: 
*/


#include <iostream>

using namespace std;

int addition(int, int);
int subtraction(int, int);
void directions();
void printResult(int, int, int, char);

int main()
{
	int x, y, r;

	directions();

	cout << "Please enter the first integer: ";
	cin >> x;
	cout << "Please enter the second integer: ";
	cin >> y;

	r = addition(x, y);
	printResult(x, y, r, '+');

	r = subtraction(x, y);
	printResult(x, y, r, '-');

	system("pause");
	return 0;
}

int addition(int a, int b)
{
	int r;
	r = a + b;
	return r;
}

int subtraction(int a, int b)
{
	int r;
	r = a - b;
	return r;
}

void directions()
{
	cout << "*******************************************************************************" << endl
		 << "Hello!" << endl
		 << "This Program asks the user for two integers, then prints the sum and difference" << endl
		 << "*******************************************************************************" << endl << endl;
}

void printResult(int a, int b, int result, char operation)
{
	cout << a << " " << operation << " " << b << " = " << result << endl;
}

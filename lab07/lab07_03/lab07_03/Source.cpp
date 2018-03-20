/*
*Author: Arthur Aigeltinger IV
*Creation Date:		03/13/18
*Modification Date:	03/13/18
*Purpose: Provide example of passing values by reference pointer into and out of multiple functions. With corrected syntax.
*/

#include <iostream>

using namespace std;

//Function Prototypes
void doIt(int&, int);
void doIt2(int, int&);
void doIt3(int&, int&);

int main()
{
	int num1, num2;

	cout << "Please enter integers for num1 and num2" << endl;
	cout << "num1: ";
	cin >> num1;
	cout << "num2: ";
	cin >> num2;

	doIt(num1, num2); //Passes num1 by reference, changing the value in main()
	cout << endl << num1 << " " << num2;

	doIt2(num1, num2); //Passes num2 by reference, changing the value in main()
	cout << endl << num1 << " " << num2;

	doIt3(num1, num2); //Passes num1 and num2 by reference, changing the values in main()
	cout << endl << num1 << " " << num2;

	cout << endl;

	system("pause");
	return 0;
}

void doIt(int& a, int b) //Passes num1 by reference, changing the value in main()
{
	a = a + 5;
	b = b + 5;
}

void doIt2(int a, int& b) //Passes num2 by reference, changing the value in main()
{
	a += 5;
	b += 5;
}

void doIt3(int& a, int& b) //Passes num1 and num 2 by reference, changing the values in main()
{
	a = a + 5;
	b += 5;
}

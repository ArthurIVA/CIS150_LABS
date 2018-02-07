/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		01/30/18
*Modification Date:	02/05/18
*Purpose: Perform quadratic equation with three "double" inputs.
*/

#include <iostream> 
#include <cmath>

using namespace std;

int main()
{

	double a, b, c, root1, root2;


	cout << "Please input three numbers to input into a quadratic equation - ax^2 + bx + c = 0" << endl << "This program will then perform the quadratic formula to find the roots of your equation" << endl;
	cout << endl << "Input a: ";
	cin >> a;
	cout << endl << "Input b: ";
	cin >> b;
	cout << endl << "Input c: ";
	cin >> c;

	if (a == 0)
	{
		root1 = -c / b;
		cout << endl << "This is a binomial" << endl << "The single root = " << root1 << endl << endl;

	}
	else if ( 0 > ((pow(b,2) - (4 * a * c))))
	{
		cout <<endl << "No real root" << endl << endl;		
	}
	else
	{
		root1 = ((sqrt((pow(b, 2) - (4 * a * c))) - b) / (2 * a));
		root2 = ((-1 * (sqrt((pow(b, 2) - (4 * a * c)))) - b) / (2 * a));
		cout << "Root 1 = " << root1 << endl << "Root 2 = " << root2 << endl;
	}

	system("pause");
	return 0;

}
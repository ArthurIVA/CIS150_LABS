/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		01/23/18
*Modification Date:	01/23/18
*Purpose: Takes number of different coins as input, computes, and prints total dollar value.
*/


#include <iostream>
using namespace std;

const double PENNY_VALUE = 0.01;
const double NICKEL_VALUE = 0.05;
const double DIME_VALUE = 0.10;
const double QUARTER_VALUE = 0.25;

int main()
{
	// declaring variables corresponding to the number of different types of coins
	int pennies, nickels, dimes, quarters, dollars;
	double total = 0.0;

	cout << "How many pennies do you have? ";
	cin >> pennies;
	// update total now
	total = total + pennies * PENNY_VALUE;
	cout << "Current total is " << total << endl;

		cout << "How many nickels do you have? ";
	cin >> nickels;
	// update total now
	total = total + nickels * NICKEL_VALUE;
	cout << "Current total is " << total << endl;

	cout << "How many dimes do you have? ";
	cin >> dimes;
	// update total now
	total = total + dimes * DIME_VALUE;
	cout << "Current total is " << total << endl;

	cout << "How many quarters do you have? ";
	cin >> quarters;
	// update total now
	total = total + quarters * QUARTER_VALUE;
	cout << "Current total is " << total << endl;

	cout << "How many dollar coins do you have? ";
	cin >> dollars;
	// update total now
	total = total + dollars;
	cout << "Current total is " << total << endl;

	// Total value of the coins
	cout << "Total value = " << total << "\n";

	system("pause");

	return 0;
}

/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		01/30/18
*Modification Date:	01/30/18
*Purpose: Calculate weekly pay for a worker, including overtime.
*/

#include <iostream> 

using namespace std;

int main()
{
	double hoursWorked, overtime, payPerHour, totalPay;

	cout << "Please input hours worked: ";
	cin >> hoursWorked;

	cout << "Please input hourly pay rate: ";
	cin >> payPerHour;

	if (hoursWorked > 40)
	{
		overtime = hoursWorked - 40;
		totalPay = ((hoursWorked - overtime) * payPerHour) + (overtime * (payPerHour * 1.5));
	}
	else
	{
		totalPay = payPerHour * hoursWorked;
	}

	cout << endl << "Gross pay for the week is $" << totalPay << endl;
	
	system("pause");
	return 0;

}
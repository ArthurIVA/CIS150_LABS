/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		01/30/18
*Modification Date:	01/30/18
*Purpose: Allow testing of manual debug functions within an 'if' statement using F9 and F10
*/

#include <iostream>

using namespace std;

int main() {
	int x, y;

	cout << "Please enter an integer value : ";
	cin >> x;

	if (x >= 15)
	{
		x++;
		y = x + x - 7;
	}
	else
	{
		x = x * 2;
		y = x * x + 7;
	}

	cout << "x = " << x << " y = " << y << endl;

	system("pause");
	return 0;
}

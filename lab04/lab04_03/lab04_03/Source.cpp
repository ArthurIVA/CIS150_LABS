/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		02/07/18
*Modification Date:	02/11/18
*Purpose: Add and Iterate in different orders with ++ operators.
*/

#include <iostream>

using namespace std;

int main()
{

	int w = 20, x = 20;
	int y = 5, z = 5;

	y = y + (++x);
	z = z + (w++);

	cout << "x=" << x << " and y=" << y << endl;
	cout << "w=" << w << "and z=" << z << endl;


	system("pause");
	return 0;

}
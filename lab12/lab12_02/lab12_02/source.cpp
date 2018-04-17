/*
*Author: Arthur Aigeltinger IV
*Creation Date:		04/16/18
*Modification Date:	04/16/18
*Purpose: Further understanding of classes via exercise in handling fractions.
*/

#include "fraction.h"

int main()
{
	fraction f1(1, 5);
	fraction f2(2, 5);
	//fraction f3 = f1 * f2;
	//f3.simplify();
	//std::cout << (f1 < f2);
	//f3.print();

	f1 = f2;
	f1.print();

	system("PAUSE");
}
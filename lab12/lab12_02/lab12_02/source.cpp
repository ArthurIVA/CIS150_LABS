/*
*Author: Arthur Aigeltinger IV
*Creation Date:		04/16/18
*Modification Date:	04/16/18
*Purpose: Further understanding of classes via exercise in handling fractions.
*/

#include "fraction.h"

int main()
{
	//Define two fractions.
	fraction f1(1, 5);
	fraction f2(4, 10);
	
	f1.print();
	std::cout << std::endl;
	f2.print();
	std::cout << std::endl << std::endl;

	//Test ADDITION operator overload.
	/*
	fraction f3 = f2 + f1;
	f3.simplify();
	f3.print();
	*/
	
	
	//Test SUBTRACTION operator overload.
	/*
	fraction f3 = f1 - f2;
	f3.simplify();
	f3.print();
	*/

	
	//Test MULTIPLICATION operator overload.
	/*
	fraction f3 = f1 * f2;
	f3.simplify();
	f3.print();
	*/

	//Test LESS THAN operator overload.
	//std::cout << (f1 < f2);

	//Test GREATER THAN operator overload.
	//std::cout << (f1 > f2);

	//Test = SET operator overload.
	std::cout << std::endl;
	/*
	fraction f3 = f1;
	f3.simplify();
	f3.print();
	*/

	std::cout << std::endl;
	system("PAUSE");
	return 0;
}
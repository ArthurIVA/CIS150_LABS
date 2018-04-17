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
	
	//Test ADDITION operator overload.
	fraction f3 = f2 + f1;
	f3.simplify();
	f3.print();
	std::cout << std::endl;
	f3 = f1;
	f3.simplify();
	f3.print();
	
	/*
	//Test SUBTRACTION operator overload.
	fraction f3 = f1 - f2;
	f3.simplify();
	f3.print();
	*/

	/*
	//Test MULTIPLICATION operator overload.
	fraction f3 = f1 * f2;
	f3.simplify();
	f3.print();
	*/

	//Test LESS THAN operator overload.
	//std::cout << std::endl << (f1 < f2) << std::endl;

	//Test GREATER THAN operator overload.
	//std::cout << (f1 > f2) << std::endl;

	//OPERATOR NOT FUNCTIONING CORRECTLY
	//Test = SET operator overload.
	/*
	f1 = f2;
	f1.simplify();
	f1.print();
	*/

	std::cout << std::endl;
	system("PAUSE");
	return 0;
}
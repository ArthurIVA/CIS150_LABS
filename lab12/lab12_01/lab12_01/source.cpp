/*
*Author: Arthur Aigeltinger IV
*Creation Date:		04/16/18
*Modification Date:	04/16/18
*Purpose: Prove I can use recursion in it's most basic form!
*/

#include <iostream>

//Function Prototypes
void recursiveCountDown(int);


int main()
{
	int userIn;

	std::cout << "Please enter an integer between 0-100: ";
	std::cin >> userIn;
	std::cout << std::endl;

	//foo(bar);
	recursiveCountDown(userIn);

	std::cout << std::endl;

	system("pause");
	return 0;
}

void recursiveCountDown(int input)
{
	if (input < 0 || input > 100)
	{
		std::cout << "No need to be recursive... You can't follow directions! :D" << std::endl;
	}
	else if (input >= 1 && input <= 100)
	{
		std::cout << input << std::endl;
		recursiveCountDown(input - 1);
	}
	if (input == 0)
	{
		std::cout << "I've learned how to use recursion!" << std::endl;
	}
}
#include <iostream>

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/15/18
Modification Date:	04/15/18
Purpose: Provide template for menu using string literals within std::cout statements.
*/
void drawMenu()
{
	std::cout << "------------------------ Menu ---------------------------" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "\t 1. Display Seat Chart" << std::endl;
	std::cout << "\t 2. Reserve Seat" << std::endl;
	std::cout << "\t 3. Cancel Reservation" << std::endl;
	std::cout << "\t 4. Save Seat Chart to File" << std::endl;
	std::cout << "\t 5. Statistics" << std::endl;
	std::cout << "\t 6. Help" << std::endl;
	std::cout << "\t 7. Quit" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
}

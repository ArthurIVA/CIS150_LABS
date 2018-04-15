#include <iomanip>
#include <iostream>

const int NCOLS = 4;

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/10/18
Modification Date:	04/15/18
Purpose: Take in a given seat array and then print it to the console.
*/
void printSeatChart(char seatArray[][NCOLS], int NROWS)
{
	//Outer loop iterates through rows with formatting.
	for (int i = 0; i < NROWS; i++)
	{
		std::cout << std::setw(3) << std::left << i + 1;

		//Inner loop iterates through sub-columns of seat rows.
		for (int j = 0; j < NCOLS; j++)
		{
			std::cout << seatArray[i][j];
		}
		std::cout << std::endl;
	}
}

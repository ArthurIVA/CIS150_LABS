#include <fstream>

const int NCOLS = 4;
/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/10/18
Modification Date:	04/15/18
Purpose: Take in a given array and an input stream to fill it for manipulation.
*/
void loadSeatChart(char seatArray[][NCOLS], int NROWS, std::ifstream& in)
{
	//Variable exists to deal with integers within the seat chart that character array cannot handle.
	//Possibility of struct to make this unnecessary?
	//Determined that since integers in this case are always finite and in order with array that this will be left un-changed.
	int numCache;

	//Continue until end of file.
	while (!in.eof())
	{
		//Outer loop iterates through rows and discards integer into numCache.
		for (int i = 0; i < NROWS; i++)

		{
			in >> numCache;

			//Inner loop iterates through sub-columns of seat rows.
			for (int j = 0; j < NCOLS; j++)
			{
				in >> seatArray[i][j];
			}
		}
	}
}
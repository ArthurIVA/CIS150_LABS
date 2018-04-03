/*
*Author: Arthur Aigeltinger IV
*Creation Date:		04/02/18
*Modification Date:	04/03/18
*Purpose: Perform given functions on a student data set in a text file, print outputs in console and file.
*/

#include <iostream>

using namespace std;

//Global Constants
const int NROWS = 4;
const int NCOLS = 4;

//Function Prototypes
int sumElements(float [][NCOLS], int, int);
float avgElements(float, int);


int main()
{
	int elements = NROWS * NCOLS;

	float box[NROWS][NCOLS] = 
	{ 
	{ 11,8,0,-4 },
	{ 74,5,13,42 },
	{ 29,-7,45,4 },
	{ 100,23,-3,61 } 
	};

	cout << "The total of all elements in the array is " << sumElements(box, NROWS, NCOLS) << endl;
	cout << "The avarage of all elements in the array is " << avgElements(sumElements(box, NROWS, NCOLS), elements) << endl;

	system("pause");
	return 0;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/03/18
*Modification Date:	04/03/18
*Purpose: Take in 2D array and add up all values inside it.
*/
int sumElements(float box[][NCOLS], int rows, int cols)
{
	int sum = 0;

	//Iterate row counter
	for (int i = 0; i < rows; i++)
	{
		//Iterate column counter
		for (int j = 0; j < cols; j++)
		{
			sum += box[i][j];
		}
	}
	return sum;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/03/18
*Modification Date:	04/03/18
*Purpose: Calculate average of all elements in 2D array. 
*/
float avgElements(float total, int elements)
{
	return total / elements;
}

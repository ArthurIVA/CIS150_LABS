/*
*Author: Arthur Aigeltinger IV
*Creation Date:		03/26/18
*Modification Date:	03/26/18
*Purpose: Perform functions with arrays being passed as parameters.
*/

#include <iostream>

using namespace std;

//Function Prototypes
double calculatePosAvg(int[], int);
int calculateSum(int[], int);
int returnMin(int[], int);
int returnMax(int[], int);

int main()
{
	const int SIZE = 20;
	int values[SIZE] = { 0, 23, 34, -7, 110, 42, -350, 424, 25, 99, 10, 05, 50, -5, 1, 200, -350, 437, 25, 147 };

	cout << "The sum of the array is " << calculateSum(values, SIZE) << endl;
	cout << "The average of all positive numbers in the array is " << calculatePosAvg(values, SIZE) << endl;
	cout << "The lowest number in the array is " << returnMin(values, SIZE) << endl;
	cout << "The highest number in the array is " << returnMax(values, SIZE) << endl;

	system("pause");
	return 0;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/26/18
*Modification Date:	03/26/18
*Purpose: Take in array and it's size and then return the sum of all values in said array.
*/
int calculateSum(int a[], int size)
{
	//Initialize total as 0.
	int total = 0;

	for (int i = 0; i < size; i++)
	{
		total += a[i];
	}
	return total;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/26/18
*Modification Date:	03/26/18
*Purpose: Take in array and it's size and then return the average of all positive values in said array.
*/
double calculatePosAvg(int a[], int size)
{
	//Initialize total as 0.
	double total = 0;
	int posInts = 0;

	for (int i = 0; i < size; i++)
	{
		//Check that int and position 'i' is a positive value.
		if (a[i] > 0)
		{
			total += a[i];
			posInts++;
		}
	}
	return total / posInts;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/26/18
*Modification Date:	03/26/18
*Purpose: Take in an array and it's size and then return minimum value in said array.
*/
int returnMin(int a[], int size)
{
	//Initialize min as first value in array.
	int min = a[0];

	for (int i = 1; i < size; i++)
	{
		//Compare next value in array to current minimum.
		if (min > a[i])
		{
			//Assign min value if smaller.
			min = a[i];
		}
	}
	return min;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/26/18
*Modification Date:	03/26/18
*Purpose: Take in an array and it's size and then return maximum value in said array.
*/
int returnMax(int a[], int size)
{
	//Initialize min as first value in array.
	int max = a[0];

	for (int i = 1; i < size; i++)
	{
		//Compare next value in array to current minimum.
		if (max < a[i])
		{
			//Assign min value if smaller.
			max = a[i];
		}
	}
	return max;
}
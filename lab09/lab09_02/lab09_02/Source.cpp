/*
*Author: Arthur Aigeltinger IV
*Creation Date:		03/26/18
*Modification Date:	03/26/18
*Purpose: Perform functions with vectors being passed as parameters.
*/

#include <iostream>
#include <vector>

using namespace std;

//Function Prototypes
double calculatePosAvg(vector <int>);
int calculateSum(vector <int>);
int returnMin(vector <int>);
int returnMax(vector <int>);

int main()
{
	vector <int> values = { 0, 23, 34, -7, 110, 42, -350, 424, 25, 99, 10, 05, 50, -5, 1, 200, -350, 437, 25, 147 };

	cout << "The sum of the array is " << calculateSum(values) << endl;
	cout << "The average of all positive numbers in the array is " << calculatePosAvg(values) << endl;
	cout << "The lowest number in the array is " << returnMin(values) << endl;
	cout << "The highest number in the array is " << returnMax(values) << endl;

	system("pause");
	return 0;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/26/18
*Modification Date:	03/26/18
*Purpose: Take in vector and then return the sum of all values in said vector.
*/
int calculateSum(vector <int> arr)
{
	//Initialize total as 0.
	int total = 0;

	for (unsigned int i = 0; i < arr.size(); i++)
	{
		total += arr.at(i);
	}
	return total;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/26/18
*Modification Date:	03/26/18
*Purpose: Take in a vector then return the average of all positive values in said vector.
*/
double calculatePosAvg(vector <int> arr)
{
	//Initialize total as 0.
	double total = 0;
	int posInts = 0;

	for (unsigned int i = 0; i < arr.size(); i++)
	{
		//Check that int and position 'i' is a positive value.
		if (arr.at(i) > 0)
		{
			total += arr[i];
			posInts++;
		}
	}
	return total / posInts;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/26/18
*Modification Date:	03/26/18
*Purpose: Take in vector then return minimum value in said vector.
*/
int returnMin(vector <int> arr)
{
	//Initialize min as first value in vector.
	int min = arr.at(0);

	for (unsigned int i = 1; i < arr.size(); i++)
	{
		//Compare next value in vector to current minimum.
		if (min > arr.at(i))
		{
			//Assign min value if smaller.
			min = arr.at(i);
		}
	}
	return min;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/26/18
*Modification Date:	03/26/18
*Purpose: Take in vector then return maximum value in said vector.
*/
int returnMax(vector <int> arr)
{
	//Initialize min as first value in vector.
	int max = arr.at(0);

	for (unsigned int i = 1; i < arr.size(); i++)
	{
		//Compare next value in vector to current minimum.
		if (max < arr.at(i))
		{
			//Assign min value if smaller.
			max = arr.at(i);
		}
	}
	return max;
}
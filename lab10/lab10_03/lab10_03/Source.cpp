/*
*Author: Arthur Aigeltinger IV
*Creation Date:		04/03/18
*Modification Date:	04/03/18
*Purpose: Search 2D array for user input value.
*/

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

//Global Constants
const int NROWS = 6;
const int NCOLS = 6;

//Function Prototypes
int getUserInt();
int search(int[][NCOLS], int, int, int, int&, int&);
double verifyNum(string, bool);

int main()
{
	int userInt = 0;
	int indexR = 0;
	int indexC = 0;

	int box[NROWS][NCOLS] =
	{
	{ 11,  8,  0, -4, 65, 52 },
	{ 74,  5, 13, 42, 54, 22 },
	{ 29, -7, 45,  4, 24, 14 },
	{100, 23, -3, 61, 64,  6 },
	{ 43,  9, 12, 72,  2, 32 },
	{ 99,  7, 96, 41, 51, 28 }
	};

	userInt = getUserInt();

	if (search(box, NROWS, NCOLS, userInt, indexR, indexC) == 0)
	{
		cout << "Target " << userInt << " found at row " << indexR << ", col " << indexC << "!" << endl;
	}
	else
	{
		cout << "Target " << userInt << " not found." << endl;
	}

	system("pause");
	return 0;
}

/*
*Author: Arthur Aigeltinger IV
*Creation Date:		04/03/18
*Modification Date:	04/02/18
*Purpose: Ask user for integer to search for.
*/
int getUserInt()
{
	string input = "";
	int num = 0;

	cout << "Please enter integer to search for: ";
	cin >> input;
	num = verifyNum(input, false);

	return num;
}

/*
*Author: Arthur Aigeltinger IV
*Creation Date:		04/03/18
*Modification Date:	04/02/18
*Purpose: Search for user integer and print its location.
*/
int search(int box[][NCOLS], int rows, int cols, int userInt, int& indexR, int& indexC)
{
	//Iterate row counter
	for (int i = 0; i < rows; i++)
	{
		//Iterate column counter
		for (int j = 0; j < cols; j++)
		{
			if (box[i][j] == userInt)
			{
				indexR = i + 1;
				indexC = j + 1;
				return 0;
			}
		}
	}
	return -1;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/12/18
*Modification Date:	03/12/18
*Purpose: Checks for valid integer input OR double/int input via string.
*Dependencies: #include <cctype>, #include <string>
*
//Original Example of verifyNum()
std::string input = "";
int num = 0;
std::cout << "Please enter an integer value: ";
std::cin >> input;
std::cout << std::endl;
num = verifyNum(input, true);
*/
double verifyNum(string val, bool isDouble)	//If isDouble is TRUE function checks for a double, instead of int.
{
	string input = val;			//Create string and assign it to argument string value so it can be changed in subroutines below IF user enters new value for the string.
	bool isValid = true;		//Condition to specify whether the input is registered as valid (i.e. double or int). Default = TRUE.
	bool foundDecimal = false;	//Declare boolean to determine if decimal is present.
	int i = 0;					//Iterator for the individual characters of the string.

	do  //Perform loop at least once. While the input is not a valid string or double, repeat the loop.
	{
		isValid = true;
		i = 0;

		if (isDouble == false)	//If we're checking for an integer, we run through this conditional to verify if all of our characters are digits.
		{
			while (input[i] != '\0') //While the iterator has not reached end of the string ('\0' specifies the end delimiter of the string).
			{
				if (!isdigit(input[i]))	//If letter in the current index of the iterator isn't a digit, do this.
				{
					cout << "Input is not valid, please enter a new value: ";	//User inputs a new value for our local variable INPUT, breaks back out to initial do-while loop.
					isValid = false;
					cin >> input;
					cout << endl;
					break;
				}

				i++;
			}
		}
		else if (isDouble == true)
		{
			/*
			* WHILE:
			* While the iterator has not reached end of the string ('\0' specifies the end delimiter of the string)
			* Do this.
			*/
			while (input[i] != '\0')
			{
				/*
				* IF:
				* The letter in the current index of the iterator isn't a digit NOR is it a decimal
				* OR
				* The letter in the current index of the iterator is a decimal and found a decimal previously
				* Do this.
				*/
				if ((!isdigit(input[i]) && input[i] != '.') || (input[i] == '.' && foundDecimal == true))
				{
					cout << "Input is not valid, please enter a new value: "; //User inputs a new value for our local variable INPUT, breaks back out to initial do-while loop.
					isValid = false;
					cin >> input;
					cout << endl;
					break;
				}

				else if (input[i] == '.')	//If decimal found, set foundDecimal to true.
				{
					foundDecimal = true;
				}

				i++;
			}
		}
	} while (isValid == false); //If number NOT valid, repeat do-while loop.

	if (isDouble == true)	//If valid double, output the input casted to a double.
	{
		return stod(input);
	}

	else   //If valid integer, output the input casted to a integer.
	{
		return stoi(input);
	}
}
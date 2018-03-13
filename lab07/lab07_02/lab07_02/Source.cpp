/*
*Author: Arthur Aigeltinger IV
*Creation Date:		03/13/18
*Modification Date:	03/13/18
*Purpose: Produce a C shape of a user defined size made of a user defined character with functions for height at width.
*/

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

//Function Prototypes
void drawHorizontal(char, int);
void drawVertical(char, int);
double verifyNum(string, bool);

int main()
{
	char character;
	int height;
	int width;
	string input = "";

	cout << endl << "Please enter the character to be used in your BIG C: ";
	cin >> character;

	cout << endl << "Please enter the width of your BIG C: ";
	cin >> input;
	width = verifyNum(input, false);

	cout << endl << "Please enter the height of your BIG C: ";
	cin >> input;
	height = verifyNum(input, false);

	cout << endl;
	drawHorizontal(character, width);
	drawVertical(character, height);
	drawHorizontal(character, width);
	cout << endl;

	system("pause");
	return 0;
}

void drawHorizontal(char character, int width)
{
	for (int i = 0; i < width; i++)
	{
		cout << character;
	}
	cout << endl;
}

void drawVertical(char character, int height)
{
	for (int i = 0; i < height; i++)
	{
		cout << character << endl;
	}
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/12/18
*Modification Date:	03/12/18
*Purpose: Checks for valid integer input OR double/int input via string.
*Dependencies: #include <cctype>, #include <string>

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
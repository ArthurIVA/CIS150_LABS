/*
*Author: Arthur Aigeltinger IV
*Creation Date:		04/17/18
*Modification Date:	04/17/18
*Purpose: Write a complete program that uses the desk class.
*/

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "desk.h"

//GLOBAL CONSTANTS
const int SIZE = 5;

//FUNCTION PROTOTYPES
void fillDeskVector(std::vector<desk>&, std::string, std::ofstream&);
double verifyNum(std::string, bool);

int main()
{
	std::ofstream output;
	std::string fileName = "";

	//Declare a vector of 5 objects of desk class.
	std::vector<desk> row(SIZE);
	
	//Declare a single desk object and iniialize it at declaration to have color "silver".
	desk tempDesk;
	tempDesk.setColor("Silver");

	//Call the printMe method of the single object and display to the screen.
	std::cout << tempDesk.printMe() << std::endl;

	//Ask the user for the name of the file to which output should be written.
	std::cout << std::endl << "What file should your desks be placed in?" << std::endl << "[filename.txt] : ";
	std::cin >> fileName;

	fillDeskVector(row, fileName, output);

	//Explicitly close the output file.
	output.close();

	//Determine which desk has the most drawers. Then, display on the screen "Most drawers:" on one one, followed by printMe information for desk with that many drawers on the next line.
	int max = row[0].getDrawers();
	for (int i = 1; i < SIZE; i++)
	{
		if (row[i].getDrawers() > max)
		{
			int max = row[i].getDrawers();
		}
	}
	std::cout << std::endl << "Most drawers: " << row[max].printMe() << std::endl;

	system("PAUSE");
	return 0;
}

void fillDeskVector(std::vector<desk>& row, std::string fileName, std::ofstream& out)
{
	const int SIZE = 5;
	std::string color;
	std::string userIn;
	int numDrawers;

	//Ask the user for 5 colors and 5 numbers and asign them to each deask in the vector
	std::cout << std::endl << "Please enter the colors of five desks." << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Desk " << i + 1 << ": ";
		std::cin >> color;

		//For the 2nd desk, if the color's name is 4 or more characters long, change the 3rd character of the name to '#'.
		if (i == 1)
		{
			if (color.size() >= 4)
			{
				color[2] = '#';
			}
		}
		row[i].setColor(color);
	}

	std::cout << std::endl << "Please enter the number of drawers of each desk." << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		do
		{
			std::cout << "Desk " << i + 1 << ": ";
			std::cin >> userIn;
			numDrawers = verifyNum(userIn, false);
		} while (numDrawers < 0);

		row[i].setDrawers(numDrawers);
	}

	//Open the file and write to it using PrintMe method for all desks in your vector.
	out.open(fileName.c_str());
	
	for (int i = 0; i < SIZE; i++)
	{
		out << row[i].printMe() << std::endl;
	}
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
double verifyNum(std::string val, bool isDouble)	//If isDouble is TRUE function checks for a double, instead of int.
{
	std::string input = val;			//Create string and assign it to argument string value so it can be changed in subroutines below IF user enters new value for the string.
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
					std::cout << "Input is not valid, please enter a new value: ";	//User inputs a new value for our local variable INPUT, breaks back out to initial do-while loop.
					isValid = false;
					std::cin >> input;
					std::cout << std::endl;
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
					std::cout << "Input is not valid, please enter a new value: "; //User inputs a new value for our local variable INPUT, breaks back out to initial do-while loop.
					isValid = false;
					std::cin >> input;
					std::cout << std::endl;
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

/*
*Author: Arthur Aigeltinger IV
*Creation Date:		03/12/18
*Modification Date:	03/12/18
*Purpose: Perform calculateSum from 0 to N and calculateAverage.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//Function Prototypes
int calculateSum(int);
float calculateAverage(double, int);
double verifyNum(string, bool);

int main()
{
	int n = 0;
	int total = 0;
	double userIn = 0;
	double sumResult = 0;
	string input = "";
	//float avgResult; //May not need.

	//Display prompt for user.
	//calculateSum Section
	cout << "This program will call calculateSum." << endl;
	cout << "Please enter the number of integers you would like to add: ";
	cin >> input;
	n = verifyNum(input, false);

	cout << endl << "The total of your " << n << " numbers is " << calculateSum(n) << endl << endl;

	//calculateAverage Section
	cout << "Now this program will call calculateAverage" << endl;
	cout << "Please enter the number of numbers you would like to find the average of: ";
	cin >> input;
	n = verifyNum(input, false); //User input for how many numbers to average.

	for (int i = 1; i <= n; i++)
	{
		cout << "Please enter number " << i << " : ";	//Prompt user.
		cin >> input;									//Take user input.
		userIn = verifyNum(input, true);				//Verify that input is Double.
		sumResult += userIn;							//Add userIn to sumResult
	}

	cout << endl << "The average of your " << n << " numbers is " << calculateAverage(sumResult, n) << endl << endl;

	system("pause");
	return 0;
}

int calculateSum(int n)
{
	int total = 0;
	int userIn = 0;
	string input = "";

	for (int i = 1; i <= n; i++)
	{
		cout << "Please enter integer number " << i << " : ";
		cin >> input;
		userIn = verifyNum(input, false);
		total += userIn;
	}

	return total;
}

float calculateAverage(double sum, int n) //Well that was easy...
{
	return sum / n;
}

//Will use std::stoi of string library in the future.
//Originally used function created by Spencer Wong.
//Discovered that making new function would just be better.


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
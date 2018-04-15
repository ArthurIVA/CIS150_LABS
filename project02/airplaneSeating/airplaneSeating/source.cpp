/*
Author: Arthur Aigeltinger IV
Creation Date:		04/10/18
Modification Date:	04/15/18
Purpose: Simulate a seat booking system for a small passenger airplane with 10 rows, each with 4 seats.
*/

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

//Constants
const int NROWS = 10;
const int NCOLS = 4;
const int EXITCHOICE = 7;

//Function Prototypes
void drawMenu();
void loadSeatChart(char[][NCOLS], int, std::ifstream&);
void printSeatChart(char[][NCOLS], int);
void reserveSeat(char[][NCOLS], int);
double verifyNum(std::string, bool);


int main()
{
	//Declare and Initialize variables
	std::string userIn = "";
	int userChoice = 0;
	

	//Delcare Input Streams and Accompanying Arrays
	std::ifstream inputDefault;
	std::ifstream inputCurrent;
	char defaultSeatChart[NROWS][NCOLS];
	char seatChart[NROWS][NCOLS];

	//Open above input streams to appropriate text files.
	inputDefault.open("chartInTemplate.txt");
	inputCurrent.open("chartIn.txt");

	loadSeatChart(defaultSeatChart, NROWS, inputDefault);
	loadSeatChart(seatChart, NROWS, inputCurrent);

	//Debug Print Statements
	//Un-comment to see state of template and current seat chart.
	//printSeatChart(defaultSeatChart, NROWS);
	//printSeatChart(seatChart, NROWS);

	//Initially Draw Menu and wait for user selection.
	drawMenu();

	//Enter Decision Stage
	do
	{
		std::cout << "Please Enter Your Choice (1-7): ";
		std::cin >> userIn;

		userChoice = verifyNum(userIn, false);

		switch (userChoice)
		{
		case 1:
			std::cout << std::endl;
			printSeatChart(seatChart, NROWS);
			std::cout << std::endl;
			break;
		case 2:
			std::cout << std::endl;
			reserveSeat(seatChart, NROWS);
			std::cout << std::endl;
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			 
			break;
		case 6:

			break;
		default:
			//If selection is anything other than a valid choice or EXIT.
			break;
		}

	} while (userChoice != EXITCHOICE);

	system("pause");
	return 0;
}

//Functions


void reserveSeat(char seatArray[][NCOLS], int NROWS)
{
	//Define input and choice variables
	std::string input = "";
	int rowChoice = -1; //When rowChoice is -1, seat is invalid.
	int colChoice;
	char seatChoice = ' ';

	//Query for input.
	std::cout << "Please Enter Seat to Reserve [1A, 4C, 6D, etc]: ";
	std::cin >> input;

	//Check input lengths and type validity.
	if (isdigit(input[0]) && isdigit(input[1]))
	{
		if (input.size() > 3)
		{
			std::cout << "INPUT LENGTH TOO LONG" << std::endl;
		}
		else
		{
			rowChoice = std::stoi(input.substr(0, 2));
			seatChoice = input[2];
			seatChoice = toupper(seatChoice);
		}
	}
	else if (isdigit(input[0]))
	{
		if (input.size() > 2)
		{
			std::cout << "INPUT LENGTH TOO LONG" << std::endl;
		}
		else
		{
			rowChoice = std::stoi(input.substr(0));
			seatChoice = input[1];
			seatChoice = toupper(seatChoice);
		}
	}
	//Check for row number within range.
	if (!(rowChoice > 0 && rowChoice <= NROWS))
	{
		std::cout << "ROW OUT OF RANGE" << std::endl;
		rowChoice = -1;
	}

	//Check for column out of range.
	if (seatChoice != 'A' && seatChoice != 'B' && seatChoice != 'C' && seatChoice != 'D')
	{
		std::cout << "IVALID SEAT LETTER" << std::endl;
		rowChoice = -1;
	}

	if (seatChoice == 'A')
	{
		colChoice = 0;
	}
	else if (seatChoice == 'B')
	{
		colChoice = 1;
	}
	else if (seatChoice == 'C')
	{
		colChoice = 2;
	}
	else if (seatChoice == 'D')
	{
		colChoice = 3;
	}

	if (seatChoice != -1)
	{
		if (seatArray[rowChoice - 1][colChoice] != 'X')
		{
			seatArray[rowChoice - 1][colChoice] = 'X';
		}
	}

	//Debug statement to check rowChoice.
	std::cout << rowChoice << std::endl;
	std::cout << seatChoice << std::endl;
	std::cout << colChoice << std::endl;

/*
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
*/
}
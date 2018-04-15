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
	std::string input = "";

	std::cout << "Please Enter Seat to Reserve [1A, 4C, 6D, etc]: ";
	std::cin >> input;
	if (input[1] == '\0')
	{
		std::cout << "INPUT LENGTH TOO SHORT" << std::endl;
	}
	else if (input[2] != '\0')
	{
		std::cout << "INPUT LENGHT TOO LONG" << std::endl;
	}
	
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
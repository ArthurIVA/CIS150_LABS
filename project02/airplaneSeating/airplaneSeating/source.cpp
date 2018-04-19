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

//Global Constants
const int NROWS = 10;
const int NCOLS = 4;
const int EXITCHOICE = 7;

//Function Prototypes
void drawMenu();
void loadSeatChart(char[][NCOLS], int, std::ifstream&);
void saveSeatChart(char[][NCOLS], int, std::ofstream&);
void printSeatChart(char[][NCOLS], int);
void reserveSeat(char[][NCOLS], int);
void cancelSeat(char[][NCOLS], char[][NCOLS], int);
void printStats(char[][NCOLS], char[][NCOLS], int);
void helpMessage();
void exitMessage();
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

	//Declare Output Stream.
	std::ofstream outputCurrent;

	//Open above input streams to appropriate text files.
	inputDefault.open("chartInTemplate.txt");
	inputCurrent.open("chartIn.txt");

	//Fill current seat chart as well at template seat chart.
	loadSeatChart(defaultSeatChart, NROWS, inputDefault);
	loadSeatChart(seatChart, NROWS, inputCurrent);

	//Explicity close input files when arrays are filled.
	inputDefault.close();
	inputCurrent.close();

	//WILL REMOVE THESE STATEMENTS
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
			std::cout << std::endl;
			cancelSeat(seatChart, defaultSeatChart, NROWS);
			std::cout << std::endl;
			break;
		case 4:
			std::cout << std::endl;
			saveSeatChart(seatChart, NROWS, outputCurrent);
			std::cout << std::endl;
			break;
		case 5:
			std::cout << std::endl;
			printStats(seatChart, defaultSeatChart, NROWS);
			std::cout << std::endl;
			break;
		case 6:
			std::cout << std::endl;
			helpMessage();
			std::cout << std::endl;
			break;
		default:
			//If selection is anything other than a valid choice or EXIT.
			break;
		}

	} while (userChoice != EXITCHOICE);

	std::cout << std::endl;
	exitMessage();
	std::cout << std::endl;

	system("pause");
	return 0;
}

//Functions

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/15/18
Modification Date:	04/15/18
Purpose: Provide template for menu using string literals within std::cout statements.
*/
void drawMenu()
{
	std::cout << "------------------------ Menu ---------------------------" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "\t 1. Display Seat Chart" << std::endl;
	std::cout << "\t 2. Reserve Seat" << std::endl;
	std::cout << "\t 3. Cancel Reservation" << std::endl;
	std::cout << "\t 4. Save Seat Chart to File" << std::endl;
	std::cout << "\t 5. Statistics" << std::endl;
	std::cout << "\t 6. Help" << std::endl;
	std::cout << "\t 7. Quit" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
}

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

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/10/18
Modification Date:	04/15/18
Purpose: Take in a given seat array and then print it to the console.
*/
void printSeatChart(char seatArray[][NCOLS], int NROWS)
{
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
	}
}

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/10/18
Modification Date:	04/15/18
Purpose: Parse an input string and use that to reserve a seat on seatArray[].
*/
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
	if (input.size() < 2)
	{
		std::cout << "INPUT LENGTH TOO SHORT" << std::endl;
		return;
	}
	else if (isdigit(input[0]) && isdigit(input[1]))
	{
		if (input.size() > 3)
		{
			std::cout << "INPUT LENGTH TOO LONG" << std::endl;
			return;
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
			return;
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
		return;
		rowChoice = -1;
	}

	//Check for column out of range.
	if (seatChoice != 'A' && seatChoice != 'B' && seatChoice != 'C' && seatChoice != 'D')
	{
		std::cout << "IVALID SEAT LETTER" << std::endl;
		return;
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
			std::cout << "Seat has been reserved" << std::endl;
		}
		else if (seatArray[rowChoice - 1][colChoice] = 'X')
		{
			std::cout << "Seat already reserved, please select another." << std::endl;
		}
		else
		{
			std::cout << "INVALID SEAT" << std::endl;
		}
	}
}

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/19/18
Modification Date:	04/19/18
Purpose: Parse an input string and use that to cancel a seat on seatArray[].
Also realizing in hindsight that this and the reserveSeat() function could be consolidated.
Just include a BOOL to be passed which would change the single comparative statement at the end of the function.
*/
void cancelSeat(char seatArray[][NCOLS], char defaultSeatArray[][NCOLS], int NROWS)
{
	//Define input and choice variables
	std::string input = "";
	int rowChoice = -1; //When rowChoice is -1, seat is invalid.
	int colChoice;
	char seatChoice = ' ';

	//Query for input.
	std::cout << "Please Enter Seat to Cancel [1A, 4C, 6D, etc]: ";
	std::cin >> input;

	//Check input lengths and type validity.
	if (input.size() < 2)
	{
		std::cout << "INPUT LENGTH TOO SHORT" << std::endl;
		return;
	}
	else if (isdigit(input[0]) && isdigit(input[1]))
	{
		if (input.size() > 3)
		{
			std::cout << "INPUT LENGTH TOO LONG" << std::endl;
			return;
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
		return;
		rowChoice = -1;
	}

	//Check for column out of range.
	if (seatChoice != 'A' && seatChoice != 'B' && seatChoice != 'C' && seatChoice != 'D')
	{
		std::cout << "IVALID SEAT LETTER" << std::endl;
		return;
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
		if (seatArray[rowChoice - 1][colChoice] != defaultSeatArray[rowChoice - 1][colChoice])
		{
			seatArray[rowChoice - 1][colChoice] = defaultSeatArray[rowChoice - 1][colChoice];
			std::cout << "Seat has been canceled." << std::endl;
		}
		else
		{
			std::cout << "That seat is available you goof! Try again." << std::endl;
		}
	}
}

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/19/18
Modification Date:	04/19/18
Purpose: Save current seat chart to file.
*/
void saveSeatChart(char seatArray[][NCOLS], int NROWS, std::ofstream& out)
{
	std::string fileName = "";

	std::cout << "Please enter output filename, including '.txt'. Choosing [chartIn.txt] will change the default loaded file." << std::endl;
	std::cout << "Filename: ";

	std::cin >> fileName;

	out.open(fileName);

	//Continue until array.
	for(int rowCount = 1; rowCount <= 10; rowCount++)
	{
		out << std::left << std::fixed << std::setw(4) << rowCount;

		//Inner loop iterates through sub-columns of seat rows.
		for (int j = 0; j < NCOLS; j++)
		{
			out << std::left << std::fixed << std::setw(3) << seatArray[rowCount - 1][j];
		}
		out << std::endl;
	}

	//Explicitly close output file.
	out.close();

	std::cout << "File has been saved to " << fileName << std::endl;
}

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/19/18
Modification Date:	04/19/18
Purpose: Displays stats of current flight to user.
*/
void printStats(char seatArray[][NCOLS], char defaultSeatArray[][NCOLS], int NROWS)
{
	//Declare local variables.
	int seatsAvailable = 0;
	int windowSeatsAvailable = 0;
	int aisleSeatsAvailable = 0;
	int seatsTotal = (NROWS * NCOLS);

	//Count all seats available.
	//Outer loop iterates through rows with formatting.
	for (int i = 0; i < NROWS; i++)
	{
		//Inner loop iterates through sub-columns of seat rows.
		for (int j = 0; j < NCOLS; j++)
		{
			//Check for general seat availability.
			if (seatArray[i][j] == defaultSeatArray[i][j])
			{
				seatsAvailable++;
			}
			//Check for window seat availability.
			if (seatArray[i][j] == 'A' || seatArray[i][j] == 'D')
			{
				windowSeatsAvailable++;
			}
			if (seatArray[i][j] == 'B' || seatArray[i][j] == 'C')
			{
				aisleSeatsAvailable++;
			}
		}
	}

	std::cout << std::endl << "----------------CURRENT FLIGHT STATISTICS----------------" << std::endl << std::endl;

	//Print Number of available seats.

	std::cout << "\t Seats Available : " << seatsAvailable << std::endl;

	//Percentage of seats already reserved.

	std::cout << "\t Seats Reserved : " << (float)(100 * (((float)seatsTotal - (float)seatsAvailable) / (float)seatsTotal)) << "%" << std::endl;

	//List of window seats available.

	std::cout << "\t Window Seats Available : " << windowSeatsAvailable << std::endl;

	//List of aisle seats available.

	std::cout << "\t Aisle Seats Available : " << aisleSeatsAvailable << std::endl;

}

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/19/18
Modification Date:	04/19/18
Purpose: Displays helpful hints to the user as well as redraws the menu.
*/
void helpMessage()
{
	system("CLS");

	std::cout << "-------------------------HELP----------------------------" << std::endl << std::endl;
	std::cout << "\t 1. Display Seat Chart" << std::endl;
	std::cout << "This will show you the current chart of booked and unbooked seats for this flight." << std::endl;
	std::cout << "Booked seats are identified by the 'X' in place of the normal seat letter." << std::endl;
	std::cout << "" << std::endl;
	std::cout << "\t 2. Reserve Seat" << std::endl;
	std::cout << "Picking this option will give you the opportunity to input a seat you would like to reserve." << std::endl;
	std::cout << "The format to input the desired seat is [Row Number][Seat Letter]. Examples - 1B, 10C, 4D, 5A, etc." << std::endl;
	std::cout << "" << std::endl;
	std::cout << "\t 3. Cancel Reservation" << std::endl;
	std::cout << "Conversely to reservation, this will give you the opportunity to input a seat to cancel." << std::endl;
	std::cout << "The format to input the desired seat is [Row Number][Seat Letter]. Examples - 1B, 10C, 4D, 5A, etc." << std::endl;
	std::cout << "" << std::endl;
	std::cout << "\t 4. Save Seat Chart to File" << std::endl;
	std::cout << "This option will ask you for a given filename to save the current seat chart to." << std::endl;
	std::cout << "" << std::endl;
	std::cout << "\t 5. Statistics" << std::endl;
	std::cout << "Select this option to see current stats about the loaded flight." << std::endl;
	std::cout << "Stats Including - Seats Available, Window Seats, Aisle Seats, and percentage of seats booked." << std::endl;
	std::cout << "" << std::endl;
	std::cout << "\t 6. Help" << std::endl;
	std::cout << "Hopefully you know this one... Because you're already here!" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "\t 7. Quit" << std::endl;
	std::cout << "Recieve our complementary good tidings!" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;

	system("PAUSE");
	system("CLS");

	drawMenu();
}

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/19/18
Modification Date:	04/19/18
Purpose: Displays thank you and exit message before program termination.
*/
void exitMessage()
{
	std::cout << "Thank you for booking with Air CIS! We hope you like the airline food..." << std::endl;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/12/18
*Modification Date:	04/15/18
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
					std::cout << "Please Enter Your Choice (1-7): ";	//User inputs a new value for our local variable INPUT, breaks back out to initial do-while loop.
					isValid = false;
					std::cin >> input;
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
					std::cout << "Please Enter Your Choice (1-7) : "; //User inputs a new value for our local variable INPUT, breaks back out to initial do-while loop.
					isValid = false;
					std::cin >> input;

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
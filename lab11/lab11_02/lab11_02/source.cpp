/*
*Author: Arthur Aigeltinger IV
*Creation Date:		04/09/18
*Modification Date:	04/10/18
*Purpose: Take in student data via file and then process into accessible table format.
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "student.h"

int main()
{
	//Input Stream
	std::ifstream input;

	//Object Initialization
	//Max Size of course[]
	const int SIZE = 30;
	student course[SIZE];

	//Output Format Constants
	const int NAMEWIDTH =	35;
	const int GRADEWIDTH =	8;

	//Counter Declaration
	int i;

	//Other Tracking Variables
	int numStudents = 0;
	int numAssignments = 0;
	float highestAvg = 0.0;
	float lowestAvg = 0.0;
	float totalScores = 0.0; //Used to calculate average for whole class.

	//Move file into input stream
	input.open("studentData.txt");

	i = 0; //Reset Counter
	//Using broader function to fill object instead of complicated calls for 'set' functions.
	//'set' functions could be implemented to change individual grades or name - act as failsafe here.
	while (!input.eof())
	{
		course[i].fillInfo(input);
		i++;
		numStudents++;
	}

	i = 0; //Reset Counter
	//<CONSOLE_OUTPUT_FORMATTING>
	//Print Table Column Labels, same widths, left margin. (with convoluted loops)
	/*
	STUDENT NAME                      |GRADES |       |       |       |       |AVERAGE
	-----------------------------------------------------------------------------------
	*/
	std::cout << std::left << std::setw(NAMEWIDTH - 1) << "STUDENT NAME" << std::setw(GRADEWIDTH) << "|GRADES";
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::setw(GRADEWIDTH) << "|";
	}
	std::cout << "|AVERAGE" << std::endl;
	//Print Dividing Line
	for  (int i = 0; i < (NAMEWIDTH + (GRADEWIDTH * 6)); i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;

	//Give values to compare while printing data.
	highestAvg = course[0].averageGrade();
	lowestAvg = course[0].averageGrade();

	//Print DATA
	while (course[i].getStudentName() != "") //Looking for blank name to end, blank name is default.
	{
		//Print Name, with NAMEWIDTH space, left margin.
		std::cout << std::setw(NAMEWIDTH) << course[i].getStudentName();

		for (int j = 0; j < 5; j++)
		{
			//Print Grades, with GRADEWIDTH space, left margin.
			std::cout << std::setw(GRADEWIDTH) << course[i].getStudentGrade(j);
			totalScores += course[i].getStudentGrade(j);
			numAssignments++;
		}

		if (course[i].averageGrade() > highestAvg)
			highestAvg = course[i].averageGrade();

		if (course[i].averageGrade() < lowestAvg)
			lowestAvg = course[i].averageGrade();

		std::cout << std::fixed << std::setprecision(2) << course[i].averageGrade() << std::endl;
		i++;
	}
	//</CONSOLE_OUTPUT_FORMATTING>

	std::cout << std::endl << std::endl;

	//<SUMMARY_INFORMATION>
	std::cout << "Total Number of Students: " << numStudents << std::endl;
	std::cout << "Highest Average in class: " << highestAvg << std::endl;
	std::cout << "Lowest Average in class:  " << lowestAvg << std::endl;
	std::cout << "Total Average for class:  " << (totalScores / numAssignments) << std::endl; //Also could have just averaged all averages.

	system("pause");
	return 0;
}
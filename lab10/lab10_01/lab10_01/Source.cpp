/*
*Author: Arthur Aigeltinger IV
*Creation Date:		04/02/18
*Modification Date:	04/02/18
*Purpose: Perform given functions on a student data set in a text file, print outputs in console and file.
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//Struct Prototypes
struct student
{
	int id;
	string first;
	string last;
	float grade;
};

//Function Prototypes
void readInfo(student[], int, ifstream&);
void defaultNullArray(student[], int);
int highestGrade(student[], int);
int lowestGrade(student[], int);
int studentsProcessed(student[], int);
float avgGrade(student[], int);
void printInfo(student[], ofstream&, int, int, int, float);

int main()
{
	//Decalre and Initialize variables
	const int SIZE = 100;
	student course[SIZE];
	ifstream input;
	ofstream output;
	string fileName = "";
	int indexMax;
	int indexMin;
	float avgScore;
	int studProcessed;

	//Set array to all null/default values
	defaultNullArray(course, SIZE);

	//Take in INPUT and OUTPUT file names
	cout << "Please enter the name of the file containing student info" << endl << "[default info.txt]: ";
	cin >> fileName;

	input.open(fileName.c_str());

	cout << "Please enter the name of the file to output data into" << endl << "[default results.txt]: ";
	cin >> fileName;

	output.open(fileName.c_str());

	readInfo(course, SIZE, input);

	//Output to console
	cout << endl;
	indexMax = highestGrade(course, SIZE);
	indexMin = lowestGrade(course, SIZE);
	avgScore = avgGrade(course, SIZE);
	studProcessed = studentsProcessed(course, SIZE);
	cout << endl;

	//Output to file
	printInfo(course, output, indexMax, indexMin, studProcessed, avgScore);

	cout << "Data has been inserted into " << fileName << endl;

	system("pause");
	return 0;
}



/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/02/18
*Modification Date:	04/02/18
*Purpose: Read grades from file to fill up array of type student - to handle out of order student id(s).
*
*Desired Format:
* Student ID, First Name, Last Name, Grade.
* newline
*/
void readInfo(student course[], int, ifstream& in)
{
	int i = 0;

	//Fill array until end of file is reached
	while (!in.eof())
	{
		in >> course[i].id >> course[i].first >> course[i].last >> course[i].grade;
		i++;
	}
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/02/18
*Modification Date:	04/02/18
*Purpose: Fill array with null values by default.
*/
void defaultNullArray(student course[], int size)
{
	//Iterate index variable and fill all values
	for (int i = 0; i < size; i++)
	{
		course[i].id = 0;
		course[i].first = "";
		course[i].last = "";
		course[i].grade = 0;
	}
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/02/18
*Modification Date:	04/02/18
*Purpose: Calculate and display maximum grade with student name in array.
*/
int highestGrade(student course[], int size)
{
	float highest = course[0].grade;
	int index = 0;
	int i = 0;

	//Read array until no more students
	while (course[i].id != 0)
	{
		if (highest < course[i].grade)
		{
			highest = course[i].grade;
			index = i;
		}
		//If end of array, break
		if (i < (size - 1))
		{
			i++;
		}
		else
		{
			break;
		}
	}

	cout << "The highest grade was " << fixed << setprecision(2) << highest << ", achieved by " << course[index].first << " " << course[index].last << endl;

	return index;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/02/18
*Modification Date:	04/02/18
*Purpose: Calculate and display minimum grade with student name in array.
*/
int lowestGrade(student course[], int size)
{
	float lowest = course[0].grade;
	int index = 0;
	int i = 0;

	//Read array until no more students
	while (course[i].id != 0)
	{
		if (lowest > course[i].grade)
		{
			lowest = course[i].grade;
			index = i;
		}
		//If end of array, break
		if (i < (size - 1))
		{
			i++;
		}
		else
		{
			break;
		}
	}

	cout << "The lowest grade was " << fixed << setprecision(2) << lowest << ", achieved by " << course[index].first << " " << course[index].last << endl;

	return index;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/02/18
*Modification Date:	04/02/18
*Purpose: Calculate and display number of students processed
*/
int studentsProcessed(student course[], int size)
{
	int i = 0;

	//Read array until no more students
	while (course[i].id != 0)
	{
		//If end of array, break
		if(i < (size - 1))
		{
			i++;
		}
		else
		{
			break;
		}
	}

	cout << "The number of students processed is " << i << endl;

	return i;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/02/18
*Modification Date:	04/02/18
*Purpose: Calculate and display average of all grade(s). 
*/
float avgGrade(student course[], int size)
{
	float average = 0;
	float total = 0;
	int index = 0;
	int i = 0;

	//Read array until no more students
	while (course[i].id != 0)
	{
		total += course[i].grade;

		//If end of array, break
		if (i < (size - 1))
		{
			i++;
		}
		else
		{
			break;
		}

		index = i;

	}

	average = total / index;

	cout << "The average grade is " << fixed << setprecision(3) << average << endl;

	return average;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		04/02/18
*Modification Date:	04/02/18
*Purpose: Produce output file with all information included in functions above. 
*/
void printInfo(student course[], ofstream& out, int indexMax, int indexMin, int studProcessed, float avgScore)
{
	//Format output file.
	out << "Highest Grade - " << fixed << setprecision(2) << course[indexMax].grade << " - " << course[indexMax].first << " " << course[indexMax].last << endl;
	out << "Lowest  Grade - " << fixed << setprecision(2) << course[indexMin].grade << " - " << course[indexMin].first << " " << course[indexMin].last << endl;
	out << "Average Grade - " << fixed << setprecision(3) << avgScore << endl << endl;
	out << "Number of Students Processed - " << studProcessed << endl;
}


#include "student.h"


/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/09/18
Modification Date:	04/09/18
Purpose: Take string input and assign it to name within class student
Standard Use

FORMATTING STRING SIZE = 35
*/
void student::setStudentName(std::string input)
{
	name = input;
}

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/09/18
Modification Date:	04/09/18
Purpose: Take input of grade and index of said grade from 0-4 and insert said grade into said index.
Standard Use

DEFAULT SIZE = 5

student::setStudentGrade(98, 3);

-> grades[5] = {0,0,0,98,0};

Or integrate into loop to fill all grades.
*/
void student::setStudentGrade(int grade, int index, int size = 5)
{
	//Initially check for valid index within the array
	if (index < 0 || index >= size)
	{
		std::cout << "INVALID INDEX - CHECK FORMATTING OF FILE" << std::endl;
	}
	else if (grade >= 0)//Valid Index
	{
		grades[index] = grade;
	}
	else
	{
		std::cout << "INVALID GRADE - CHECK FORMATTING OF FILE" << std::endl;
	}
}

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/09/18
Modification Date:	04/09/18
Purpose: Insert partial input stream into name and grades by line.
Standard Use

student::fillInfo(student myArray[], ifstream& below)

FORMATTING
string int   int   int   int   int
name   grade grade grade grade grade
*/
void student::fillInfo(std::ifstream& in, int size)
{
	//Fill name then grades.
	in >> name;
	
	for (int i = 0; i < size; i++)
	{
		in >> grades[i];
	}
}

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/09/18
Modification Date:	04/09/18
Purpose: Return student name.
Standard Use

student::getStudentName();
*/
std::string student::getStudentName()
{
	return name;
}

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/09/18
Modification Date:	04/09/18
Purpose: Return student grade at index [0-4].
Standard Use

student::getStudentGrade(3); 
-> grades[5] = {0,0,0,98,0};
return -> 98

Or integrate into loop to return all grades.
*/
int student::getStudentGrade(int index, int size)
{
	//Initially check for valid index within the array
	if (index >= 0 && index < size)
	{
		return grades[index];
	}
	else
	{
		std::cout << "INVALID SEARCH INDEX" << std::endl;
		return -1;
	}
}

/*
Function Author: Arthur Aigeltinger IV
Creation Date:		04/09/18
Modification Date:	04/09/18
Purpose: Return student name.
Standard Use

student::averageGrade();
*/
float student::averageGrade(int size)
{
	//Initialize
	float total = 0;

	//Accumulate all grades into total.
	for (int i = 0; i < size; i++)
	{
		total += grades[i];
	}
	//Self explanatory...
	return (float)total / size;
}

student::student()
{
}


student::~student()
{
}

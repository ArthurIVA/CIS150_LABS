/*
*Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Take file input and calculate employee salary, then print that to another file.
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//Function Prototype(s)
void processStudents(ifstream&);

int main()
{
	ifstream input;
	string fileName;;

	cout << "This program will take formatted student and score file and provide the average and the max." << endl;
	//Prompt user for input and output filenames with suggested defaults.
	cout << "Input Filename [default scores.txt] : ";
	cin >> fileName;

	//Once file is open it will be referred to by its logical name - [input/output]
	input.open(fileName.c_str());

	//PULL THE LEVER KRONK 2.0
	processStudents(input);

	cout  << "Thank you for using this utility!" << endl << endl;

	//Close logical files.
	input.close();

	system("pause");
	return 0;
}

//Always remember to pass file variables by reference.

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Pass logical file into function and perform line read, calculation, and cout.
*/
void processStudents(ifstream& in)
{
	//Declare necessary local variables.
	string firstName, lastName;
	string topFirstName, topLastName;
	float score, avgScore;
	float totalScore = 0;
	float maxScore = 0;
	int numScores = 0;

	//Specify loop until End Of File reached.
	while (!in.eof())
	{
		//Take input as formatted in original file by line.
		//Does not handle different formats.
		in >> firstName >> lastName >> score;

		//Add to total score and iterate counter of number of scores.
		totalScore += score;
		numScores++;

		//Check for largest score in list.
		if (score > maxScore)
		{
			topFirstName = firstName;
			topLastName = lastName;
			maxScore = score;
		}
		
	}

	avgScore = totalScore / numScores;

	cout << endl << "Average score is " << avgScore << endl;
	cout << "The higest score was " << maxScore << " from " << topFirstName << " " << topLastName  << "." << endl;

}
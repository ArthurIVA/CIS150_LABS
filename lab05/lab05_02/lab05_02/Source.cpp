/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		02/19/18
*Modification Date:	02/19/18
*Purpose: Calculate average score of user defined class size using a FOR loop.
*/

#include <iostream>

using namespace std;

int main()
{
	int numStudents; //Declare variable to contain # of students in class.
	double score, totalScore, averageScore; // Declare variables to hold calculation values.

	totalScore = 0; //Initialize totalScore outside of loop allow it to be accumulated.

	cout << "Enter the number of students you would like to calculate the average grade for: ";
	cin >> numStudents;

	for (int countStudents = 0; countStudents < numStudents; countStudents++) //Initialize local counter for accumulation.
	{
		cout << endl << "Enter exam score for student number " << countStudents + 1 << " : ";
		cin >> score;
		totalScore += score; //"totalScore = totalScore + score" equivalent. 
	}

	averageScore = totalScore / numStudents;

	cout << endl << "The average score is " << averageScore << endl << endl;

	system("pause");
	return 0;
}
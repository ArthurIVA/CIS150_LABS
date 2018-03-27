/*
*Author: Arthur Aigeltinger IV
*Creation Date:		03/27/18
*Modification Date:	03/27/18
*Purpose: Take in answer key and given student answers to compare then print.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Function Prototypes
float calculatePointGrade(int, int);
char calculateLetterGrade(float pointGrade);
void readSettings(ifstream&, string&, int&);
int gradeAnswer(string, string, int);


int main()
{
	ifstream input;
	ifstream settings;
	ofstream output;
	string fileName1, fileName2, fileName3;
	string answerKey = "";
	string answers = "";
	string firstName = "";
	string lastName = "";
	float percentGrade = 0;
	int numQuestions = 0;
	int correctAnswers = 0;

	//cout << "Input Settings File [default settings.txt] : ";
	//cin >> fileName1;

	//settings.open(fileName1.c_str());

	//cout << "Input Student Answers File [default exam.txt] : ";
	//cin >> fileName2;

	//input.open(fileName2.c_str());

	//cout << "Output File [default grades.txt] : ";
	//cin >> fileName3;

	//output.open(fileName3.c_str());

	//Set filenames for all applicable logical files.
	settings.open("settings.txt");
	input.open("exam.txt");
	output.open("grades.txt");

	//Read settings file containing answer key and number of questions. 
	readSettings(settings, answerKey, numQuestions);

	cout << "Input and Subsequent Output" << endl;
	cout << "---------------------------------" << endl << endl;

	//Read buffer of input file and push results to output file.
	while (!input.eof())
	{
		input >> firstName >> lastName >> answers;

		cout << firstName << " " << lastName << " " << answers << endl;

		correctAnswers = gradeAnswer(answers, answerKey, numQuestions);
		percentGrade = calculatePointGrade(correctAnswers, numQuestions);
		output << firstName << " " << lastName << " ";
		output << fixed << setprecision(1) << percentGrade << "% ";
		output << calculateLetterGrade(percentGrade) << endl;

		cout << firstName << " " << lastName << " " << fixed << setprecision(1) << percentGrade << "% " << calculateLetterGrade(percentGrade) << endl;

	}

	cout << endl;

	input.close();
	settings.close();
	output.close();


	system("pause");
	return 0;
}



/*
 Author: Arthur Aigeltinger IV
 Creation Date: 03/27/18
 Last Modification Date: 03/27/18
 Purpose: compares answer with key (character per character).
          Each character represents the answer to a question.
          The number of questions is numOfQuestions.
          Returns the number of correct answers
*/
int gradeAnswer(string answers, string key, int numOfQuestions)
{
	int i = 0;
	int correctAnswers = 0;

	//While iterator has not reached and of string.
	while (answers[i] != '\0')
	{
		//Compare value at iterator position of answers to key.
		if (answers[i] == key[i])
		{
			//Iterate correctAnswers if answer is correct.
			correctAnswers++;
		}
		//Iterate iterator.
		i++;
	}
	
	return correctAnswers;
}

/*
Author: Arthur Aigeltinger IV
Creation Date: 03/27/18
Last Modification Date: 03/27/18
 Purpose: Gets the number of correct questions and the total
          number of questions. Returns the grade out of 100
*/
float calculatePointGrade(int numOfCorrectAnswers, int numOfQuestions)
{
	return 100 * ((float)numOfCorrectAnswers / (float)numOfQuestions);
}

/*
Author: Arthur Aigeltinger IV
Creation Date: 03/27/18
Last Modification Date: 03/27/18
 Purpose: Returns the letter grade using the following:
          >=90				A
          <90 and >=80		B
          <80 and >= 70		C
          <70 and >= 60		D
          <60 and >= 50		E
          <50 				F
*/
char calculateLetterGrade(float pointGrade)
{
	if (pointGrade >= 90)
		return 'A';
	else if (pointGrade >= 80)
		return 'B';
	else if (pointGrade >= 70)
		return 'C';
	else if (pointGrade >= 60)
		return 'D';
	else if (pointGrade >= 50)
		return 'E';
	else
		return 'F';
}

/*
Author: Arthur Aigeltinger IV
Creation Date: 03/27/18
Last Modification Date: 03/27/18
 Purpose: Returns the number of questions and answer
          key of the exam (both as reference parameters)
          We assume the file settings contains only two data:
          Number of questions (in line 1 of the file)
          Answer key (line 2 of the file)
*/
void readSettings(ifstream& settings, string& key, int& numQuestions)
{
	while (!settings.eof())
	{
		settings >> numQuestions >> key;
	}
}

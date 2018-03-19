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
void processSalary(ifstream&, ofstream&);

int main()
{
	ifstream input;
	ofstream output;
	string fileName1, fileName2;

	//Prompt user for input and output filenames with suggested defaults.
	cout << "Input Filename [default employees.txt] : ";
	cin >> fileName1;
	cout << "Output Filename [default results.txt] : ";
	cin >> fileName2;

	//Once file is open it will be referred to by its logical name - [input/output]
	input.open(fileName1.c_str());
	output.open(fileName2.c_str());

	//PULL THE LEVER KRONK
	processSalary(input, output);

	cout << endl << "Weekly salary of each employee has been calculated and outputted to " << fileName2;
	cout << endl << "Thank you for using this utility!" << endl << endl;

	//Close logical files.
	input.close();
	output.close();

	system("pause");
	return 0;
}

//Always remember to pass file variables by reference.

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Pass logical files into function and perform line read, calculation, and line write.
*/
void processSalary(ifstream& in, ofstream& out)
{
	//Declare necessary local variables.
	string firstName, lastName;
	float hours, hourlyRate, salary;

	//Specify loop until End Of File reached.
	while (!in.eof())
	{
		//Take input as formatted in original file by line.
		//Does not handle different formats.
		in >> firstName >> lastName >> hours >> hourlyRate;

		//Calculate and print subsequent lines into logical output.
		salary = hours * hourlyRate;
		out << firstName << " " << lastName << "'s Weekly Salary = $" << salary << endl;
	}
}
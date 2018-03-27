/*
*Author: Arthur Aigeltinger IV
*Creation Date:		03/27/18
*Modification Date:	03/27/18
*Purpose: 
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	struct letterOccur
	{
		char letter;
		unsigned short occurrences;
	};

	string holder[10];
	vector<letterOccur> characterHolder;
	ifstream file("poem.txt");
	ofstream capitalOutput("capitalOutput.txt");
	ofstream statisticsOutput("statisticsOutput.txt");

	for (unsigned short i = 0; i < 10; i++)  //Loop to pass lines from file into the array.
	{
		getline(file, holder[i]); 
	}	

	file.seekg(0);

	while (!file.eof())
	{
		letterOccur *tempObject = new letterOccur;
		bool letterExists = false;
		unsigned short posOfExistingLetter = 0;
		for (unsigned short i = 0; i < characterHolder.size(); i++)
		{
			if (toupper(file.peek()) == characterHolder.at(i).letter)
			{
				letterExists = true;
				posOfExistingLetter = i;
				break;
			}
		}

		if (letterExists == true)
			characterHolder.at(posOfExistingLetter).occurrences++;

		else if (letterExists == false && file.peek() != '32' && file.peek() != -1 && file.peek() != '\n')
		{
			tempObject->letter = toupper(file.peek());
			tempObject->occurrences = 1;
			characterHolder.push_back(*tempObject);
		}

		file.get();
		letterExists = false;
	}

	for (int i = 0; i < characterHolder.size(); i++)
	{
		cout << "Letter: " << characterHolder.at(i).letter << endl;
		cout << "Occurrences: " << characterHolder.at(i).occurrences << endl;
		cout << endl;
	}



	system("PAUSE");
}
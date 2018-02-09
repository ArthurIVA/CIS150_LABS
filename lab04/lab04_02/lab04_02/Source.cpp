/*
*Author:			Arthur Aigeltinger IV
*Creation Date:		02/06/18
*Modification Date:	02/08/18
*Purpose: Get letter grade, GIVE MORE JUGDEMENT!
*/

#include <iostream>
#include <cctype> //Will help with exception handling in terms of UPPER and lower case inputs & invalid grade

using namespace std;

int main()
{
	char grade = 0;

	cout << "Please enter the letter grade of the student: ";
	cin >> grade;
	grade = toupper(grade); //Applied toupper to handle all lower case inputs.

	switch (grade)
	{
		case 'A':
		{
			cout << "Excellent" << endl;
			break;
		}
		
		case 'B':
		{
			cout << "Good" << endl;
			break;
		}

		case 'C':
		{
			cout << "Average" << endl;
			break;
		}

		case 'D':
		{
			cout << "Below Average" << endl;
			break;
		}

		case 'E':
		{
			cout << "Below Average " << endl;
			break;
		}

		case 'F':
		{
			cout << "Fail" << endl;
			break;
		}

		default:
		{
			cout << "Invalid Grade" << endl;
			break;
		}
	}

	system("pause");
	return 0;

}
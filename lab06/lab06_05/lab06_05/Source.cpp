/*
*Author: Arthur Aigeltinger IV
*Creation Date: 03/05/18
*Modification Date:	03/05/18
*Purpose: Prompt user for five integers, use one function to return highest and lowest of the five.
*/

#include <iostream>
#include <algorithm>

using namespace std;

//Function Prototype(s)
void minMaxInts(int, int, int, int, int);

int main()
{
	//Initialize variables
	int userNum1, userNum2, userNum3, userNum4, userNum5;

	cout << "Please input 5 integers, you will then see the minimum and maximum" << endl << endl;
	cout << "Number 1 : ";
	cin >> userNum1;
	cout << "Number 2 : ";
	cin >> userNum2;
	cout << "Number 3 : ";
	cin >> userNum3;
	cout << "Number 4 : ";
	cin >> userNum4;
	cout << "Number 5 : ";
	cin >> userNum5;
	cout << endl;

	//Pass variables to functions.
	minMaxInts(userNum1, userNum2, userNum3, userNum4, userNum5);

	system("pause");
	return 0;
}

//Should really create this algorithm myself but for simplicity and to teaching calling functions I chose to use max_element
void minMaxInts(int num1, int num2, int num3, int num4, int num5)
{
	//Insert values into array
	int userSet[] = { num1, num2, num3, num4, num5 };

	cout << "The largest number is " << *max_element(userSet, userSet + 5) << endl;
	cout << "The smallest number is " << *min_element(userSet, userSet + 5) << endl;
}

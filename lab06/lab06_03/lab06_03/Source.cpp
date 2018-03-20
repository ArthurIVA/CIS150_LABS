/*
*Author: Arthur Aigeltinger IV
*Creation Date: 03/05/18
*Modification Date:	03/05/18
*Purpose: Determine winner of basketball game based on user inputted scores.
*/

#include <iostream>
#include <string>

using namespace std;

//Function Prototype
void determineWinner(int, int);

int main()
{
	//Initialize Variables
	int score1;
	int score2;

	//Ask politely for data
	cout << "This program will pass scores of a basketball game and determine the winner." << endl << endl;
	cout << "Please enter the score for Team 1: ";
	cin >> score1;
	cout << "Please enter the score for Team 2: ";
	cin >> score2;
	cout << endl;

	//Take data and crunch it.
	determineWinner(score1, score2);

	system("pause");
	return 0;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date: 03/05/18
*Modification Date:	03/05/18
*Purpose: Take score, give winner.
*/
void determineWinner(int score1, int score2)
{
	//Not a nested if since I couldn't think of how to do this with one. 
	if (score1 > score2)
	{
		cout << "Team 1 is the winner" << endl << endl;
	}
	else if (score2 > score1)
	{
		cout << "Team 2 is the winner" << endl << endl;
	}
	else
	{
		cout << "No winner winner chicken dinner! It's a tie" << endl << endl;
	}

}
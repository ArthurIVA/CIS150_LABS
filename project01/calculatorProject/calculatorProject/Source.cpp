/*
*Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Provide 10 function calculator from within the command line interface.
*/

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

//Function Prototypes
void menu();
void exitMessage();
void errorMessage();
void functionExecutions(string&, string&, string&, string&, string&, string&, string&, string&, string&, string&);
float computeSum(float num1, float num2);
float computeSub(float num1, float num2);
float computeMul(float num1, float num2);
float computeDiv(float num1, float num2);
float computeRoot(float num1, int n);
float computePower(float num1, int index);
float computePerc(float num1, float perc);
int   computeLCM(int num1, int num2);
int   computeGCD(int num1, int num2);
int   computeMod(int num1, int num2);
double verifyNum(string, bool);



int main()
{

	char choice = 0;
	float num1 = 0.0; 
	float num2 = 0.0;
	const string EXE = "Executed";
	const string NONEXE = "Function Skipped";
	string input = "";
	string didSum = NONEXE;
	string didSub = NONEXE;
	string didMul = NONEXE;
	string didDiv = NONEXE;
	string didRoot= NONEXE;
	string didPow = NONEXE;
	string didPer = NONEXE;
	string didLCM = NONEXE;
	string didGCD = NONEXE;
	string didMod = NONEXE;


	menu(); //Draw initial menu.

	do //Decision stage
	{
		cout << endl << "Please select an operation: ";
		cin >> choice;
		choice = toupper(choice); //Apply toupper() of <cctype> to handle lowercases.
		
		switch (choice)
		{
			//Addition
			case 'A': 
			{
				cout << "Please provide the first number: ";
				cin >> input;
				num1 = verifyNum(input, true);

				cout << "Please provide the second number: ";
				cin >> input;
				num2 = verifyNum(input, true);

				cout  << "Operation: " << num1 << " + " << num2 << " = " << computeSum(num1, num2) << endl;

				didSum = EXE;
				choice = 0; //Reset choice to return to decision stage.
				break;
			}
			//Subtraction
			case 'B':
			{
				cout << "Please provide the first number: ";
				cin >> input;
				num1 = verifyNum(input, true);

				cout << "Please provide the second number: ";
				cin >> input;
				num2 = verifyNum(input, true);

				cout << "Operation: " << num1 << " - " << num2 << " = " << computeSub(num1, num2) << endl;

				didSub = EXE;
				choice = 0; //Reset choice to return to decision stage.
				break;
			}
			//Multiplication
			case 'C':
			{
				cout << "Please provide the first number: ";
				cin >> input;
				num1 = verifyNum(input, true);

				cout << "Please provide the second number: ";
				cin >> input;
				num2 = verifyNum(input, true);

				cout << "Operation: " << num1 << " * " << num2 << " = " << computeMul(num1, num2) << endl;

				didMul = EXE;
				choice = 0; //Reset choice to return to decision stage.
				break; 
			}
			//Division
			case 'D':
			{
				cout << "Please provide the first number: ";
				cin >> input;
				num1 = verifyNum(input, true);

				do
				{
					cout << "Please provide the second number: ";
					cin >> input;
					num2 = verifyNum(input, true);
				} while (num2 == 0); //Loop such that divisor cannot be 0


				cout << "Operation: " << num1 << " / " << num2 << " = " << computeDiv(num1, num2) << endl;

				didDiv = EXE;
				choice = 0; //Reset choice to return to decision stage.
				break;
			}
			//Roots
			case 'E':
			{
				cout << "Please provide the number to take a root of: ";
				cin >> input;
				num1 = verifyNum(input, true);

				do
				{
					cout << "Please provide a positive, whole number root: ";
					cin >> input;
					num2 = verifyNum(input, false);
				} while (num2 < 0); //Loop such that root is positive.

				cout << "Operation: " << num2 << " root " << num1 << " = " << computeRoot(num1, num2) << endl;

				didRoot = EXE;
				choice = 0; //Reset choice to return to decision stage.
				break;
			}
			//(Austin) Powers
			case 'F':
			{
				cout << "Please provide the number to POW: ";
				cin >> input;
				num1 = verifyNum(input, true);

				do
				{
					cout << "Please provide a positive, whole number power: ";
					cin >> input;
					num2 = verifyNum(input, false);
				} while (num2 < 0); //Loop such that power is positive.

				cout << "Operation: " << num2 << " power of " << num1 << " = " << computePower(num1, num2) << endl;

				didPow = EXE;
				choice = 0; //Reset choice to return to decision stage.
				break;
			}
			//Percentage
			case 'G':
			{
				cout << "Please provide the number to take a percentage of: ";
				cin >> input;
				num1 = verifyNum(input, true);

				do
				{
					cout << "Please provide a positive percentage: ";
					cin >> input;
					num2 = verifyNum(input, true);
				} while (num2 < 0); //Loop such that power is positive.

				cout << "Operation: " << num2 << "% of " << num1 << " = " << computePerc(num1, num2) << endl;

				didPer = EXE;
				choice = 0; //Reset choice to return to decision stage.
				break;
			}
			//Least Common Multiple
			case 'H':
			{
				cout << "Please provide the first number: ";
				cin >> input;
				num1 = verifyNum(input, false);

				cout << "Please provide the second number: ";
				cin >> input;
				num2 = verifyNum(input, false);

				cout << "Operation: LCM of " << num1 << " & " << num2 << " = " << computeLCM(num1, num2) << endl;

				didLCM = EXE;
				choice = 0; //Reset choice to return to decision stage.
				break;
			}
			//Greatest Common Divisor
			case 'I':
			{
				cout << "Please provide the first number: ";
				cin >> input;
				num1 = verifyNum(input, false);

				cout << "Please provide the second number: ";
				cin >> input;
				num2 = verifyNum(input, false);

				cout << "Operation: GCD of " << num1 << " & " << num2 << " = " << computeGCD(num1, num2) << endl;

				didGCD = EXE;
				choice = 0; //Reset choice to return to decision stage.
				break; 
			}
			//Modulus
			case 'J':
			{
				cout << "Please provide the first number: ";
				cin >> input;
				num1 = verifyNum(input, false);

				cout << "Please provide the second number: ";
				cin >> input;
				num2 = verifyNum(input, false);

				cout << "Operation: " << num1 << " modulus " << num2 << " = " << computeMod(num1, num2) << endl;

				didMod = EXE;
				choice = 0; //Reset choice to return to decision stage.
				break;
			}
			//What did we do
			case 'K':
			{
				functionExecutions(didSum, didSub, didMul, didDiv, didRoot, didPow, didPer, didLCM, didGCD, didMod);
				choice = 0; //Reset choice to return to decision stage.
				break;
			}
			//gtfo
			case 'L':
			{
				exitMessage();  //Will skip over return to decision stage and exit loop.
				break;
			}
			//Redraw Menu
			case 'M':
			{
				system("CLS"); //TERRIBLE IMPLEMENTATION DO NOT DO IT LIKE THIS IN THE FUTURE.
				menu();
				choice = 0; //Reset choice to return to decision stage.
				break;
			}
			default:
			{
				errorMessage(); //left in for modularity purposes.
				choice = 0; //Reset choice to return to decision stage.
			}
		}
	}  while (choice != 'L');

	system("pause");
	return 0;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Print default menu.
*/
void menu()
{
	cout << "----------------------------------------------------------------------"	<< endl;
	cout << "                  WELCOME TO THE CALCULATOR PROJECT                   "	<< endl;
	cout << "----------------------------------------------------------------------"	<< endl;
	cout																				<< endl;
	cout << "A.) Addition"																<< endl;
	cout << "B.) Subtraction"															<< endl;
	cout << "C.) Multiplication"														<< endl;
	cout << "D.) Division"																<< endl;
	cout << "E.) Roots(only positive number)"											<< endl;
	cout << "F.) Power(only positive number)"											<< endl;
	cout << "G.) Percentage"															<< endl;
	cout << "H.) Least Common Multiplier"												<< endl;
	cout << "I.) Greatest Common Divisor"												<< endl;
	cout << "J.) Modulus"																<< endl;
	cout << "K.) Display function execution"											<< endl;
	cout << "L.) Quit"																	<< endl;
	cout << "M.) Clear Screen and Show New Menu"										<< endl;
	cout << "----------------------------------------------------------------------"	<< endl;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Print exit message.
*/
void exitMessage()
{
	cout << "Thank you for using this calculator program!" << endl;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Default error message for handling in the future.
*/
void errorMessage()
{
	//Left in for modularity purposes.
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Print execution page.
*/
void functionExecutions(string& didSum, string& didSub, string& didMul, string& didDiv, string& didRoot, string& didPow, string& didPer, string& didLCM, string& didGCD, string& didMod)
{
	system("CLS"); //As mentioned, DO NOT DO THIS IN THE FUTURE.

	cout << "----------------------------------------------------------------------"	<< endl;
	cout << "                    DISPLAYING FUNCTION EXECUTION                     "	<< endl;
	cout << "----------------------------------------------------------------------"	<< endl;
	cout << "Addition       - " << didSum												<< endl;
	cout << "Subtraction    - " << didSub												<< endl;
	cout << "Multiplication - " << didMul												<< endl;
	cout << "Division       - " << didDiv												<< endl;
	cout << "Roots          - " << didRoot												<< endl;
	cout << "Power          - " << didPow												<< endl;
	cout << "Percentage     - " << didPer												<< endl;
	cout << "LCM            - " << didLCM												<< endl;
	cout << "GCD            - " << didGCD												<< endl;
	cout << "Modulus        - " << didMod												<< endl;
	cout << "----------------------------------------------------------------------"	<< endl;
	cout																				<< endl;
	cout << "L.) Quit"																	<< endl;
	cout << "M.) Clear Screen and Show New Menu"										<< endl;

}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Add
*/
float computeSum(float num1, float num2)
{
	return num1 + num2;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Subtract
*/
float computeSub(float num1, float num2)
{
	return num1 - num2;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Multiply
*/
float computeMul(float num1, float num2)
{
	return num1 * num2;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Divide
*/
float computeDiv(float num1, float num2)
{
	return num1 / num2;
}

/*
*Function Author: PROVIDED
*Creation Date:	Unknown
*Modification Date:	03/19/18
*Purpose: Do root.
*/
float computeRoot(float root, int index)
{
	float tp, mid, low = 0.0, high = root;

	do {
		mid = (low + high) / 2;
		if (computePower(mid, index) > root)
			high = mid;
		else
			low = mid;

		mid = (low + high) / 2;
		tp = (computePower(mid, index) - root);

		if (tp < 0)
		{//grab absolute value
			tp = -tp;
		}
	} while (tp > .000005);	//accuracy of our root

	return mid;

}

/*
*Function Author: PROVIDED
*Creation Date:	Unknown
*Modification Date:	03/19/18
*Purpose: Compute Powers/Exponentials.
*/
float computePower(float x, int n)
{
	float numProduct = 1.0;
	int i;

	for (i = 0; i < n; i++)
		numProduct *= x;

	return numProduct;
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Calculate a given positive percentage of a given number.
*/
float computePerc(float num1, float perc)
{
	return num1 * (perc / 100); //Placeholder
}

/*
*Function Author: PROVIDED
*Creation Date:	Unknown
*Modification Date:	03/19/18
*Purpose: Compute Least Common Multiple.
*/
int   computeLCM(int a, int b)
{
	int tmp_lcm;
	tmp_lcm = ((a * b) / computeGCD(a, b));
	return tmp_lcm;
	return ((a * b) / computeGCD(a, b));

}

/*
*Function Author: PROVIDED
*Creation Date:	Unknown
*Modification Date:	03/19/18
*Purpose: Compute Greatest Common Divisor.
*/
int   computeGCD(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}

	return a;

}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/19/18
*Modification Date:	03/19/18
*Purpose: Compute modulus.
*/
int   computeMod(int num1, int num2)
{
	return num1 % num2; 
}

/*
*Function Author: Arthur Aigeltinger IV
*Creation Date:		03/12/18
*Modification Date:	03/12/18
*Purpose: Checks for valid integer input OR double/int input via string.
*Dependencies: #include <cctype>, #include <string>
*
//Original Example of verifyNum()
std::string input = "";
int num = 0;
std::cout << "Please enter an integer value: ";
std::cin >> input;
std::cout << std::endl;
num = verifyNum(input, true);
*/
double verifyNum(string val, bool isDouble)	//If isDouble is TRUE function checks for a double, instead of int.
{
	string input = val;			//Create string and assign it to argument string value so it can be changed in subroutines below IF user enters new value for the string.
	bool isValid = true;		//Condition to specify whether the input is registered as valid (i.e. double or int). Default = TRUE.
	bool foundDecimal = false;	//Declare boolean to determine if decimal is present.
	int i = 0;					//Iterator for the individual characters of the string.

	do  //Perform loop at least once. While the input is not a valid string or double, repeat the loop.
	{
		isValid = true;
		i = 0;

		if (isDouble == false)	//If we're checking for an integer, we run through this conditional to verify if all of our characters are digits.
		{
			while (input[i] != '\0') //While the iterator has not reached end of the string ('\0' specifies the end delimiter of the string).
			{
				if (!isdigit(input[i]))	//If letter in the current index of the iterator isn't a digit, do this.
				{
					cout << "Input is not valid, please enter a new value: ";	//User inputs a new value for our local variable INPUT, breaks back out to initial do-while loop.
					isValid = false;
					cin >> input;
					cout << endl;
					break;
				}

				i++;
			}
		}
		else if (isDouble == true)
		{
			/*
			* WHILE:
			* While the iterator has not reached end of the string ('\0' specifies the end delimiter of the string)
			* Do this.
			*/
			while (input[i] != '\0')
			{
				/*
				* IF:
				* The letter in the current index of the iterator isn't a digit NOR is it a decimal
				* OR
				* The letter in the current index of the iterator is a decimal and found a decimal previously
				* Do this.
				*/
				if ((!isdigit(input[i]) && input[i] != '.') || (input[i] == '.' && foundDecimal == true))
				{
					cout << "Input is not valid, please enter a new value: "; //User inputs a new value for our local variable INPUT, breaks back out to initial do-while loop.
					isValid = false;
					cin >> input;
					cout << endl;
					break;
				}

				else if (input[i] == '.')	//If decimal found, set foundDecimal to true.
				{
					foundDecimal = true;
				}

				i++;
			}
		}
	} while (isValid == false); //If number NOT valid, repeat do-while loop.

	if (isDouble == true)	//If valid double, output the input casted to a double.
	{
		return stod(input);
	}

	else   //If valid integer, output the input casted to a integer.
	{
		return stoi(input);
	}
}

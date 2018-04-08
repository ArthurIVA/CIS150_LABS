/*
*Author: Arthur Aigeltinger IV
*Creation Date:		04/08/18
*Modification Date:	04/08/18
*Purpose: Access class "triangle" to perform written functions and then print output with largest triangle labeled.
*/

#include "triangle.h"
#include <iomanip>
#include <iostream>

//Function Prototypes
int maxTriangle(triangle[], int);

int main()
{
	const int SIZE = 5; //Default is 5 user defined triangle to use in computation.
	triangle arrTri[SIZE];
	float input;
	int indexMax = 0;
	//Format for requesting input from user. Fed into arrTri[] of class triangle.
	std::cout << "You will be asked to the BASE and HEIGHT of Five Triangles." << std::endl;
	std::cout << "This program will subsequently calculate the area of each and determine which is the largest." << std::endl;

	//Loop to insert all inputs into array of class triangle
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << std::endl << "Base for Triangle " << i + 1 << ": ";
		std::cin >> input;
		arrTri[i].setBase(input);

		std::cout << "Height for Triangle " << i + 1 << ": ";
		std::cin >> input;
		arrTri[i].setHeight(input);

		//Take user input and compute area for triangle at index 'i'.
		arrTri[i].computeArea();
	}

	//Determine which triangle has the max area.
	indexMax = maxTriangle(arrTri, SIZE);

	//Print report of triangle sizes.
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << std::fixed << std::setprecision(2) << std::endl;
		std::cout << arrTri[i].getBase() << " x " << arrTri[i].getHeight() << " has area " << arrTri[i].getArea();
		if (indexMax == i)
		{
			std::cout << " - largest";
		} 
	}

	std::cout << std::endl << std::endl;

	system("pause");
	return 0;
}

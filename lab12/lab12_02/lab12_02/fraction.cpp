#include "fraction.h"

//Default Constructor.
fraction::fraction()
{
	numerator = 1;
	denominator = 1;
}
//Definition of template fraction.
//Replaces setNumerator() and setDenominator()
fraction::fraction(int num, int dem)
{
	numerator = num;
	denominator = dem;
}

int fraction::getNumerator()
{
	return numerator;
}

int fraction::getDenominator()
{
	return denominator;
}

//Provides styling for printing to match lab requirements.
void fraction::print()
{
	std::cout << numerator << "/" << denominator;
}

void fraction::simplify()
{
	int divisor = 0;
	while (divisor != 1)
	{
		for (int i = 1; i < 9; i++)
		{
			if (numerator % i == 0 && denominator % i == 0)
			{
				divisor = i;
			}
		}

		numerator = numerator / divisor;
		denominator = denominator / divisor;
	}
}

fraction::~fraction()
{
}

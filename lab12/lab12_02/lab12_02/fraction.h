#pragma once

#include <iostream>

class fraction
{
private:
	//Default values of 1.
	int numerator;
	int denominator;

public:
	fraction();

	fraction(int, int);

	int getNumerator()
	{
		return numerator;
	}

	int getDenominator()
	{
		return denominator;
	}
	
	void print()
	{
		std::cout << numerator << "/" << denominator;
	}

	void simplify()
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

	fraction operator+ (fraction &secondOperand)
	{
		fraction result;
		if (this->denominator == secondOperand.denominator)
		{
			result.numerator = this->numerator + secondOperand.numerator;
			result.denominator = this->denominator;
		}

		else
		{
			this->numerator = secondOperand.denominator;
			secondOperand.numerator = this->denominator;
			result.numerator = this->numerator + secondOperand.numerator;
			result.denominator = this->denominator * secondOperand.denominator;	
		}

		return result;
	}

	fraction operator- (fraction &secondOperand)
	{
		fraction result;
		if (this->denominator == secondOperand.denominator)
		{
			result.numerator = this->numerator - secondOperand.numerator;
			result.denominator = this->denominator;
		}

		else
		{
			this->numerator = secondOperand.denominator;
			secondOperand.numerator = this->denominator;
			result.numerator = this->numerator - secondOperand.numerator;
			result.denominator = this->denominator * secondOperand.denominator;
		}

		return result;
	}

	bool operator< (fraction &secondOperand)
	{
		double val1, val2;
		val1 = (double)this->numerator / (double)this->denominator;
		val2 = (double)secondOperand.numerator / (double)secondOperand.denominator;
		
		if (val1 < val2)
			return true;

		else
			return false;
	}

	bool operator> (fraction &secondOperand)
	{
		double val1, val2;
		val1 = (double)this->numerator / (double)this->denominator;
		val2 = (double)secondOperand.numerator / (double)secondOperand.denominator;

		if (val1 > val2)
			return true;

		else
			return false;
	}

	bool operator== (fraction &secondOperand)
	{
		double val1, val2;
		val1 = (double)this->numerator / (double)this->denominator;
		val2 = (double)secondOperand.numerator / (double)secondOperand.denominator;
		if (val1 == val2)
			return true;

		else
			return false;
	}

	fraction operator* (fraction &secondOperand)
	{
		fraction result;

		result.numerator = this->numerator * secondOperand.numerator;
		result.denominator = this->denominator * secondOperand.denominator;

		return result;
	}

	void operator= (fraction &secondOperand)
	{
		fraction *result = this;

		result->numerator = secondOperand.numerator;
		result->denominator = secondOperand.denominator;
	}

	~fraction();
};


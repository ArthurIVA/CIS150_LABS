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

	//Function Prototypes
	int getNumerator();
	int getDenominator();
	void print();
	void simplify();

	//Operator OVERLOADING
	// + ADDITION
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
			int num1 = this->numerator, num2 = secondOperand.numerator;
			num1 *= secondOperand.denominator;
			num2 *= this->denominator;
			result.numerator = num1 + num2;
			result.denominator = this->denominator * secondOperand.denominator;
		}

		return result;
	}

	// - SUBTRACTION
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
			int num1 = this->numerator, num2 = secondOperand.numerator;
			num1 *= secondOperand.denominator;
			num2 *= this->denominator;
			result.numerator = num1 - num2;
			result.denominator = this->denominator * secondOperand.denominator;
		}

		return result;
	}

	// < LESS THAN
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

	// > GREATER THAN
	bool operator> (fraction &secondOperand)
	{
		double val1, val2;
		val1 = (double)this->numerator / (double)this->denominator;
		val2 = (double)secondOperand.numerator / (double)secondOperand.denominator;

		if (val1 > val2)
		{
			return true;
		}
		else
		{
			return false;
		}
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
		this->numerator = secondOperand.numerator;
		this->denominator = secondOperand.denominator;
	}

	~fraction();
};


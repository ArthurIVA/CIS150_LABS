#include "desk.h"



desk::desk()
{
	//Default Constructor
	color = "Steel Blue";
	drawers = 4;

	std::cout << "\n \t Constructor Called \n";
}

//INLINE SET FUNCTIONS - not requested, left for redundancy.
void desk::setColor(std::string input)
{
	color = input;
}

void desk::setDrawers(int input)
{
	drawers = input;
}

//INLINE GET FUNCTIONS
std::string desk::getColor()
{
	return color;
}

int desk::getDrawers()
{
	return drawers;
}

//REFERENCE GET METHOD
void desk::getInfo(std::string& color, int& drawers)
{
	color = this->color;
	drawers = this->drawers;
}

std::string desk::printMe()
{
	std::string result;
	std::string numDrawers = std::to_string(drawers);

	result = "I'm a " + color + " desk with " + numDrawers + " drawers.";
	return result;
}

//Destructor - appears briefly after pause, then shutdown.
desk::~desk()
{
	std::cout << "\n \t Destructor Called \n";
}

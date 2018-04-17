#pragma once

#include <iostream>
#include <string>

class desk
{
private:

	std::string color;
	int drawers;


public:
	desk();

	void setColor(std::string);
	void setDrawers(int);
	std::string getColor();
	int getDrawers();

	void getInfo(std::string&, int&);

	std::string printMe();

	~desk();
};


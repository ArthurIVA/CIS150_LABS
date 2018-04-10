#pragma once
#include <fstream>
#include <iostream>
#include <string>

class student
{
private:
	//Default set to hold five grades, starting at 0 for all.
	int grades[5] = { 0,0,0,0,0 };
	std::string name = "";

public:
	void setStudentName(std::string); //(name [First / First & Last])
	void setStudentGrade(int, int, int); //(grade [0 - 100, possibly higher], index of grade [0-4], size of array)
	void fillInfo(std::ifstream&, int size = 5); //Contains default argument.
	std::string getStudentName(); //Returns student name.
	int getStudentGrade(int, int size = 5); //(index of grade [0-4]), size of array, returns grade and index
	float averageGrade(int size = 5); //(size of array), Returns average of all integer grades held in instance of grades[].

	student();
	~student();
};


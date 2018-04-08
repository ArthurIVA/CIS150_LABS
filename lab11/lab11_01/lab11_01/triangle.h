#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "max.h"

class triangle
{
private: 
	float base;
	float height;
	float area;

public:
	void setBase(float);
	void setHeight(float);
	float getBase();
	float getHeight();
	float getArea();
	float computeArea();

	triangle();
	~triangle();
};
#endif
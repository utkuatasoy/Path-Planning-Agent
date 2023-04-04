#pragma once
#ifndef Vector
#define Vector
#include<iostream>
#include<random>
#include<time.h>
#include <math.h>

class vector {
private:
	double x;
	double y;
	double unitVectorOfX;
	double unitVectorOfY;

public:
	vector();
	vector(double, double);
	void setX(double);
	void setY(double);
	double getX();
	double getY();
	void setUnitVectorOfX(double);
	void setUnitVectorOfY(double);
	double getUnitVectorOfX();
	double getUnitVectorOfY();
};

vector::vector() {
	this->x = -30 + (rand() % 60);
	//	agent2d'nin default bakis acisi -30 ile +30 arasinda bir deger alir.

	this->y = 1;

	this->unitVectorOfX = x / sqrt(x * x + y * y);
	this->unitVectorOfY = y / sqrt(x * x + y * y);
}

vector::vector(double x, double y) {
	this->unitVectorOfX = x / sqrt(x * x + y * y);
	this->unitVectorOfY = y / sqrt(x * x + y * y);

	this->x = x;
	this->y = y;
}

void vector::setX(double x) {
	this->x = x;
}

void vector::setY(double y) {
	this->y = y;
}

double vector::getX() {
	return this->x;
}

double vector::getY() {
	return this->y;
}
void vector::setUnitVectorOfX(double x) {
	this->unitVectorOfX = x;
}
void vector::setUnitVectorOfY(double y) {
	this->unitVectorOfY = y;
}
double vector::getUnitVectorOfX() {
	return this->unitVectorOfX;
}
double vector::getUnitVectorOfY() {
	return this->unitVectorOfY;
}

#endif // !vector

class Vector
{
};

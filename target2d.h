#pragma once
#ifndef target2d
#define target2d
#include<iostream>
#include<random>
#include<time.h>

class target {
private:
	double x;
	double y;
public:
	target();
	target(double, double);
	void setX(double);
	void setY(double);
	double getX();
	double getY();
};

target::target() {
	this->x = 35.0 + (rand() % 30);
	//	x degeri 35 ile 65 arasinda deger alir.
	this->y = 5.0;
}

target::target(double x, double y) {
	this->x = x;
	this->y = y;
}

void target::setX(double x) {
	this->x = x;
}

void target::setY(double y) {
	this->y = y;
}

double target::getX() {
	return this->x;
}

double target::getY() {
	return this->y;
}

#endif // !target
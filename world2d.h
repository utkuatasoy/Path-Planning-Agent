#pragma once
#ifndef world2d
#define world2d
#include<iostream>

class world {
private:
	double x;
	double y;
public:
	world();
	world(double, double);
};

world::world() {
	this->x = 100.0;
	this->y = 200.0;
}
world::world(double x, double y) {
	this->x = x;
	this->y = y;
}


#endif // !world2s.h

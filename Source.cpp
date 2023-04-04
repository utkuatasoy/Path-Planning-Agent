#include<iostream>
#include<time.h>
#include<random>
#include "world2d.h"
#include "agent2d.h"
#include "target2d.h"
#include "Vector.h"
#include <iostream>
#include <fstream>
#include <ctime>
using std::cout;
using std::cin;

int main() {
		srand(time(NULL));
		agent Agent = agent();
		target Target = target();
		std::cout << "----------------------------------" << std::endl;
		std::cout << "THE TRIAL HAS EXECUTED" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "At the Beginning :  Coordinate of Agent (X): " << Agent.getX() << " Agent (Y): " << Agent.getY() << std::endl;
		std::cout << "At the Beginning :  Coordinate of Target (X): " << Target.getX() << " Target (Y): " << Target.getY() << std::endl;
		std::cout << "" << std::endl;
		while (Agent.decide(Target) != 1);
		std::cout << "" << std::endl;
		std::cout << "THE TRIAL HAS FINISHED" << std::endl;
		std::cout << "----------------------------------" << std::endl;
	return 0;
}
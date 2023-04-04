#pragma once
#ifndef agent2d
#define agent2d
#include<iostream>
#include<math.h>
#include "Vector.h"
#include "target2d.h"
#include <fstream>
#include <iomanip>
#include <ctime>


class agent {
private:
	double width;
	double length;
	double x;
	double y;
	double alpha;
public:
	void setX(double);
	void setY(double);
	double getX();
	double getY();
	agent();
	agent(double, double);
	double perceive(target);
	int decide(target);
	int move(double, double);
	std::ofstream outputText;
};

agent::agent() {
	width = 5.0;
	length = 5.0;
	this->y = 190.0;
	this->x = 25.0 + (rand() % 50);
}

agent::agent(double width, double length) {
	this->width = width;
	this->length = length;

}

void agent::setX(double x) {
	this->x = x;
}

void agent::setY(double y) {
	this->y = y;
}

double agent::getX() {
	return this->x;
}

double agent::getY() {
	return this->y;
}

double agent::perceive(target Target) {

	//	Burada target'in ve agent'in x,y degerleri isleme sokularak mesafe hesaplanir.

	double tX = Target.getX();
	double tY = Target.getY();
	double xDiffSQ = pow(abs(tX - this->getX()), 2);
	double yDiffSQ = pow(abs(tY - this->getY()), 2);
	double dist = sqrt(yDiffSQ + xDiffSQ);

	return dist;

}

int agent::decide(target Target) {
	srand(time(NULL));

	double vect = perceive(Target);
	vector v1, v2;
	outputText.open("output.txt", std::ios_base::app);
	outputText << std::fixed << std::setprecision(2);

	if (vect <= 1) {

		//	Distance'in 1'den kucuk oldugu durumda agent target'a ulasmis olur ve exit burada alinir.

		outputText << "" << std::endl;
		outputText << "Agent has reached the target." << std::endl;
		outputText << "" << std::endl;
		outputText << "The Final Coordinate of Agent  (X,Y): (" << getX() << "," << getY() << ")" << std::endl;
		outputText << "The Final Coordinate of Target (X,Y): (" << Target.getX() << "," << Target.getY()<< ")" << std::endl;
		outputText << "The final distance just before the agent reaches the target: " << vect << std::endl;
		outputText << "" << std::endl;
		return 1;

	}
	else {
		v1 = vector();
		//	v1 vectoru default olarak vector'un bakis acisini -30 ile +30 arasinda deger saglatir.

		v2 = vector(getX(), getY());

		// v2 vektoru agent'in hareket yonunun birim vektorudur. Bu yuzden verilen x,y degerleriyle isleme girer.
	
	
		alpha = 0.95;

		//	v1(t) = (1 - alpha) v2(t) + (alpha) v1(t)	
		//	Asagida bu fonksiyonun koordinat degerleri alpha degeri ile hesaplanir.

		double v1_x = abs((1 - alpha) * v2.getUnitVectorOfX() + (alpha)*v1.getUnitVectorOfX());
		double v1_y = abs((1 - alpha) * v2.getUnitVectorOfY() + (alpha)*v1.getUnitVectorOfY());
		vector final = vector(v1_x, v1_y);
		if (((getX() + (v1_x * sqrt(2))) < 100) && ((getX() + (v1_x * sqrt(2))) > 0) && (getY() + (v1_y * sqrt(2)) < 200) && (getY() + (v1_y * sqrt(2)) > 0)) {
			if (Target.getY() < getY()) {
				//	agent'in target'in altinda olma durumunu hesaplar.
				move(getX(), getY() - (v1_y * sqrt(2)));
			}
			else {
				//	agent'in target'in altinda olma durumunu hesaplar. (Bu odevde gerekli degildir fakat ileride gerekli olabilir.)
				move(getX(), getY() + (v1_y * sqrt(2)));
			}
			if (Target.getX() < getX()) {
				//	agent'in target'in saginda olma durumunu hesaplar. Ve sola dogru hareket gosterir.
				move((getX() - (v1_x * sqrt(2))), getY());
			}
			else {
				//	agent'in target'in solunda olma durumunu hesaplar. Ve saga dogru hareket gosterir.
				move((getX() + (v1_x * sqrt(2))), getY());
			}
		}
		outputText << "Agent1 coords: (" << this->getX() << "," << this->getY() <<")"<< "   Agent2 coords: (" << Target.getX() << "," << Target.getY()  << ")  distance: " << perceive(Target) << std::endl;
	}
	outputText.close();
	return 0;
}

int agent::move(double newX, double newY) {

	//	Gerekli move degiskenleri decide methodunda yollanir, move methodunda ise agent'in koordinatlari burada set edilir.

	this->setX(newX);
	this->setY(newY);
	
	return 0;
}
#endif // !agent2d

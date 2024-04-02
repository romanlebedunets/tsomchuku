#pragma once
#include "Shape.h"
class Circle : public Shape {
protected:
	double radius;
public:
	Circle() : radius(1.) {}
	Circle(double R) { 
		radius = (R > 0.1) ? R : 0.1; 
	}
	Circle(const Circle& C) : radius(C.radius) {}
	virtual~Circle() {}

	double per() const override { return 2 * Pi * radius; }
	double area() const override { return Pi * pow(radius, 2); }

	virtual void setR(double R) { radius = (R > 0.1) ? R : 0.1; }

	void in(istream& is) override {
		is >> radius;
	}
	void out(ostream& os) override {
		os << "Circle  r: " << radius << "\ntArea: " << area() << "\tPer: " << per();
	}
};


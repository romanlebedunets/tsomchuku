#pragma once
#include "Shape.h"
class Circle : public Shape {
protected:
	double r;
public:
	Circle() : r(1.) {}
	Circle(double R) { 
		r = (R > 0.1) ? R : 0.1; 
	}
	Circle(const Circle& C) : r(C.r) {}
	virtual~Circle() {}

	double per() const override { return 2 * Pi * r; }
	double area() const override { return Pi * pow(r, 2); }

	virtual void setR(double R) { r = (R > 0.1) ? R : 0.1; }

	void in(istream& is) override {
		is >> r;
	}
	void out(ostream& os) override {
		os << "Circle  r: " << r << "\ntArea: " << area() << "\tPer: " << per();
	}
};


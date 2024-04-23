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
	~Circle() override {}

	double per() const override { return 2 * Pi * radius; }
	double area() const override { return Pi * radius * radius; }

	double getR() const { return radius; }

	Shape* clone() const override {
		return new Circle(*this);
	}

	void in(istream& is) override {
		is >> radius;
	}
	void out(ostream& os) const override {
		os << "Circle  r: " << radius << "\n\tbaseArea: " << area() << "\t\tbasePer: " << per();
	}
};


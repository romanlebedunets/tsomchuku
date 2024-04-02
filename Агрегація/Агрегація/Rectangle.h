#pragma once
#include "Shape.h"
class Rectangle : public Shape {
protected:
	double a, b;
public:
	Rectangle() : a(1.), b(1.) {}
	Rectangle(double A, double B) {
		a = (A > 0.1) ? A : 0.1;
		b = (B > 0.1) ? B : 0.1;
	}
	Rectangle(const Rectangle& R) : a(R.a), b(R.b) {}
	virtual~Rectangle() {}

	double per() const override { return a + b ; }
	double area() const override { return a * b; }

	virtual void setA(double A) { a = (A > 0.1) ? A : 0.1; }
	virtual void setB(double B) { b = (B > 0.1) ? B : 0.1; }

	void in(istream& is) override {
		is >> a >> b;
	}
	void out(ostream& os) override {
		os << "Rectangle  a: " << a << "\tb: " << b << "\ntArea: " << area() << "\tPer: " << per();
	}
};


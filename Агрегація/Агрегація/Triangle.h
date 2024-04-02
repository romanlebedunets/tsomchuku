#pragma once
#include "Shape.h"
class Triangle : public Shape {
protected:
	double a, b, c;
public:
	Triangle() : a(1.), b(1.), c(1.) {}
	Triangle(double A, double B, double C) {
		a = (A > 0.1) ? A : 0.1;
		b = (B > 0.1) ? B : 0.1;
		c = (C > 0.1) ? C : 0.1;
	}
	Triangle(const Triangle& T) : a(T.a), b(T.b), c(T.c) {}
	virtual~Triangle() {}

	bool exist() const {
		return a + b > c && a + c > b && b + c > a;
	}

	double per() const override { return a + b + c; }
	double area() const override { return sqrt((per() / 2) * (per() / 2 - a) * (per() / 2 - b) * (per() / 2 - c)); }

	virtual void setA(double A) { a = (A > 0.1) ? A : 0.1; }
	virtual void setB(double B) { b = (B > 0.1) ? B : 0.1; }
	virtual void setC(double C) { c = (C > 0.1) ? C : 0.1; }

	void in(istream& is) override {
		is >> a >> b >> c;
	}
	void out(ostream& os) override {
		os << "Triangle  a: " << a << "\tb: " << b << "\tc: " << c << "\ntArea: " << area() << "\tPer: " << per();
	}
};
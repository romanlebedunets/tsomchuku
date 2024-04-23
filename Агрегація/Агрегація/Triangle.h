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
	~Triangle() override {}

	bool isExist() const {
		return a + b > c && a + c > b && b + c > a;
	}

	double per() const override { return a + b + c; }
	double area() const override { return sqrt((per() / 2) * (per() / 2 - a) * (per() / 2 - b) * (per() / 2 - c)); }

	double getA() const { return a;	}
	double getB() const { return b; }
	double getC() const { return c; }

	Shape* clone() const override {
		return new Triangle(*this);
	}

	void in(istream& is) override {
		is >> a >> b >> c;
	}
	void out(ostream& os) const override {
		if (!isExist()) {
			os << "Triangle is invalid!" << endl;
			return;
		}
		os << "triangle  a: " << a << "\tb: " << b << "\tc: " << c << "\n\tbaseArea: " << area() << "\t\tbasePer: " << per();
	}
};
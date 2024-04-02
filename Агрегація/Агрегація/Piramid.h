#pragma once
#include "Triangle.h"
class Piramid : public Triangle {
private:
	double height;
public:
	Piramid() : Triangle(), height(1.) {}
	Piramid(double A, double B, double C, double H) : Triangle(A, B, C) { 
		height = (H > 0) ? H : 0.1; 
	}
	Piramid(const Piramid& P) : Triangle(P), height(P.height) {}
	virtual~Piramid() {}

	double volume() const override {
		return 0.33 * area() * height;
	}
	double sideArea() const override {
		return 0.5 * per() * height;
	}
	double surfaceArea() const override {
		return area() + sideArea();
	}

	void setH(double H) {
		height = (H > 0.1) ? H : 0.1;
	}

	void in(istream& is) override {
		is >> a >> b >> c >> height;
	}
	void out(ostream& os) override {
		os << "Piramid  a: " << a << "\tb: " << b << "\tc: " << c << "\tHeight:" << height << "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};


#pragma once
#include "Triangle.h"
class Piramid : public Triangle {
private:
	double h;
public:
	Piramid() : Triangle(), h(1.) {}
	Piramid(double A, double B, double C, double H) : Triangle(A, B, C) { 
		h = (H > 0) ? H : 0.1; 
	}
	Piramid(const Piramid& P) : Triangle(P), h(P.h) {}
	virtual~Piramid() {}

	double volume() const {
		return 0.33 * area() * h;
	}
	double sideArea() const {
		return 0.5 * per() * h;
	}
	double surfaceArea() const {
		return area() + sideArea();
	}

	void setH(double H) {
		h = (H > 0.1) ? H : 0.1;
	}

	void in(istream& is) override {
		is >> a >> b >> c >> h;
	}
	void out(ostream& os) override {
		os << "Piramid  a: " << a << "\tb: " << b << "\tc: " << c << "\th:" << h << "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};


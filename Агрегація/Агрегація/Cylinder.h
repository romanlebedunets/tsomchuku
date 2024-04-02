#pragma once
#include "Circle.h"
class Cylinder : public Circle {
private:
	double h;
public:
	Cylinder() : Circle(), h(1.) {}
	Cylinder(double R, double H) : Circle(R) {
		h = (H > 0) ? H : 0.1;
	}
	Cylinder(const Cylinder& Ñ) : Circle(Ñ), h(Ñ.h) {}
	virtual~Cylinder() {}

	double volume() const {
		return area() * h;
	}
	double sideArea() const {
		return per() * h;
	}
	double surfaceArea() const {
		return 2 * area() + sideArea();
	}

	void setH(double H) {
		h = (H > 0.1) ? H : 0.1;
	}

	void in(istream& is) override {
		is >> r >> h;
	}
	void out(ostream& os) override {
		os << "Cylinder  r: " << r << "\th:" << h << "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};


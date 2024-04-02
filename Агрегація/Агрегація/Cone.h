#pragma once
#include "Circle.h"
class Cone : public Circle {
private:
	double h;
public:
	Cone() : Circle(), h(1.) {}
	Cone(double R, double H) : Circle(R) {
		h = (H > 0) ? H : 0.1;
	}
	Cone(const Cone& Ñ) : Circle(Ñ), h(Ñ.h) {}
	virtual~Cone() {}

	double volume() const {
		return 0.33 * area() * h;
	}
	double sideArea() const {
		return Pi * r * sqrt(h * h + r * r);
	}
	double surfaceArea() const {
		return area() + sideArea();
	}

	void setH(double H) {
		h = (H > 0.1) ? H : 0.1;
	}

	void in(istream& is) override {
		is >> r >> h;
	}
	void out(ostream& os) override {
		os << "Cone  r: " << r << "\th:" << h << "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};


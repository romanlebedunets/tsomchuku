#pragma once
#include "Circle.h"
class Cone : public Circle {
private:
	double height;
public:
	Cone() : Circle(), height(1.) {}
	Cone(double R, double H) : Circle(R) {
		height = (H > 0) ? H : 0.1;
	}
	Cone(const Cone& Ñ) : Circle(Ñ), height(Ñ.height) {}
	virtual~Cone() {}

	double volume() const override {
		return 0.33 * area() * height;
	}
	double sideArea() const override {
		return Pi * radius * sqrt(height * height + radius * radius);
	}
	double surfaceArea() const override {
		return area() + sideArea();
	}

	void setH(double H) {
		height = (H > 0.1) ? H : 0.1;
	}

	void in(istream& is) override {
		is >> radius >> height;
	}
	void out(ostream& os) override {
		os << "Cone  r: " << radius << "\tHeight:" << height << "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};


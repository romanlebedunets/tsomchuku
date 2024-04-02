#pragma once
#include "Circle.h"
class Cylinder : public Circle {
private:
	double height;
public:
	Cylinder() : Circle(), height(1.) {}
	Cylinder(double R, double H) : Circle(R) {
		height = (H > 0) ? H : 0.1;
	}
	Cylinder(const Cylinder& Ñ) : Circle(Ñ), height(Ñ.height) {}
	virtual~Cylinder() {}

	double volume() const override {
		return area() * height;
	}
	double sideArea() const override {
		return per() * height;
	}
	double surfaceArea() const override {
		return 2 * area() + sideArea();
	}

	void setH(double H) {
		height = (H > 0.1) ? H : 0.1;
	}

	void in(istream& is) override {
		is >> radius >> height;
	}
	void out(ostream& os) override {
		os << "Cylinder  r: " << radius << "\tHeight:" << height << "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};


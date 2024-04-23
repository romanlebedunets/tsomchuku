#pragma once
#include "Circle.h"
#include "volum_shape.h"

class Cylinder : public volumeShape {
public:
	Cylinder(double R = 0, double H = 0) : volumeShape((new Circle(R)), H) {}
	~Cylinder() override {}

	double volume() const override {
		return base->area() * height;
	}
	double sideArea() const override {
		return base->per() * height;
	}
	double surfaceArea() const override {
		return 2 * baseArea() + sideArea();
	}

	volumeShape* clone() const override {
		return new Cylinder(*this);
	}

	void in(istream& is) override {
		base->in(is);
		is >> height;
	}
	void out(ostream& os) const override {
		os << "Cylinder:\nBase: ";
		base->out(os);
		os << "\n\tVolume: " << volume() << "\t\tSideArea: " << sideArea() << "\t\tSurfaceArea: " << surfaceArea();
	}
};


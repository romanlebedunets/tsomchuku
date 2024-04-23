#pragma once
#include "Rectangle.h"
#include "volum_shape.h"

class Parallelepiped : public volumeShape {
public:
	Parallelepiped(double A = 0, double B = 0, double H = 0) : volumeShape((new Rectangle(A, B)), H) {}
	~Parallelepiped() override {}

	double volume() const override {
		return baseArea() * height;
	}
	double sideArea() const override {
		return basePer() * height;
	}
	double surfaceArea() const override {
		return 2 * baseArea() + sideArea();
	}

	volumeShape* clone() const override {
		return new Parallelepiped(*this);
	}

	void in(istream& is) override {
		base->in(is);
		is >> height;
	}
	void out(ostream& os) const override {
		os << "Parallelepiped:\nBase: ";
		base->out(os);
		os	<< "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};


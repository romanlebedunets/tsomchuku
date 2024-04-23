#pragma once
#include "Triangle.h"
#include "volum_shape.h"

class Piramid : public volumeShape {
public:
	Piramid(double A = 0, double B = 0, double C = 0, double H = 0) : volumeShape((new Triangle(A, B, C)), H) {}
	~Piramid() override {}

	double volume() const override {
		return 0.33 * baseArea() * height;
	}
	double sideArea() const override {
		return 0.5 * basePer() * height;
	}
	double surfaceArea() const override {
		return baseArea() + sideArea();
	}

	volumeShape* clone() const override {
		return new Piramid(*this);
	}

	void in(istream& is) override {
		base->in(is);
		is >> height;
	}
	void out(ostream& os) const override {
		if (!dynamic_cast<Triangle*>(base)->isExist()) {
			os << "Base triangle is invalid!" << endl;
			return;
		}
		os << "Piramid:\nBase: ";
		base->out(os);
		os << "\n\tVolume: " << volume() << "\t\tSideArea: " << sideArea() << "\t\tSurfaceArea: " << surfaceArea();
	}
};


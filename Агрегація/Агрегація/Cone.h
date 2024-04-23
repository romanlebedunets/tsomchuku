#pragma once
#include "Circle.h"
#include "volum_shape.h"

class Cone : public volumeShape {
public:
	Cone(double R = 0, double H = 0) : volumeShape((new Circle(R)), H) {}
	~Cone() override {}

	double volume() const override {
		return 0.33 * baseArea() * height;
	}
	double sideArea() const override {
		double R = dynamic_cast<Circle*>(base)->getR();
		return Pi * R * sqrt(height * height + R * R);
	}
	double surfaceArea() const override {
		return baseArea() + sideArea();
	}

	volumeShape* clone() const override {
		return new Cone(*this);
	}

	void in(istream& is) override {
		base->in(is);
		is >> height;
	}
	void out(ostream& os) const override {
		os << "Cone:\nBase: ";
		base->out(os);
		os << "\n\tVolume: " << volume() << "\t\tSideArea: " << sideArea() << "\t\tSurfaceArea: " << surfaceArea();
	}
};


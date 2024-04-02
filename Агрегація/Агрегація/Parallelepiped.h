#pragma once
#include "Rectangle.h"
class Parallelepiped : public Rectangle {
private:
	double height;
public:
	Parallelepiped() : Rectangle(), height(1.) {}
	Parallelepiped(double A, double B, double H) : Rectangle(A, B) {
		height = (H > 0) ? H : 0.1;
	}
	Parallelepiped(const Parallelepiped& P) : Rectangle(P), height(P.height) {}
	virtual~Parallelepiped() {}

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
		is >> a >> b >> height;
	}
	void out(ostream& os) override {
		os << "Parallelepiped  a: " << a << "\tb: " << b << "\tHeight:" << height << "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};


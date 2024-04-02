#pragma once
#include "Rectangle.h"
class Parallelepiped : public Rectangle {
private:
	double h;
public:
	Parallelepiped() : Rectangle(), h(1.) {}
	Parallelepiped(double A, double B, double H) : Rectangle(A, B) {
		h = (H > 0) ? H : 0.1;
	}
	Parallelepiped(const Parallelepiped& P) : Rectangle(P), h(P.h) {}
	virtual~Parallelepiped() {}

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
		is >> a >> b >> h;
	}
	void out(ostream& os) override {
		os << "Parallelepiped  a: " << a << "\tb: " << b << "\th:" << h << "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};


#pragma once
#include "Shape.h"

class volumeShape {
protected:
	Shape* base;
	double height;
public:
	volumeShape(Shape* b = nullptr, double H = 0.0) : base(b), height(H) {}
	volumeShape(const volumeShape& V) : base(V.base->clone()), height(V.height) {}
	virtual~volumeShape() { delete base; }

	virtual void in(istream& is) abstract;
	virtual void out(ostream& os) const abstract;

	virtual double basePer() const { return base->per(); };
	virtual double baseArea() const { return base->area(); }

	void setH(double H) {
		height = (H > 0.1) ? H : 0.1;
	}
	double getH() const { return height; }
	virtual volumeShape* clone() const abstract;

	virtual double volume() const abstract;
	virtual double sideArea() const abstract;
	virtual double surfaceArea() const abstract;

	friend istream& operator>>(istream& is, volumeShape& S) {
		S.in(is);
		return is;
	}
	friend ostream& operator<<(ostream& os, const volumeShape& S) {
		S.out(os);
		return os;
	}
};
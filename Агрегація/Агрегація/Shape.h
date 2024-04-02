#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const double Pi = 3.14;

class Shape {
public:
	virtual~Shape() {}

	virtual void in(istream&) abstract;
	virtual void out(ostream&) abstract;

	virtual double per() const abstract;
	virtual double area() const abstract;
	virtual double volume() const abstract;
	virtual double sideArea() const abstract;
	virtual double surfaceArea() const abstract;

	friend istream& operator>>(istream& is, Shape& S) {
		S.in(is);
		return is;
	}
	friend ostream& operator<<(ostream& os, Shape& S) {
		S.out(os);
		return os;
	}
};


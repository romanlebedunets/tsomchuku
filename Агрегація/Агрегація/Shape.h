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
	virtual void out(ostream&) const abstract;

	virtual double per() const abstract;
	virtual double area() const abstract;

	virtual Shape* clone() const abstract;

	friend istream& operator>>(istream& is, Shape& S) {
		S.in(is);
		return is;
	}
	friend ostream& operator<<(ostream& os, const Shape& S) {
		S.out(os);
		return os;
	}
};
#pragma once
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Piramid.h"
#include "Cone.h"

class Shapes {
	int size;
	vector<Shape*> Shapess;
public:
	Shapes() : size(0) {}
	Shapes(int s) : size(s) {}
	Shapes(const Shapes& S) : size(S.size) {
		Shapess.reserve(S.Shapess.size());
		for (Shape* shape : S.Shapess) {
			Shapess.push_back(copy(shape));
		}
	}
	~Shapes() {
		for (Shape* i : Shapess) {
			delete i;
		}
		Shapess.clear();
	}

	bool isEmpty() const;
	void add(size_t, Shape*);
	void pop(size_t);
	void deleteAll();

	Shape* copy(Shape*) const;

	void operator=(const Shapes&);
	Shape* operator[](size_t);

	friend istream& operator>>(istream&, Shapes&);
	friend ostream& operator<<(ostream&, const Shapes&);
};


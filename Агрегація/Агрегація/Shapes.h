#pragma once
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Piramid.h"
#include "Cone.h"
class Shapes {
	int size;
	vector<volumeShape*> mem;
	void checkInd(int i) const { 
		if (i < 0 || i >= size) {
			cerr << "Error: Invalid index " << i << endl;
			exit(-1);
		}
	}
public:
	Shapes() : size(0) {}
	Shapes(vector<volumeShape*>);
	Shapes(const Shapes& S);
	~Shapes();

	bool isEmpty() const;
	void add(int, volumeShape*);
	void pop(int);
	void deleteAll();

	volumeShape* copy(volumeShape*) const;

	Shapes& operator=(const Shapes&);
	volumeShape*& operator[](int);
	const volumeShape* operator[](int) const;

	friend istream& operator>>(istream&, Shapes&);
	friend ostream& operator<<(ostream&, const Shapes&);

	typedef void Action(volumeShape*);
	void doEach(Action f) const {
		for (int i = 0; i < size; i++) f(mem[i]);
	}
	typedef bool Predicate(volumeShape*);
	int detectFirst(Predicate condition) const {
		int i = 0;
		for (; i < size; i++)
			if (condition(mem[i])) break;
		return i;
	}
};



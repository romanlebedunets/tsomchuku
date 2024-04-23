#include "Shapes.h"

Shapes::Shapes(vector<volumeShape*> v) : size(v.size()) {
	for (auto shape : v) {
		mem.emplace_back(shape->clone());
	}
}

Shapes::Shapes(const Shapes& S) : size(S.size) {
	for (auto shape : S.mem) {
		mem.emplace_back(shape->clone());
	}
}

Shapes::~Shapes() {
	for (auto it = mem.begin(); it != mem.end(); it++) {
		delete* it;
	}
}

bool Shapes::isEmpty() const {
	return size > 0;
}

void Shapes::add(int index, volumeShape* S) {
	checkInd(index);
	mem.emplace(mem.begin() + index, S);
}

void Shapes::pop(int index) {
	checkInd(index);
	mem.erase(mem.begin() + index);
}

void Shapes::deleteAll() {
	size = 0;
	for (auto it = mem.begin(); it != mem.end(); it++) {
		delete* it;
	}
	mem.clear();
}

Shapes& Shapes::operator=(const Shapes& S) {
	if (this == &S)
		return *this;

	deleteAll();

	for (auto shape : S.mem) {
		mem.emplace_back(shape->clone());
	}

	return *this;
}


volumeShape*& Shapes::operator[](int index) {
	checkInd(index);
	return mem[index];
}

const volumeShape* Shapes::operator[](int index) const {
	checkInd(index);
	return mem[index];
}

volumeShape* Shapes::copy(volumeShape* v) const {
	if (v == nullptr) {
		return nullptr;
	}

	volumeShape* copiedShape = nullptr;

	if (typeid(*v) == typeid(Cylinder))
		copiedShape = new Cylinder(*dynamic_cast<Cylinder*>(v));
	else if (typeid(*v) == typeid(Parallelepiped))
		copiedShape = new Parallelepiped(*dynamic_cast<Parallelepiped*>(v));
	else if (typeid(*v) == typeid(Cone))
		copiedShape = new Cone(*dynamic_cast<Cone*>(v));
	else if (typeid(*v) == typeid(Piramid))
		copiedShape = new Piramid(*dynamic_cast<Piramid*>(v));
	else {
		cout << "Unknown type!" << endl;
	}

	return copiedShape;
}

istream& operator>>(istream& is, Shapes& S) {
	is >> S.size;
	string type;
	for (size_t i = 0; i < S.size; i++) {
		is >> type;
		if (type == "cone") {
			Cone* temp = new Cone;
			is >> *temp;
			S.add(i, temp);
		}
		else if (type == "cylinder") {
			Cylinder* temp = new Cylinder;
			is >> *temp;
			S.add(i, temp);
		}
		else if (type == "paralel") {
			Parallelepiped* temp = new Parallelepiped;
			is >> *temp;
			S.add(i, temp);
		}
		else if (type == "piramid") {
			Piramid* temp = new Piramid;
			is >> *temp;
			S.add(i, temp);
		}
		else {
			cout << "Unknown type, try again!" << endl;
			i--;
		}
	}
	return is;
}
ostream& operator<<(ostream& os, const Shapes& S) {
	if (!S.isEmpty()) {
		os << "Array is empty!" << endl;
		return os;
	}

	for (auto i : S.mem) {
		os << *i << endl;
	}
	return os;
}
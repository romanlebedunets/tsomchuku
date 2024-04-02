#include "Shapes.h"

bool Shapes::isEmpty() const {
	return size > 0;
}
void Shapes::add(size_t index, Shape* S) {
	if (index > size || index < 0) {
		cout << "Invalid index!" << endl;
		return;
	}
	Shapess.insert(Shapess.begin() + index, S);
}
void Shapes::pop(size_t index) {
	if (index >= size || index < 0) {
		cout << "Invalid index!" << endl;
		return;
	}
	Shapess.erase(Shapess.begin() + index);
}
void Shapes::deleteAll() {
	size = 0;
	for (Shape* i : Shapess) {
		delete i;
	}
	Shapess.clear();
}

void Shapes::operator=(const Shapes& S) {
	size = S.size;
	for (Shape* i : Shapess) {
		delete i;
	}
	Shapess.clear();

	Shapess.reserve(S.Shapess.size());
	for (Shape* shape : S.Shapess) {
		Shapess.push_back(copy(shape));
	}
}
Shape* Shapes::operator[](size_t index) {
	if (index >= size || index < 0) {
		cout << "Invalid index!" << endl;
		exit(-1);
	}
	return Shapess[index];
}

Shape* Shapes::copy(Shape* v) const {
	if (v == nullptr) {
		return nullptr;
	}

	Shape* copiedShape = nullptr;

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

	for (Shape* i : S.Shapess) {
		os << *i << endl;
	}
	return os;
}
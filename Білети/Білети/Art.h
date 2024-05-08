#pragma once
#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

template <typename T>
class Art
{
protected:
	T cost;
	int coount;
	string genre;
public:
	Art() :cost(0), coount(0), genre("lox") {}
	Art(T co, int cou, string ge) : cost(co), coount(cou), genre(ge) {}
	Art(const Art& A) :coount(A.coount), cost(A.cost), genre(A.genre) {}

	void Name(ostream& os) const {
		os << "Name class: " << typeid(*this).name() << "\n\t";
	}
	virtual double costOne() const {
		return cost / coount;
	}

	void setCount(int data) {	coount += data; }
	void setCost(T data) { cost += data; }
	string getGenre() const { return genre; }
	int getCount() const { return coount; }

	bool operator > (const Art& A) const {
		return cost > A.cost;
	}

	virtual void print(ostream& os) const {
		os << "Cost: " << cost << "\tCount: " << coount << "\tGenre: " << genre << endl;
	}
	virtual void input(istream& is) {
		is >> cost >> coount >> genre;
	}

	friend istream& operator >> (istream& is, Art& A) {
		A.input(is);
		return is;
	}
	friend ostream& operator << (ostream& os, const Art& A) {
		A.Name(os);
		A.print(os);
		return os;
	}
};

template <typename T>
class UniqueArt : public Art<T>
{
private:
	pair<string, T> Object;
	string nameBoss;
public:
	UniqueArt() : Art<T>(), nameBoss("-") {
		Object.first = "-";
		Object.second = 0;
	}
	UniqueArt(string NB, T co, int cou, string ge, pair<string, T> Ob) : Art<T>(co, cou, ge), nameBoss(NB), Object(Ob) {}
	UniqueArt(const UniqueArt& U) : Art<T>(U), nameBoss(U.nameBoss) {
		Object.first = U.Object.first;
		Object.second = U.Object.second;
	}

	double costOne() const override {
		return Object.second;
	}

	void SetPrice(int data) { Object.second = data; }

	void input(istream& is) override {
		is >> this->cost >> this->coount >> this->genre;
		is >> nameBoss >> Object.first >> Object.second;

	}
	void print(ostream& os) const override {
		os << "Cost: " << this->cost << "\tCount: " << this->coount << "\tGenre: " << this->genre << "\tNameBoss: " << nameBoss 
			<< "\n\tNameOne: " << Object.first << "\tPriceOne: " << Object.second << endl;
	}
};
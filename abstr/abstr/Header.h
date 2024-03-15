#pragma once
#include <iostream>
using namespace std;

class progres {
public:
	virtual~progres() {}

	virtual double sum() const abstract;
	virtual void in(istream&) abstract;
	virtual void out(ostream&) const abstract;

	friend istream& operator>>(istream& is, progres* P) {
		P->in(is);
		return is;
	}
	friend ostream& operator<<(ostream& os, const progres* P) {
		P->out(os);
		return os;
	}
};

class infProg : public progres {
private:
	double a;
	double q;
public:
	infProg() : a(1), q(1) {}
	infProg(double A, double Q) : a(A), q(Q) {}
	infProg(const infProg* i) : a(i->a), q(i->q) {}
	virtual ~infProg() {};

	double sum() const override {
		if (abs(q) < 1) {
			return a / (1 - q);
		}
		else {
			return numeric_limits<double>::infinity();
		}
	}
	void in(istream& is) override {
		is >> a >> q;
	}
	void out(ostream& os) const override {
		os << "First num of infProg: " << a << "\t\tDenominator: " << q << "\t\tSum: " << sum() << endl;
	}
};

class endProg : public progres {
private:
	double a;
	double q;
	int n;
public:
	endProg() : a(1), q(1), n(0) {}
	endProg(double A, double Q, int N) : a(A), q(Q), n(N) {}
	endProg(const endProg* e) : a(e->a), q(e->q), n(e->n) {}
	virtual ~endProg() {}

	double sum() const override {
		if (n <= 0) return 0;
		return a * (1 - pow(q, n)) / (1 - q);
	}
	void in(istream& is) override {
		is >> a >> q >> n;
	}
	void out(ostream& os) const override {
		os << "First num of endProg: " << a << "\t\tDenominator: " << q << "\t\tCount: " << n << "\t\tSum: " << sum() << endl;
	}
};
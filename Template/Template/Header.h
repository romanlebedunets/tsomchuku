#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

template <class type> class Matrix {
private:
	int rows, cols;
	type** arr;

public:
	Matrix() : rows(0), cols(0), arr(nullptr) {};
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();

	void setEl(size_t, size_t, type);

	double norm() const;
	type maxEl() const;

	template <typename type> friend istream& operator>>(istream&, Matrix<type>&);
	template <typename type> friend ostream& operator<<(ostream&, const Matrix<type>&);
};

#include "Header.h"

void clear(const string namefile) {
	ofstream out(namefile);
	if (!out.is_open()) {
		cout << "Error opening file!" << endl;
		exit(-1);
	}
	out.close();
}

int** fill(int n, int m) {
	int** ma = new int* [n];
	for (size_t i = 0; i < n; i++) {
		ma[i] = new int[m];
	}

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			ma[i][j] = rand() % 10;
		}
	}

	return ma;
}
void display(const string namefile, int** arr, int n, int m) {
	ofstream out(namefile, ios::app);
	if (!out.is_open()) {
		cout << "Error opening file!" << endl;
		exit(-1);
	}
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			out << arr[i][j] << " ";
		}
		out << endl;
	}
	out << endl;

	out.close();
}

void deleteM(int** m, int n) {
	for (size_t i = 0; i < n; i++) {
		delete[] m[i];
	}
	delete[] m;
}

int** standartMult(int** arr1, int n1, int m1, int** arr2, int n2, int m2) {
	if (m1 != n2) {
		cout << "Incorrect matrix`s size!" << endl;
		exit(-1);
	}

	int** result = new int* [n1];
	for (size_t i = 0; i < n1; i++) {
		result[i] = new int[m2];
	}

	for (size_t i = 0; i < n1; i++) {
		for (size_t j = 0; j < m2; ++j) {
			result[i][j] = 0;
			for (size_t k = 0; k < m1; k++) {
				result[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}

	return result;
}

int** grapeMult(int** arr1, int n1, int m1, int** arr2, int n2, int m2) {
	if (m1 != n2) {
		cout << "Incorrect matrix`s size!" << endl;
		exit(-1);
	}

	int* rowFactor = new int[n1];
	int* colFactor = new int[m2];

	int** result = new int* [n1];
	for (size_t i = 0; i < n1; i++) {
		result[i] = new int[m2];
	}

	// Розрахунок факторів для кожного рядка першої матриці та кожного стовпця другої матриці
	for (size_t i = 0; i < n1; i++) {
		rowFactor[i] = 0;
		for (size_t j = 0; j < m1 / 2; j++) {
			rowFactor[i] += arr1[i][2 * j] * arr1[i][2 * j + 1];
		}
	}

	for (size_t i = 0; i < m2; i++) {
		colFactor[i] = 0;
		for (size_t j = 0; j < n2 / 2; j++) {
			colFactor[i] += arr2[2 * j][i] * arr2[2 * j + 1][i];
		}
	}

	// Множення матриць
	for (size_t i = 0; i < n1; i++) {
		for (size_t j = 0; j < m2; j++) {
			result[i][j] = -rowFactor[i] - colFactor[j];
			for (int k = 0; k < m1 / 2; ++k) {
				result[i][j] += (arr1[i][2 * k + 1] + arr2[2 * k][j]) * (arr1[i][2 * k] + arr2[2 * k + 1][j]);
			}
		}
	}

	// Виправлення для матриць з непарною кількістю стовпців або рядків
	if (m1 % 2 != 0) {
		for (size_t i = 0; i < n1; i++) {
			for (size_t j = 0; j < m2; j++) {
				result[i][j] += arr1[i][m1 - 1] * arr2[m1 - 1][j];
			}
		}
	}

	delete[] rowFactor;
	delete[] colFactor;

	return result;
}
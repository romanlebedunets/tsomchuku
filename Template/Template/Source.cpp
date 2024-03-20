#include "Header.h"

template <typename type> Matrix<type>::Matrix(int n, int m) : rows(n), cols(m) {
	if (rows <= 0 || cols <= 0) {
		cout << "Invalid size!" << endl;
		exit(-1);
	}

	arr = new type * [n];
	for (size_t i = 0; i < n; i++) {
		arr[i] = new type[m];
	}
}

template <typename type> Matrix<type>::Matrix(const Matrix& M) : rows(M.rows), cols(M.cols) {
	arr = new type * [rows];
	for (size_t i = 0; i < rows; i++) {
		arr[i] = new type[cols];

		for (size_t j = 0; j < cols; j++) {
			arr[i][j] = M.arr[i][j];
		}
	}
}

template <typename type> Matrix<type>::~Matrix() {
	for (size_t i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

template <typename type> void Matrix<type>::setEl(size_t index1, size_t index2, type el) {
	if (index1 >= rows || index2 >= cols) {
		cout << "Error set element!" << endl;
		return;
	}
	arr[index1][index2] = el;
}

template <typename type> double Matrix<type>::norm() const {
	if (arr == nullptr || rows <= 0 || cols <= 0) {
		cout << "Zero elemets in matrix!" << endl;
		return 0;
	}

	double norm = 0.0;
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			norm += static_cast<double>(arr[i][j]) * static_cast<double>(arr[i][j]);
		}
	}
	return sqrt(norm);
}
template <typename type> type Matrix<type>::maxEl() const {
	if (arr == nullptr || rows <= 0 || cols <= 0) {
		cout << "Zero elemets in matrix!" << endl;
		return 0;
	}

	type max = arr[0][0];
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
	}
	return max;
}

template <typename type> istream& operator>>(istream& is, Matrix<type>& M) {
	if (!(is >> M.rows >> M.cols)) {
		cout << "Invalid size!" << endl;
		exit(-1);
	}

	M.arr = new type * [M.rows];
	for (size_t i = 0; i < M.rows; i++) {
		M.arr[i] = new type[M.cols];

		for (size_t j = 0; j < M.cols; j++) {
			if (!(is >> M.arr[i][j])) M.arr[i][j] = 0;
		}
	}
	return is;
}

template <typename type> ostream& operator<<(ostream& os, const Matrix<type>& M) {
	if (M.arr == nullptr) {
		cout << "Matrix is empty!" << endl;
		return os;
	}

	for (size_t i = 0; i < M.rows; i++) {
		for (size_t j = 0; j < M.cols; j++) {
			os << M.arr[i][j] << " ";
		}
		os << "\n";
	}
	os << "Norm matrix: " << static_cast<double>(M.norm()) << "\nMax element: " << M.maxEl() << endl;

	return os;
}





//це той самий код тільки не для класу матриць, а для дефолтних
//template <typename T> double norm(T** ma, int n, int m) {
//    double norm = 0.0;
//    for (size_t i = 0; i < n; i++) {
//        for (size_t j = 0; j < m; j++) {
//            norm += ma[i][j] * ma[i][j];
//        }
//    }
//    return sqrt(norm);
//}
//
//template <typename T> T maxEl(T** ma, int n, int m) {
//    T max = ma[0][0];
//    for (size_t i = 0; i < n; i++) {
//        for (size_t j = 0; j < m; j++) {
//            if (ma[i][j] > max) {
//                max = ma[i][j];
//            }
//        }
//    }
//    return max;
//}
//
//template <typename T> T** fill(const string namefile, int& n, int& m, size_t& count) {
//    ifstream in(namefile);
//    if (!in.is_open()) {
//        cout << "Error opening file!" << endl;
//        exit(-1);
//    }
//
//    for (size_t i = 0; i < count; i++) {
//        if (count > 0) in.ignore(100, 'n');
//    }
//
//    in >> n >> m;
//    T** ma = new T * [n];
//    for (size_t i = 0; i < n; i++) {
//        ma[i] = new T[m];
//    }
//
//    for (size_t i = 0; i < n; i++) {
//        for (size_t j = 0; j < m; j++) {
//            in >> ma[i][j];
//        }
//    }
//
//    ++count;
//    in.close();
//
//    return ma;
//}
//
//template <typename T> void dispaly(const string namefile, T** ma, int n, int m) {
//    ofstream out(namefile, ios::app);
//    if (!out.is_open()) {
//        cout << "Error opening file!" << endl;
//        exit(-1);
//    }
//
//    for (size_t i = 0; i < n; i++) {
//        for (size_t j = 0; j < m; j++) {
//            out << ma[i][j] << " ";
//        }
//        out << "\n";
//    }
//
//    out << "Norm matrix: " << norm(ma, n, m) << "\nMax element: " << maxEl(ma, n, m) << "\n" << endl;
//
//    out.close();
//}
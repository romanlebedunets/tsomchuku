#include "Header.h"
#include "Source.cpp"

int main() {
    ifstream in("text.txt");
    if (!in.is_open()) {
        cout << "Error opening file!" << endl;
        return -1;
    }

    Matrix<int> m;
	Matrix<double> n;
    in >> m >> n;

    in.close();

    ofstream out("text.txt", ios::app);
    if (!out.is_open()) {
        cout << "Error opening file!" << endl;
        return -1;
    }

    out << m << "\n" << n;

    out.close();

    return 0;
}


#include "Header.h"

void clear(const string namefile) {
    ofstream out(namefile);
    if (!out.is_open()) {
        cout << "Error opening file!" << endl;
        exit(-1);
    }
    out.close();
}

int** fill(int n) {
    int** ma = new int* [n];
    for (size_t i = 0; i < n; i++) {
        ma[i] = new int[n];
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            ma[i][j] = rand() % 10;
        }
    }

    return ma;
}

void display(const string namefile, int** ma, int n) {
    ofstream out(namefile, ios::app);
    if (!out.is_open()) {
        cout << "Error opening file!" << endl;
        exit(-1);
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            out << ma[i][j] << " ";
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

int** trivial_mul(int** left, int** right, int n) {
    int** res = new int* [n];
    res[0] = new int;
    res[0][0] = left[0][0] * right[0][0];
    return res;
}

int** algorithmStrasena(int** left, int** right, int n) {
    if (n <= 1) {
        return trivial_mul(left, right, n);
    }
    int s = n / 2;
    int** a11 = new int* [s];
    int** a12 = new int* [s];
    int** a21 = new int* [s];
    int** a22 = new int* [s];
    int** b11 = new int* [s];
    int** b12 = new int* [s];
    int** b21 = new int* [s];
    int** b22 = new int* [s];
    int** s1 = new int* [s];
    int** s2 = new int* [s];
    int** s3 = new int* [s];
    int** s4 = new int* [s];
    int** s5 = new int* [s];
    int** s6 = new int* [s];
    int** s7 = new int* [s];
    int** s8 = new int* [s];
    int** p1 = new int* [s];
    int** p2 = new int* [s];
    int** p3 = new int* [s];
    int** p4 = new int* [s];
    int** p5 = new int* [s];
    int** p6 = new int* [s];
    int** p7 = new int* [s];
    int** t1 = new int* [s];
    int** t2 = new int* [s];
    int** c11 = new int* [s];
    int** c12 = new int* [s];
    int** c21 = new int* [s];
    int** c22 = new int* [s];

    for (size_t i = 0; i < s; i++) {
        a11[i] = new int[s];
        a12[i] = new int[s];
        a21[i] = new int[s];
        a22[i] = new int[s];
        b11[i] = new int[s];
        b12[i] = new int[s];
        b21[i] = new int[s];
        b22[i] = new int[s];
        s1[i] = new int[s];
        s2[i] = new int[s];
        s3[i] = new int[s];
        s4[i] = new int[s];
        s5[i] = new int[s];
        s6[i] = new int[s];
        s7[i] = new int[s];
        s8[i] = new int[s];
        p1[i] = new int[s];
        p2[i] = new int[s];
        p3[i] = new int[s];
        p4[i] = new int[s];
        p5[i] = new int[s];
        p6[i] = new int[s];
        p7[i] = new int[s];
        t1[i] = new int[s];
        t2[i] = new int[s];
        c11[i] = new int[s];
        c12[i] = new int[s];
        c21[i] = new int[s];
        c22[i] = new int[s];
    }

    for (size_t i = 0; i < s; i++) {
        for (size_t j = 0; j < s; j++) {
            a11[i][j] = left[i][j];
            a12[i][j] = left[i][j + s];
            a21[i][j] = left[i + s][j];
            a22[i][j] = left[i + s][j + s];
            b11[i][j] = right[i][j];
            b12[i][j] = right[i][j + s];
            b21[i][j] = right[i + s][j];
            b22[i][j] = right[i + s][j + s];
        }
    }
    for (size_t i = 0; i < s; i++) {
        for (size_t j = 0; j < s; j++) {
            s1[i][j] = a21[i][j] + a22[i][j];
            s2[i][j] = s1[i][j] - a11[i][j];
            s3[i][j] = a11[i][j] - a21[i][j];
            s4[i][j] = a12[i][j] - s2[i][j];
            s5[i][j] = b12[i][j] - b11[i][j];
            s6[i][j] = b22[i][j] - s5[i][j];
            s7[i][j] = b22[i][j] - b12[i][j];
            s8[i][j] = s6[i][j] - b21[i][j];
        }
    }

    p1 = algorithmStrasena(s2, s6, s);
    p2 = algorithmStrasena(a11, b11, s);
    p3 = algorithmStrasena(a12, b21, s);
    p4 = algorithmStrasena(s3, s7, s);
    p5 = algorithmStrasena(s1, s5, s);
    p6 = algorithmStrasena(s4, b22, s);
    p7 = algorithmStrasena(a22, s8, s);

    for (size_t i = 0; i < s; i++) {
        for (size_t j = 0; j < s; j++) {
            t1[i][j] = p1[i][j] + p2[i][j];
            t2[i][j] = t1[i][j] + p4[i][j];
            c11[i][j] = p2[i][j] + p3[i][j];
            c12[i][j] = t1[i][j] + p5[i][j] + p6[i][j];
            c21[i][j] = t2[i][j] - p7[i][j];
            c22[i][j] = t2[i][j] + p5[i][j];
        }
    }

    int** c = new int* [n];
    for (size_t i = 0; i < n; i++) {
        c[i] = new int[n];
    }
    for (size_t i = 0; i < s; i++) {
        for (size_t j = 0; j < s; j++) {
            c[i][j] = c11[i][j];
            c[i][j + s] = c12[i][j];
            c[i + s][j] = c21[i][j];
            c[i + s][j + s] = c22[i][j];
        }
    }

    for (size_t i = 0; i < s; i++) {
        delete[]a11[i];
        delete[]a12[i];
        delete[]a21[i];
        delete[]a22[i];
        delete[]b11[i];
        delete[]b12[i];
        delete[]b21[i];
        delete[]b22[i];
        delete[]c11[i];
        delete[]c12[i];
        delete[]c21[i];
        delete[]c22[i];
        delete[]s1[i];
        delete[]s2[i];
        delete[]s3[i];
        delete[]s4[i];
        delete[]s5[i];
        delete[]s6[i];
        delete[]s7[i];
        delete[]s8[i];
        delete[]p1[i];
        delete[]p2[i];
        delete[]p3[i];
        delete[]p4[i];
        delete[]p5[i];
        delete[]p6[i];
        delete[]p7[i];
    }
    delete[]a11;
    delete[]a12;
    delete[]a21;
    delete[]a22;
    delete[]b11;
    delete[]b12;
    delete[]b21;
    delete[]b22;
    delete[]c11;
    delete[]c12;
    delete[]c21;
    delete[]c22;
    delete[]s1;
    delete[]s2;
    delete[]s3;
    delete[]s4;
    delete[]s5;
    delete[]s6;
    delete[]s7;
    delete[]s8;
    delete[]p1;
    delete[]p2;
    delete[]p3;
    delete[]p4;
    delete[]p5;
    delete[]p6;
    delete[]p7;

    return c;
}

int** standartMult(int** ma1, int** ma2, int n) {
    int** result = new int* [n];
    for (size_t i = 0; i < n; i++) {
        result[i] = new int[n];
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; ++j) {
            result[i][j] = 0;
            for (size_t k = 0; k < n; k++) {
                result[i][j] += ma1[i][k] * ma2[k][j];
            }
        }
    }

    return result;
}
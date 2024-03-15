#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace chrono;

int** fill(int n);
void clear(const string namefile);
void display(const string namefile, int** ma, int n);
void deleteM(int** m, int n);
int** trivial_mul(int** left, int** right, int n);
int** algorithmStrasena(int** left, int** right, int n);
int** standartMult(int** ma1, int** ma2, int n);

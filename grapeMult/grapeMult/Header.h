#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace chrono;

void clear(const string namefile);
int** fill(int n, int m);
void display(const string namefile, int** ma, int n, int m);
void deleteM(int** arr, int n);
int** standartMult(int** arr1, int n1, int m1, int** arr2, int n2, int m2);
int** grapeMult(int** arr1, int n1, int m1, int** arr2, int n2, int m2);
#include "Header.h"

int main() {
	srand(time(0));

	int n1, m1, n2, m2;
	cout << "Enter rows and cols first matrix:";
	cin >> n1 >> m1;
	cout << "Enter rows and cols second matrix:";
	cin >> n2 >> m2;

	clear("text.txt");

	int** arr1 = fill(n1, m1);
	int** arr2 = fill(n2, m2);
	
	display("text.txt", arr1, n1, m1);
	display("text.txt", arr2, n2, m2);

	auto startStandard = high_resolution_clock::now();
	int** res = standartMult(arr1, n1, m1, arr2, n2, m2);
	auto stopStandard = high_resolution_clock::now();
	auto durationStandard = duration_cast<microseconds>(stopStandard - startStandard);

	auto startVinograd = high_resolution_clock::now();
	int** res1 = grapeMult(arr1, n1, m1, arr2, n2, m2);
	auto stopVinograd = high_resolution_clock::now();
	auto durationGrape = duration_cast<microseconds>(stopVinograd - startVinograd);

	cout << "Time taken by standard multiplication: " << durationStandard.count() << " microseconds" << endl;
	cout << "Time taken by Grape multiplication: " << durationGrape.count() << " microseconds" << endl;

	display("text.txt", res, n1, m2);
	display("text.txt", res1, n1, m2);

	deleteM(arr1, n1);
	deleteM(arr2, n2);
	deleteM(res, n1);
	deleteM(res1, n1);

	return 0;
}
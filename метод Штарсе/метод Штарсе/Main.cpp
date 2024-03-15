#include "Header.h"

int main() {
    srand(time(NULL));
    int n = 128; //n має бути 2 4 8 16 і тд...

    int** a = fill(n);
    int** b = fill(n);

    clear("text.txt");

    display("text.txt", a, n);
    display("text.txt", b, n);

    auto startStandard = high_resolution_clock::now();
    int** d = standartMult(a, b, n);
    auto stopStandard = high_resolution_clock::now();
    auto durationStandard = duration_cast<microseconds>(stopStandard - startStandard);

    auto startVinograd = high_resolution_clock::now();
    int** c = algorithmStrasena(a, b, n);
    auto stopVinograd = high_resolution_clock::now();
    auto durationShtr = duration_cast<microseconds>(stopVinograd - startVinograd);

    cout << "Time taken by standard multiplication: " << durationStandard.count() << " microseconds" << endl;
    cout << "Time taken by Strase multiplication: " << durationShtr.count() << " microseconds" << endl;


    display("text.txt", c, n);
    display("text.txt", d, n);

    deleteM(a, n);
    deleteM(b, n);
    deleteM(c, n);
    deleteM(d, n);

    return 0;
}
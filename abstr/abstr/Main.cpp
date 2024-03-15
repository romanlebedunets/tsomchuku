#include "Header.h"

int main() {
	int count;
	cout << "Enter a number of progressions:";
	cin >> count;

	progres** pr = new progres * [count];
	char typeProg;
	for (size_t i = 0; i < count; i++) {
		cout << "Enter type of progression(E - endProd; I - infProg):";
		cin >> typeProg;

		switch (typeProg) {
		case 'E': {
			pr[i] = new endProg;
			cin >> pr[i];
			break;
		}
		case 'I': {
			pr[i] = new infProg;
			cin >> pr[i];
			break;
		}
		default:
			cout << "Enter correct data!" << endl;
			return -1;
		}
	}

	for (size_t i = 0; i < count; i++) {
		cout << pr[i];
	}

	for (size_t i = 0; i < count; i++) {
		delete[] pr[i];
	}
	delete[] pr;

	return 0;
}
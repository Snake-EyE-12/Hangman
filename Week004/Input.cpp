#include "Input.h"

int Input::getUserInt(string prompt, unsigned short low, unsigned short high) {
	int iTemp = 0;
	do {
		cout << prompt;
		//cout << "\n Enter a number between " << low << " and " << high << ".\n";
		cin >> iTemp;

		if (!cin.good()) {
			cin.clear();
			cin.ignore();
			cout << "\n Improper Input!";
			iTemp = low - 1;
		}
	} while (iTemp < low || iTemp > high);
	return iTemp;
}
int Input::getUserInt(unsigned short low, unsigned short high) {
	return getUserInt("", low, high);
}
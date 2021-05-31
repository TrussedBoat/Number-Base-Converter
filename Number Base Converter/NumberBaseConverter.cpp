#include <iostream>
using namespace std;



string DecimalToHexadecimal(int decimalNumber) {
	//Written By TrussedBoat
	char hexaNumbers[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	string hexadecimalNumber;

	unsigned int current = 1;
	while (current * 16 <= decimalNumber) {
		current *= 16;
	}

	int tempNumber = decimalNumber;
	while (tempNumber >= 0 && current >= 1) {
		hexadecimalNumber += hexaNumbers[tempNumber / current];
		tempNumber %= current;
		current /= 16;
	}

	return hexadecimalNumber;
}

int main() {
	cout << "Welcome to \"Base Converter\"" << endl;
	cout << "Write the number you want to turn to hexadecimal" << endl;
	cout << "When you need to quit, just type \"-1\"" << endl << endl;

	int a = 0;
	while (true) {
		cout << "Decimal = ";
		cin >> a;
		if (a == -1) {
			break;
		}
		cout << "Hexadecimal = " << DecimalToHexadecimal(a) << endl << endl;
	}



}

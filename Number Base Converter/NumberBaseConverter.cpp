#include <iostream>
using namespace std;

unsigned long long int stringToInt(string str) {
	//Written By TrussedBoat
	unsigned long long int current = 1;
	unsigned long long int newInteger = 0;

	for (int i = str.length() - 1;i >= 0; i--) {
		newInteger += (str[i] - '0') * current;
		current *= 10;
	}
	
	return newInteger;
}

void configLibrary(char numberArray[]) {
	//Written By TrussedBoat
	for (int i = 0; i < 10; i++) {	
		numberArray[i] = (char)(48 + i);
	}

	for (int i = 10; i < 36; i++) {
		numberArray[i] = (char)(55 + i);
	}

}


string DecimalToAllBases(unsigned long long int decimalNumber , int targetBase) {
	//Written By TrussedBoat
	char charArray[36];
	configLibrary(charArray);

	string newNumber;

	unsigned long long int current = 1;
	while (current * targetBase <= decimalNumber) {
		current *= targetBase;
	}

	unsigned long long int tempNumber = decimalNumber;
	while (tempNumber >= 0 && current >= 1) {
		newNumber += charArray[tempNumber / current];
		tempNumber %= current;
		current /= targetBase;
	}

	return newNumber;
}

int main() {
	cout << "Welcome to \"Base Converter\"" << endl;
	cout << "Write your target base (e.g. Writing \"2\" converts your decimal to binary)" << endl;
	cout << "Write the number you want to convert to target base" << endl;
	cout << "When you need to quit, just type \"-1\"" << endl << endl;

	string a = "";
	string b = "";
	while (true) {
		while (true) {
			cout << "Target Base = ";
			cin >> b;
			if (b == "-1") {
				return 0;
			}
			else if (b[0] == '-' || (b == "0") || (b == "1")) {
				cout << "Sorry! You cannot give a value to \"Target Base\" smaller than \"2\"" << endl;
			}
			else if (b.length() > 2 || stringToInt(b) > 35) {
				cout << "Sorry! You cannot give a value to \"Target Base\" bigger than \"35\""<<endl;
			}
			else {
				break;
			}
		}
		
		
		while (true) {
			cout << "Decimal = ";
			cin >> a;
			if (a == "-1") {
				return 0;
			}
			else if (a[0] == '-') {
				cout << "Sorry! Your \"Decimal Number\" can\'t be negative" << endl;
			}
			else if (a.length() > 19 || (a.length()==19 && a != "1000000000000000000")) {
				cout << "Sorry! Your \"Decimal Number\" can\'t be bigger than \"1.000.000.000.000.000.000 (1 quintillion)\"" << endl;
				cout << "Try again!" << endl;
			}
			else {
				break;
			}
		}
		cout << "Your Decimal Number In Target Base = " << DecimalToAllBases(stringToInt(a) , stringToInt(b)) << endl << endl;
	}



}

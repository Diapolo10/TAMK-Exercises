#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;

double get_input() {
	double result = 0.0;
    double weight;
	bool input_valid = false;

	while (!input_valid) {

		std::cout << "Package weight in grams: ";
		std::cin >> weight;

		if (weight <= 2000) {
			input_valid = true;
		}
		else {
			std::cout << "Invalid input - weight exceeds maximum accepted value (" << weight << "g vs 2000g\n";
		}

	}

	if (weight <= 50) {
		result = 0.60;
	}
	else if (weight <= 100) {
		result = 0.90;
	}
	else if (weight <= 250) {
		result = 1.30;
	}
	else if (weight <= 500) {
		result = 2.10;
	}
	else if (weight <= 1000) {
		result = 3.50;
	}
	else if (weight <= 2000) {
		result = 5.50;
	}
	else {
		throw "Program panicked at get_input(): result's value changed after creation";
	}

	return result;
}

int main(void) {
	double price = get_input();
	std::cout << "Sending the package costs " << price << " euros.\n";
}
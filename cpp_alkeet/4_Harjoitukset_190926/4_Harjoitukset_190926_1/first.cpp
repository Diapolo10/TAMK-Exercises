#include <iostream>
#include <string>

using std::string;

int main(void) {
	double weight, height;

	std::cout << "User weight (kg): ";
	std::cin >> weight;

	std::cout << "User height (m): ";
	std::cin >> height;

	double weight_index = weight / (height * height);
	string result = "Error!";

	if (weight_index <= 20.7) {
		result = "underweight";
	}
	else if (20.7 < weight_index && weight_index <= 26.4) {
		result = "normal";
	}
	else if (26.4 < weight_index && weight_index <= 27.8) {
		result = "slight overweight";
	}
	else if (27.8 < weight_index && weight_index <= 31.1) {
		result = "overweight";
	}
	else if (31.1 < weight_index) {
		result = "obesity";
	}
	else {
		throw "ValueError: weight_index had an unexpected value";
	}

	std::cout << result;
}
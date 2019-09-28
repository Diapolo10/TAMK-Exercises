#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using std::string;

int main(void) {
	double temperature, temp_2;
	string unit;

	while (true) {

		std::cout << "Syota lampotila: ";
		std::cin >> temperature;

		std::cout << "Syota yksikko (F=Fahrenheit, C=Celsius): ";
		std::cin >> unit;

		// Turns the unit into a lowercase std::string
		std::transform(unit.begin(), unit.end(), unit.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if (unit == (string)"c") {
			temp_2 = temperature * 1.8 + 32;
			std::cout << temperature << " Celsius = " << temp_2 << " Fahrenheit\n";
		}
		else if (unit == (string)"f") {
			temp_2 = (temperature - 32) / 1.8;
			std::cout << temperature << " Fahrenheit = " << temp_2 << " Celsius\n";
		}
		else {
			std::cout << "Given unit is not supported\N";
		}
	}
}

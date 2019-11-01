#include <iostream>
#include <string>

using namespace std::string_literals;

float virta(float jannite, float resistanssi) {
	// U == R*I -> I == U/R

	return jannite / resistanssi;
}

int main(void) {
	float voltage{}, resistance{};

	std::cout << u8"Virtapiirin jännite (V): ";
	std::cin >> voltage;

	std::cout << u8"Virtapiirin resistanssi (Ω): ";
	std::cin >> resistance;

	std::cout << u8"Virtapiirin sähkövirta on " << virta(voltage, resistance) << " A.\n";
}

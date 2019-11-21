#include <iostream>
#include <string>

using std::string;
using namespace std::string_literals;

// Config
const int VOLTAGE = 220;

void sulake(double teho) {
	double current = teho / VOLTAGE;
	string result {};

	if ((current - 10) <= 0) {
		result = "sulake on 10A";
	}
	else if ((current - 6) <= 10) {
		result = "sulake on 16A";
	}
	else if ((current - 4) <= 16) {
		result = "sulake on 20A";
	}
	else {
		result = "Laitteen taakse tarvitaan useampi sulake";
	}

	std::cout << result << std::endl;
}

int main(void) {
	double power;

	std::cout << u8"Anna sähkölaitteen teho: ";
	std::cin >> power;

	sulake(power);
	return 0;
}

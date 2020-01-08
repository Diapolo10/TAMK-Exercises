#include <iostream>
#include <iomanip>

void falling_speed(long seconds) {

	double g = 9.81;
	std::cout << "\nAika        Nopeus (km/h)\n";
	
	for (long t = 0; t <= seconds; ++t) {
		double v = g * t;
		std::cout << std::left << std::setfill(' ') << std::setw(12) << t << v * 3.6 << "\n";
	}
}

int main(void) {
	long time;

	std::cout << "Kulunut aika sekunneissa: ";
	std::cin >> time;

	falling_speed(time);

	return EXIT_SUCCESS;
}
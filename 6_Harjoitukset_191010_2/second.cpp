#include <iostream>

void falling_speed(long seconds) {

	double g = 9.81;
	std::cout << "\nAika       Nopeus (km/h)\n";
	
	for (long t = 0; t <= seconds; ++t) {
		double v = g * t;
		std::cout << t;

		// Pads the column with whitespace, works when t < 1_000_000_000
		for (int _ = 0; _ < 10 - (t / 10); ++_) {
			std::cout << " ";
		}
		std::cout << v * 3.6 << "\n";
	}
}

int main(void) {
	long time;

	std::cout << "Kulunut aika sekunneissa: ";
	std::cin >> time;

	falling_speed(time);

	return EXIT_SUCCESS;
}
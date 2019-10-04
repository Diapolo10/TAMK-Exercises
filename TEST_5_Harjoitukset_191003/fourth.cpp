#include <iostream>
#include <vector>
#include <string>

// Self-written library code
#include "utility.h"

using std::string;
using std::vector;

// For utf-8 encoding and std::string literals
using namespace std::string_literals;

int main(void) {
	double length;

	std::cout << u8"Hypyn pituus: "s;
	std::cin >> length;

	double result = non_std::math::sum(non_std::io::get_n_input<double>(5L, u8"Tuomarin {} pisteet: "s)) + 0.9 * length;
	std::cout << u8"Hypyn pisteet: "s << result << std::endl;
	return EXIT_SUCCESS;
}
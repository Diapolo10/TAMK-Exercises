#include <iostream>

void print_even(long n) {
	for (long i=2; i <= n; i += 2) {
		std::cout << i;
		if (i != n) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

int main(void) {
	// Part a
	for (int i = 1; i <= 10; ++i) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	// Part b
	print_even(20);

	return EXIT_SUCCESS;
}
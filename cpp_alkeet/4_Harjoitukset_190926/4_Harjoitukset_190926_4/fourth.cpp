#include <iostream>
#include <string>

using std::string;

int main(void) {
	long n;

	std::cout << "Gimme an integer: ";
	std::cin >> n;

	for (long i = 0; i < n; ++i) {
		std::cout << (string)"Hello, world!\n";
	}

	for (unsigned short int i = 1; i <= 15; ++i) {
		std::cout << i << " ";
	}
	std::cout << "\n";
}
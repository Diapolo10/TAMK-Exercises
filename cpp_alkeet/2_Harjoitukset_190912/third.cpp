#include <iostream>


template<typename T>
T max(T first, T second) {
	return (first > second) ? first : second;
}

int main(void) {
	double first, second;

	std::cout << "First person's height: ";
	std::cin >> first;

	std::cout << "Second person's height: ";
	std::cin >> second;

	std::cout << max(first, second) << " is taller.\n";
	return 0;
}
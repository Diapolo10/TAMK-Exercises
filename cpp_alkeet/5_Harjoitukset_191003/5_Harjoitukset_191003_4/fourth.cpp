#include <iostream>
#include <vector>

using std::vector;

template <class T>
vector<T> get_scores(long num) {
	/* Gets num inputs from the user; returns a vector of type T */

	vector<T> result;
	T input;
	long num_counter = 1L;

	do {
		std::cout << "Tuomarin " << num_counter++ << " pisteet: ";
		std::cin >> input;

		result.push_back(input);

	} while (num_counter <= num);

	return result;
}

template <class T>
long double sum(T iterable) {
	/* Adds up the contents of any iterable type T, returns a long double */
	long double result = 0LL;

	for (auto num : iterable) {
		result += num;
	}

	return result;
}

int main(void) {
	double length;

	std::cout << "Hypyn pituus: ";
	std::cin >> length;

	std::cout << "Hypyn pisteet: " << sum(get_scores<double>(5L)) + 0.9 * length << "\n";
	return EXIT_SUCCESS;
}
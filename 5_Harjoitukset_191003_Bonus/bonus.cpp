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
T max(vector<T> vec) {
	/* Takes a vector of type T, returns the highest value of type T */

	T current_max = vec.front();

	for (auto value : vec) {
		if (value > current_max) {
			current_max = value;
		}
	}

	return current_max;
}

template <class T>
T min(vector<T> vec) {
	/* Takes a vector of type T, returns the lowest value of type T */

	T current_min = vec.front();

	for (auto value : vec) {
		if (value < current_min) {
			current_min = value;
		}
	}

	return current_min;
}

template <typename T>
auto competitive_sum(T iterable) {
	/*
	 * Adds up the contents of any iterable type T, returns a T::value_type.
	 *
	 * If the type doesn't support addition, no error handling is done.
	 */

	typename T::value_type result = {};
	auto max_score = max<T::value_type>(iterable);
	auto min_score = min<T::value_type>(iterable);

	// I was too lazy to sort the vector, so I decided to strip the values otherwise
	bool max_found = false;
	bool min_found = false;

	for (auto num : iterable) {

		if (num == max_score && !max_found) {

			// Ignores the first found value equal to the highest one
			max_found = true;
			continue;

		}

		if (num == min_score && !min_found) {

			// Ignores the first found value equal to the lowest one
			min_found = true;
			continue;

		}

		result += num;
	}

	return result;
}

int main(void) {
	double length;

	std::cout << "Hypyn pituus: ";
	std::cin >> length;

	std::cout << "Hypyn pisteet: " << competitive_sum(get_scores<double>(5L)) + 0.9 * length << "\n";
	return EXIT_SUCCESS;
}
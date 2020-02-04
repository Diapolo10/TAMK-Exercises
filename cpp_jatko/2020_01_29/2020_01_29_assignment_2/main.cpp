#include <fstream>
#include <iostream>
#include <vector>

// Results checked with Python

// From my own library header which I didn't bother including
template <typename T>
typename T::value_type sum(const T& iterable) {
	/*
	 * Adds up the contents of any iterable type T, returns the sum of its contents
	 * as type T::value_type.
	 */
	typename T::value_type result = {};

	for (const auto& num : iterable) {
		result += num;
	}

	return result;
}

int main() {

	std::ifstream num_file;

	num_file.open("Random.txt");
	if (num_file.fail()) {
		std::cerr << "Error opening file\n";
		
	}

	else {

	    std::vector<double> nums{};
	    double input;

	    while (num_file >> input) {
		    nums.push_back(input);
	    }

	    auto number_sum = sum(nums);

	    std::cout << "There are " << nums.size() << " numbers in the file.\n";
	    std::cout << "The sum of the numbers is " << number_sum << ".\n";
	    std::cout << "The average of the numbers is " << number_sum / nums.size() << ".\n";
	}

	num_file.close();
}

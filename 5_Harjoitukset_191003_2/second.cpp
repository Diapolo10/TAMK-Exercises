#include <iostream>
#include <vector>

using std::vector;

template <class T>
long long get_sum(vector<T> nums) {

	// I know I could've just used a counter variable instead of storing all numbers in a vector, but this was more interesting.
	long long result = 0LL;

	for (auto num : nums) {
		result += num;
	}

	return result;
}

vector<long> get_input(void) {
	/* Gets input from the user; returns a vector of long numbers. */
	vector<long> nums;
	long input = -1L;
	long num_counter = 1L;

	std::cout << "Enter integers to calculate their sum. Entering 0 returns the sum.\n\n";

	do {
		std::cout << "Enter number " << num_counter++ << "#: ";
		std::cin >> input;

		nums.push_back(input);

	} while (input != 0L);


	return nums;
}

int main(void) {
	std::cout << "Sum of entered numbers: " << get_sum(get_input()) << "\n";
}
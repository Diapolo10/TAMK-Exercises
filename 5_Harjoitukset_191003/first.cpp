#include <iostream>
#include <vector>

using std::vector;

vector<long> gen_positive_negative_range(long n) {
	/* n : absolute distance from zero to either end */
	vector<long> nums;
	long start, stop;
	
	start = stop = n;

	for (long i = -start; i <= stop; ++i) {
		nums.push_back(-i);
	}

	return nums;
}

vector<long> gen_even(long n) {
	/* n : upper limit for generated even numbers */
	vector<long> nums;

	for (long i = 2; i <= n; i += 2) {
		nums.push_back(i);
	}

	return nums;
}

template <class T>
void print_vector(vector<T> vec) {
	/* Prints out the contents of any vector type T, separated by a space. Adds a newline in the end. */
	for (auto num : vec) {
		std::cout << num << " ";
	}
	std::cout << "\n";
}

int main(void) {
	
	// First objective; generate and print integers from -5 to 5
	print_vector(gen_positive_negative_range(5));

	// Second objective; generate and print all even numbers from 1 to 50
	print_vector(gen_even(50));

	return EXIT_SUCCESS;
}
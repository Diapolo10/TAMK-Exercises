#include <iostream>
#include <random>
#include <vector>

using std::vector;

vector<long> forwards_for_loop(long n) {
	vector<long> nums;
	long start, stop;
	
	start = stop = n / 2;

	for (long i = -start; i <= stop; ++i) {
		nums.push_back(-i);
	}

	return nums;
}

vector<long> backwards_for_loop(long n) {
	vector<long> nums;
	long start, stop;
	
	start = stop = n / 2;

	for (long i = start; i >= -stop; --i) {
		nums.push_back(i);
	}

	return nums;
}

vector<long> forwards_while_loop(long n) {
	vector<long> nums;
	long start = -n / 2;
	long stop =   n / 2;

	while (start <= stop) {
		nums.push_back(-start++);
	}

	return nums;
}

vector<long> backwards_while_loop(long n) {
	vector<long> nums;
	long start = n / 2;
	long stop = -n / 2;

	while (start >= stop) {
		nums.push_back(start--);
	}

	return nums;
}

template <class T>
void print_vector(vector<T> vec) {
	for (auto num : vec) {
		std::cout << num << " ";
	}
	std::cout << "\n";
}

int main(void) {

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist4(1, 4); // distribution in range [1, 4]

	int choice = dist4(rng);

	switch (choice) {
	    case 1:
			print_vector(forwards_for_loop(10));
		break;
		case 2:
			print_vector(backwards_for_loop(10));
		break;
		case 3:
			print_vector(forwards_while_loop(10));
		break;
		case 4:
			print_vector(backwards_while_loop(10));
		break;
		default:
			std::cerr << "SNAFU\n";
		break;
	}

	return EXIT_SUCCESS;
}
// -*- lsst-c++ -*-
/// Copyright Lari Liuhamo, 2019

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using std::string;
using std::tuple;
using std::vector;

/* 
 * Quick note from author 
 *
 * I'm not an experienced C++ developer, but I have plenty of Python experience and I'm learning Rust.
 * This beginner course was looking too simple, so I've made a point to try and solve all suitable assignments
 * in such a way I'll actually learn something. Expect my future solutions to mirror this wherever possible.
 * 
 * My solutions aim to be generalised, properly formed, with corner cases handled (where possible) and with
 * best practices taken into account to the best of my knowledge.
 * 
 * Dear Teacher, I look forward to working with you in the future.
 * 
 * Cheers,
 * - Lari Liuhamo, who previously worked for the Finnish Defence Forces as a programmer
 */

vector<int> get_nums(int n = 2) {

	/**
	 ** Takes user input n times, returns a vector of the given integers.
	 **
	 ** Does not handle incorrect input, because I'm not familiar enough with C++ to do so yet.
	 */

	vector<int> nums;

	for (int i = 0; i < n; ++i) {

		int num;
		std::cout << "Syota " << i + 1 << ". luku: ";
		std::cin >> num;

		nums.push_back(num);

	}

	return nums;
}


tuple<int, int> calculator(vector<int> numbers) {

	/**
	 ** Takes a non-empty vector of integers as input, then takes the first number from the vector and
	 ** uses that as a base for substraction and multiplication. Returns a tuple with the results.
	 ** 
	 ** Should work with all vectors with at least one value.
	 */

	// Stores a reference to the first number in the vector
	int first = numbers.front();

	// Initialises the starting values for substraction and multiplication
	int sub = first;
	int mul = first;

	// Slices the original vector to drop out the first number, may result in an empty vector
	vector<int> rest = vector<int>(numbers.begin() + 1, numbers.end());

	// Iterates over the sliced vector using a for-each loop, performing calculations on each iteration
	// If the vector is empty, the loop is skipped entirely
	for (int num : rest) {
		sub -= num;
		mul *= num;
	}

	// Returns a tuple of 32-bit integers containing the results of the calculations
	return tuple<int, int>(sub, mul);
}


int main(void) {

	vector<int> nums = get_nums();
	tuple<int, int> results = calculator(nums);

	int sub_result = std::get<0>(results);
	int mul_result = std::get<1>(results);

	std::cout << "Lukujen erotus on " << sub_result << ".\n";
	std::cout << "Lukujen tulo on " << mul_result << ".\n";

}

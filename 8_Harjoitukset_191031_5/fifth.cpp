#include <algorithm> // std::sort
#include <iostream>  // std::cout, std::endl
#include <random>    // std::random_device, std::mt19937, std::uniform_int_distribution
#include <vector>    // std::vector

// rand()? No thanks! https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful
// I'll stick to std::random.

using std::vector;

// CONFIGURATION
const int MIN_VALUE = 1;
const int MAX_VALUE = 40;
const int NUMBER_OF_VALUES = 7;

int main() {

	// Creating a random number distribution
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(MIN_VALUE, MAX_VALUE);

	// Vector for storing the random numbers
	vector<int> lottery_numbers {};

	// Add unique nums to the vector until it has seven of them
	while (lottery_numbers.size() < NUMBER_OF_VALUES) {

		// Generates a random number from the distribution
		int num { dist(mt) };

		// If the generated number is not in the sequence, add it in
		if (find(lottery_numbers.begin(), lottery_numbers.end(), num) == lottery_numbers.end()) {
			lottery_numbers.push_back(num);
		}
	}

	// Sort the results for readability
	std::sort(lottery_numbers.begin(), lottery_numbers.end());

	// Print out the numbers
	std::cout << "Lottery numbers: ";
	for (auto num : lottery_numbers) {
		std::cout << num << ' ';
	}
	std::cout << std::endl;
}

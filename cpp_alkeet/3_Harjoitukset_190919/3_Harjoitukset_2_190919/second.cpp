#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<double> get_input(unsigned int n=3) {
	vector<double> result;

	for (int i=1; i <= n; ++i) {
		double input;
		std::cout << "Enter number #" << i << ": ";
		std::cin >> input;
		result.push_back(input);
	}

	return result;
}

template<class T>
T max(vector<T> iterable) {
	auto current_max = iterable.front();

	for (auto val : iterable) {
		if (val > current_max) {
			current_max = val;
		}
	}

	return current_max;
}

int main(void) {
	std::cout << "Largest entered number: " << max(get_input()) << "\n";
}

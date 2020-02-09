#include <cmath>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::vector<T> get_n_input(long n, std::string prompt) {
	/* Gets n inputs from the user; returns a std::vector of type T
	 *
	 * prompt is a formattable std::string, where '{}' is used as a
	 * placeholder for the current counter value.
	 */

	std::vector<T> result;
	T input;
	long num_counter = 1L;

	do {
		while (true) {

			std::cout << prompt;

			if (!(std::cin >> input)) {
				std::cout << u8"Virhe, syötä uudelleen.\n\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}

			break;
		}

		result.push_back(input);

	} while (++num_counter <= n);

	return result;
}

int main() {
    auto num = get_n_input<double>(1, "Anna luku: ").front();
	std::cout << "Luku " << num << u8" sisältyy välille [ " << std::floor(num) << ", " << std::ceil(num) << " ].\n";
	return 0;
}
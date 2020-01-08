#include <iostream>
#include <string>
#include <tuple>

using std::string;
using std::tuple;

tuple<double, double>& get_nums(void) {
	double a, b;

	std::cout << "Anna kolmion kanta metreina: ";
	std::cin >> a;

	std::cout << "Anna kolmion kateetti metreina: ";
	std::cin >> b;

	tuple<double, double> results = std::make_tuple(a, b);
	return results;
}


int main(void) {
	auto nums = get_nums();
	double kanta = std::get<0>(nums);
	double korkeus = std::get<1>(nums);
	std::cout << "Kolmion pinta-ala on " << kanta * korkeus / 2 << "\n";
	return 0;
}

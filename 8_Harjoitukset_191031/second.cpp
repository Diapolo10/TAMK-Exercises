#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "mylib.hpp"

using std::string;
using std::tuple;
using std::vector;

using namespace std::string_literals;

// ASSIGNMENTS
void first(void);
void second(void);
void third(void);
void fourth(void);

int main(void) {
	first();
	second();
	third();
	fourth();
}

void first(void) {

	vector<tuple<int, long long>> first_test_cases{ {0, 0LL}, {1, 1LL}, {-1, 1LL}, {2, 4LL}, {-8, 64LL}, {2147483647, 4611686014132420609LL}, {-2147483647, 4611686014132420609LL} };

	for (auto [input, expected] : first_test_cases) {

		long double result{ nonstd::Nelio(input) };
		std::cout << "Tested Nelio(" << input << "), expected " << expected << ", got " << result << ". Result is " << (expected == result ? "correct" : "incorrect") << "!\n";
	}
	std::cout << std::endl;
}

void second(void) {

	vector<tuple<int, int, long long>> second_test_cases{ {0, 0, 0LL}, {1, 0, 0LL}, {0, 1, 0LL}, {1, 1, 1LL}, {2, 7, 14LL}, {8, 9, 72LL}, {2147483647, 2147483647, 4611686014132420609LL}, {13, 26, 338LL} };

	for (auto [height, width, expected] : second_test_cases) {

		long double result{ nonstd::Suorakaide(height, width) };
		std::cout << "Tested Suorakaide(" << height << ", " << width << "), expected " << expected << ", got " << result << ". Result is " << (expected == result ? "correct" : "incorrect") << "!\n";
	}
	std::cout << std::endl;
}

void third(void) {

	float travel_distance{};
	float fuel_consumption{};
	float fuel_price{};

	std::cout << u8"Kuljettu matka kilometrein�: "s;
	std::cin >> travel_distance;

	std::cout << u8"Auton polttoaineenkulutus (litraa per kilometri): "s;
	std::cin >> fuel_consumption;

	std::cout << u8"Polttoaineen hinta: "s;
	std::cin >> fuel_price;

	std::cout << u8"Matkan polttoainekustannukset ovat " << nonstd::MatkanHinta(travel_distance, fuel_consumption, fuel_price) << u8"�.\n"s;
	std::cout << std::endl;
}

void fourth(void) {

	int work_hours{};

	std::cout << u8"Viikon ty�tunnit: "s;
	std::cin >> work_hours;

	std::cout << u8"Viikon bruttoansiot: "s << nonstd::palkka(work_hours) << "�.\n";
	std::cout << std::endl;
}

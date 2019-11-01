#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using std::string;
using std::tuple;
using std::vector;

using namespace std::string_literals;

// ASSIGNMENTS
void first(void);
void second(void);
void third(void);
void fourth(void);

/*
 * I do not approve of PascalCase function names,
 * they should only be used for class names, and
 * snake_case for most everything else.
 *
 * Sure, call it Python influence, but I like
 * the convention. It makes sense.
 * - Lari, 2019
 */

/*
 * Using long long to prevent overflows;
 * assuming worst-case scenario where
 * int == 32 bits and long long == 64 bits
 *
 * The maximum value of a signed 32-bit value is
 * 2_147_483_647, and the maximum value of a 64-bit
 * signed value is 9_223_372_036_854_775_807.
 * 2147483647 * 2147483647 == 4611686014132420609,
 * so overflows shouldn't occur. I couldn't use
 * unsigned values because the input could be negative.
 */

// Calculates the square of a given int, returning it as a long long
long long Nelio(int num) {
	long long n { num }; // Prevents overflows
	return n * n;
}

// Calculates the area of a rectangle with the specified width and height
long long Suorakaide(int width, int height) {
	long long w { width }, h { height }; // Prevents overflows
	return w * h;
}

// A function that takes a travel distance, the fuel consumption of the vehicle and the price of its fuel,
// returning the average fuel cost of the trip. Fuel consumption can not be zero.
long double MatkanHinta(float distance, float fuel_consumption, float fuel_price) {
	long double d { distance }, c { fuel_consumption }, p { fuel_price }; // Helps prevent overflows, but may not fully negate them
	return (d / c) * p;
}

// Due to the assignment requiring the use of int here, I cannot do anything to prevent overflows
int palkka(int tuntimaara) {

	int base_salary { 10 };
	int result = base_salary * tuntimaara;

	if (tuntimaara > 40) {
		result += (tuntimaara - 40) * (base_salary / 2);
	}

	return result;
}

int main(void) {
	first();
	second();
	third();
	fourth();
	return EXIT_SUCCESS;
}

void first(void) {

	vector<tuple<int, long long>> first_test_cases{ {0, 0LL}, {1, 1LL}, {-1, 1LL}, {2, 4LL}, {-8, 64LL}, {2147483647, 4611686014132420609LL}, {-2147483647, 4611686014132420609LL} };

	for (auto test : first_test_cases) {

		int input { std::get<0>(test) };
		long long expected { std::get<1>(test) };

		long long result { Nelio(input) };
		std::cout << "Tested Nelio(" << input << "), expected " << expected << ", got " << result << ". Result is " << (expected == result ? "correct" : "incorrect") << "!\n";
	}
	std::cout << std::endl;
}

void second(void) {

	vector<tuple<int, int, long long>> second_test_cases{ {0, 0, 0LL}, {1, 0, 0LL}, {0, 1, 0LL}, {1, 1, 1LL}, {2, 7, 14LL}, {8, 9, 72LL}, {2147483647, 2147483647, 4611686014132420609LL}, {13, 26, 338LL} };

	for (auto test : second_test_cases) {

		int height { std::get<0>(test) };
		int width { std::get<1>(test) };
		long long expected { std::get<2>(test) };

		long long result{ Suorakaide(height, width) };
		std::cout << "Tested Suorakaide(" << height << ", " << width << "), expected " << expected << ", got " << result << ". Result is " << (expected == result ? "correct" : "incorrect") << "!\n";
	}
	std::cout << std::endl;
}

void third(void) {

	float travel_distance {};
	float fuel_consumption {};
	float fuel_price {};

	std::cout << u8"Kuljettu matka kilometreinä: "s;
	std::cin >> travel_distance;

	std::cout << u8"Auton polttoaineenkulutus (litraa per kilometri): "s;
	std::cin >> fuel_consumption;

	std::cout << u8"Polttoaineen hinta: "s;
	std::cin >> fuel_price;

	std::cout << "Matkan polttoainekustannukset ovat " << MatkanHinta(travel_distance, fuel_consumption, fuel_price) << u8"€.\n"s;
	std::cout << std::endl;
}

void fourth(void) {

	int work_hours {};

	std::cout << u8"Viikon työtunnit: "s;
	std::cin >> work_hours;

	std::cout << u8"Viikon bruttoansiot: "s << palkka(work_hours) << "€.\n";
	std::cout << std::endl;
}

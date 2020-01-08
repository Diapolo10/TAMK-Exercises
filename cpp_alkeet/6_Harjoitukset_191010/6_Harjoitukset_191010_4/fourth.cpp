#include <cmath>
#include <iostream>
#include <string>

using std::string;
using namespace std::string_literals;

int main(void) {

	string user_input;
	
	do {
	
		std::cout << u8"Valitse laskutoimitus (1=neliöjuuri, 2=ln, 3=exp, 4=tan, L=lopetus): "s;
		std::cin >> user_input;

		if (user_input != "L"s) {
			return EXIT_SUCCESS;
		}

		double num;
		std::cout << u8"Syötä luku: "s;
		std::cin >> num;

		if (user_input == "1"s) {
			std::cout << u8"Syöttämäsi luvun neliöjuuri on: "s << std::sqrt(num);
		}
		else if (user_input == u8"2"s) {
			std::cout << u8"Syöttämäsi luvun luonnollinen logaritmi on: "s << std::log(num);
		}
		else if (user_input == u8"3"s) {
			std::cout << u8"Neperin luvun korotus syöttämääsi potenssiin on: "s << std::exp(num);
		}
		else if (user_input == u8"4"s) {
			std::cout << u8"Syöttämäsi luvun tangentti on: "s << std::tan(num);
		}

	}
	while (true);
}
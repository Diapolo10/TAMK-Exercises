#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

const int COUNTRY_COUNT{ 2 };

struct Valtio {
	string nimi;
	long asukasluku;
	double pinta_ala;
	string johtaja;
};

int main(void) {
	vector<Valtio> countries{};

	while (countries.size() < COUNTRY_COUNT) {
		string name{};
		long population{};
		double area{};
		string leader{};
		std::cout << "Valtio #" << countries.size() + 1 << ":\n";

		std::cout << "Nimi: ";
		std::cin >> name;

		std::cout << "Asukasluku: ";
		std::cin >> population;

		std::cout << "Pinta-ala: ";
		std::cin >> area;

		std::cout << "Johtaja: ";
		std::cin >> leader;

		std::cout << std::endl;

		countries.push_back(Valtio{ name, population, area, leader });
	}

	for (auto country : countries) {
		std::cout <<
			"Nimi: " << country.nimi << "\n" <<
			"Asukasluku: " << country.asukasluku << "\n" <<
			"Pinta-ala: " << country.pinta_ala << "\n" <<
			"Johtaja: " << country.johtaja << "\n";
		std::cout << std::endl;
	}
}
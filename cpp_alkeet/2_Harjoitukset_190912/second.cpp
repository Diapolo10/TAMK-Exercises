#include <iostream>

int main(void) {
	double laina, korko, vuodet;

	std::cout << "Syota lainan maara (euroa): ";
	std::cin >> laina;

	std::cout << "Syota korkoprosentti: ";
	std::cin >> korko;

	std::cout << "Syota laina-aika (vuosia): ";
	std::cin >> vuodet;

	std::cout << "Lainan korot laina-ajalta ovat " << laina * korko * vuodet / 100 << " euroa.\n";
	return 0;
}
#include <iostream>
#include <string>

using std::string;
using namespace std::string_literals;

int main(void) {
	double input, balance = 0.0;
	int choice;

	std::cout << u8"Tervetuloa pankkiin!\n"s;

	while (true) {

		std::cout << u8"Tilillä on rahaa " << (long)balance << " Euroa.\n"s;

		std::cout << u8"Valitse toiminto (1. Talleta, 2. Nosta, 3. Lopeta): "s;
		std::cin >> choice;

		switch (choice) {
			case 1:

				std::cout << u8"Syötä talletettava rahasumma: "s;
				std::cin >> input;

				if (input <= 0) {
					std::cout << u8"Syötetty luku ei kelpaa. Et voi tallettaa negatiivista rahasummaa.\n"s;
				}

				else if (input + balance < balance) {
					// In case of overflow
					std::cout << u8"Syötetty luku ei kelpaa. Pankkitilillä ei ole tarpeeksi tilaa.\n"s;
				}

				else {
					balance += input;
				}

			break;
			case 2:

				std::cout << u8"Syötä nostettava rahasumma: "s;
				std::cin >> input;

				if (input <= 0) {
					std::cout << u8"Syötetty luku ei kelpaa. Et voi nostaa negatiivista rahasummaa.\n"s;
				}

				else if (balance - input < 0) {
					std::cout << u8"Tilin varat eivät riitä. Pankkitilin saldo ei voi mennä negatiiviseksi.\n"s;
				}

				else {
					balance -= input;
				}

			break;
			case 3:

				std::cout << u8"Näkemiin!\n"s;
				return EXIT_SUCCESS;

			break;
			default:

				std::cout << "Annettua komentoa ei tueta.\n";
			break;
		}
		std::cout << std::endl;

	}
}

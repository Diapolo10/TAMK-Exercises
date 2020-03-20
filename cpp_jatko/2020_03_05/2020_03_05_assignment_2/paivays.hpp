#pragma once

#include <iostream>
#include <string>

class Paivays {
	public:
		int getPaiva();
		void setPaiva(int);

		int getKuukausi();
		void setKuukausi(int);

		int getVuosi();
		void setVuosi(int);

		void tulostaPaivays();

		void operator++();
		void setDate();
	private:
		int paiva;
		int kuukausi;
		int vuosi;
};

template<typename T>
T get_input(const std::string& prompt) {
	T input{};

	while (true) {
		std::cout << prompt;

		if (!(std::cin >> input)) {
			std::cerr << u8"Invalid input.\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		break;
	}

	return input;
}

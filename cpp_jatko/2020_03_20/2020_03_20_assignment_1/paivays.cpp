#include <array>
#include <iostream>

#include "paivays.hpp"

const int Paivays::getPaiva() {
	return this->paiva;
}

void Paivays::setPaiva(int day) {
	this->paiva = day;
}

const int Paivays::getKuukausi() {
	return this->kuukausi;
}

void Paivays::setKuukausi(int month) {
	this->kuukausi = month;
}

const int Paivays::getVuosi() {
	return this->vuosi;
}

void Paivays::setVuosi(int year) {
	this->vuosi = year;
}

const void Paivays::tulostaPaivays() {
	std::cout << this->getPaiva() << '.' << this->getKuukausi() << '.' << this->getVuosi() << std::endl;
}

void Paivays::operator++() {
	auto date = this->getPaiva();
	auto month = this->getKuukausi();
	auto year = this->getVuosi();
	bool odd_month{ false };
	const std::array<int, 5> odd_months{ 2, 4, 6, 9, 11 };

	switch (date) {
	case 28:
		if (month == 2) {
			date = 1;
			if (month < 12) {
				++month;
			}
			else {
				month = 1;
				++year;
			}
		}
		else ++date;
		break;
	case 30:
		for (auto m : odd_months) {
			if (m == month) {
				odd_month = true;
				break;
			}
		}
		if (odd_month) {
			date = 1;
			if (month < 12) {
				++month;
			}
			else {
				month = 1;
				++year;
			}
		}
		else ++date;
		break;
	case 31:
		date = 1;
		if (month < 12) {
			++month;
		}
		else {
			month = 1;
			++year;
		}
		break;
	default:
		++date;
	}

	this->setPaiva(date);
	this->setKuukausi(month);
	this->setVuosi(year);
}

void Paivays::setDate() {
	auto date = get_input<int>("Paiva: ");
	auto month = get_input<int>("Kuukausi: ");
	auto year = get_input<int>("Vuosi: ");

	this->setPaiva(date);
	this->setKuukausi(month);
	this->setVuosi(year);
}

Paivays::Paivays() {
	this->setPaiva(1);
	this->setKuukausi(1);
	this->setVuosi(1970);
}

Paivays::Paivays(int day, int month, int year) {
	this->setPaiva(day);
	this->setKuukausi(month);
	this->setVuosi(year);
}

Paivays::~Paivays() {
	std::cout << "Paivays destructor for ";
	this->tulostaPaivays();
}

const Paivays Kalenterimerkinta::getPaivays() {
	return this->paivays;
}


void Kalenterimerkinta::setPaivays(Paivays date) {
	this->paivays = date;
}

const std::string Kalenterimerkinta::getAsia() {
	return this->asia;
}

void Kalenterimerkinta::setAsia(std::string note) {
	this->asia = note;
}

const bool Kalenterimerkinta::getMuistutus() {
	return this->muistutus;
}

void Kalenterimerkinta::setMuistutus(bool reminder) {
	this->muistutus = reminder;
}

void Kalenterimerkinta::tulostaMerkinta() {
	auto date = this->getPaivays();
	std::cout << "Kalenterimerkinta:\n"
		<< "Paivays: "; date.tulostaPaivays();
	std::cout << "Asia: " << this->getAsia() << '\n'
		<< "Muistutus: " << (this->getMuistutus() ? "Enabled" : "Disabled");
	std::cout << std::endl;
}

void Kalenterimerkinta::kysyTiedot() {
	
	auto date = Paivays{};
	date.setDate();

	auto note = get_input<std::string>("Asia: ");
	auto temp = get_input<std::string>("Muistutus? (Y/n): ");
	auto reminder = temp.size() && (temp[0] == 'y' || temp[0] == 'Y');

	this->setPaivays(date);
	this->setAsia(note);
	this->setMuistutus(reminder);
}

Kalenterimerkinta::Kalenterimerkinta() {
	this->setPaivays(Paivays{});
	this->setAsia("");
	this->setMuistutus(false);
}

Kalenterimerkinta::Kalenterimerkinta(Paivays date, std::string note, bool reminder) {
	this->setPaivays(date);
	this->setAsia(note);
	this->setMuistutus(reminder);
}

Kalenterimerkinta::~Kalenterimerkinta() {
	std::cout << "Merkinta destructor run" << std::endl;
}

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
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		break;
	}

	return input;
}

template<>
std::string get_input(const std::string& prompt) {
	std::string input{};

	while (true) {
		std::cout << prompt;

		if (!(std::getline(std::cin, input))) {
			std::cerr << u8"Invalid input.\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		break;
	}

	return input;
}

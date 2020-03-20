#include <array>
#include <iostream>

#include "paivays.hpp"

int Paivays::getPaiva() {
	return this->paiva;
}

void Paivays::setPaiva(int day) {
	this->paiva = day;
}

int Paivays::getKuukausi() {
	return this->kuukausi;
}

void Paivays::setKuukausi(int month) {
	this->kuukausi = month;
}

int Paivays::getVuosi() {
	return this->vuosi;
}

void Paivays::setVuosi(int year) {
	this->vuosi = year;
}

void Paivays::tulostaPaivays() {
	std::cout << this->getPaiva() << '.' << this->getKuukausi() << '.' << this->getVuosi();
	std::cout << "\n";
}

void Paivays::operator++() {
	auto date = this->getPaiva();
	auto month = this->getKuukausi();
	auto year = this->getVuosi();
	bool odd_month{false};
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

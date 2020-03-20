#include <iostream>

#include "henkilo.hpp"

std::string Henkilo::getNimi() {
	return this->nimi;
}

void Henkilo::setNimi(std::string name) {
	this->nimi = name;
}

int Henkilo::getIka() {
	return this->ika;
}

void Henkilo::setIka(int age) {
	this->ika = age;
}

void Henkilo::tulostaHenkilonTiedot() {
	std::cout << "Nimi: " << this->getNimi() << std::endl;
	std::cout << "Ika: " << this->getIka() << std::endl;
}


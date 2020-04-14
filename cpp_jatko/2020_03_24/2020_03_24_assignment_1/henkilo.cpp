#include <iostream>

#include "henkilo.hpp"

const std::string Henkilo::getNimi() {
	return this->nimi;
}

void Henkilo::setNimi(const std::string& name) {
	this->nimi = name;
}

const int Henkilo::getIka() {
	return this->ika;
}

void Henkilo::setIka(const int& age) {
	this->ika = age;
}

const Osoite Henkilo::getOsoite() {
	return this->osoite;
}

void Henkilo::setOsoite(const Osoite& address) {
	this->osoite = address;
}

const void Henkilo::tulostaHenkilonTiedot() {
	std::cout << "Nimi: " << this->getNimi() << std::endl;
	std::cout << "Ika: " << this->getIka() << "\n" << std::endl;
	auto address = this->getOsoite();
	address.tulostaTiedot();
}

Henkilo::Henkilo() {
	this->setNimi("");
	this->setIka(0);
	this->setOsoite(Osoite{});
}

Henkilo::Henkilo(const std::string& name, const int& age) {
	this->setNimi(name);
	this->setIka(age);
	this->setOsoite(Osoite{});
}

Henkilo::Henkilo(const std::string& name, const int& age, const Osoite& address) {
	this->setNimi(name);
	this->setIka(age);
	this->setOsoite(address);
}

Henkilo::Henkilo(const Henkilo& other) {
	this->setNimi(other.nimi);
	this->setIka(other.ika);
	this->setOsoite(other.osoite);
}

Henkilo::~Henkilo() {
	std::cout << "Henkilo destructor for:\n";
	this->tulostaHenkilonTiedot();
}

const std::string Osoite::getKatuosoite() {
	return this->katuosoite;
}

void Osoite::setKatuosoite(const std::string& street_address) {
	this->katuosoite = street_address;
}

const std::string Osoite::getPostinumero() {
	return this->postinumero;
}

void Osoite::setPostinumero(const std::string& postal_code) {
	this->postinumero = postal_code;
}

const std::string Osoite::getKunta() {
	return this->kunta;
}

void Osoite::setKunta(const std::string& city) {
	this->kunta = city;
}

const void Osoite::tulostaTiedot() {
	std::cout
		<< "Osoite:\n"
		<< "Katuosoite: " << this->getKatuosoite() << '\n'
		<< "Postinumero: " << this->getPostinumero() << '\n'
		<< "Kunta: " << this->getKunta() << '\n';
}

Osoite::Osoite() {
	this->setKatuosoite("");
	this->setPostinumero("0");
	this->setKunta("");
}

Osoite::Osoite(const std::string& street_address, const std::string& postal_code, const std::string& city) {
	this->setKatuosoite(street_address);
	this->setPostinumero(postal_code);
	this->setKunta(city);
}

Osoite::~Osoite() {
	std::cout << "Address '" << this->getKatuosoite() << "' destroyed." << std::endl;
}

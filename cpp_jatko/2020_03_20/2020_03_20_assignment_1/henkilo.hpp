#pragma once

#include <string>

class Osoite {
private:
	std::string katuosoite{};
	std::string postinumero{};
	std::string kunta{};

public:

	Osoite();
	Osoite(std::string, std::string, std::string);
	~Osoite();

	const std::string getKatuosoite();
	void setKatuosoite(std::string);

	const std::string getPostinumero();
	void setPostinumero(std::string);

	const std::string getKunta();
	void setKunta(std::string);
	
	const void tulostaTiedot();
};

class Henkilo {
private:
	std::string nimi;
	int ika;
	Osoite osoite{};

public:

	Henkilo();
	Henkilo(std::string, int, Osoite);
	~Henkilo();

	const std::string getNimi();
	void setNimi(std::string);

	const int getIka();
	void setIka(int);

	const Osoite getOsoite();
	void setOsoite(Osoite);

	const void tulostaHenkilonTiedot();
};

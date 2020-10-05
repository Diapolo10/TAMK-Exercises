#pragma once

#include <string>

class Osoite {
private:
	std::string katuosoite{};
	std::string postinumero{};
	std::string kunta{};

public:

	Osoite();
	Osoite(const std::string&, const std::string&, const std::string&);
	~Osoite();

	const std::string getKatuosoite();
	void setKatuosoite(const std::string&);

	const std::string getPostinumero();
	void setPostinumero(const std::string&);

	const std::string getKunta();
	void setKunta(const std::string&);

	const void tulostaTiedot();
};

class Henkilo {
private:
	std::string nimi;
	int ika;
	Osoite osoite{};

public:

	Henkilo();
	Henkilo(const std::string&, const int&);
	Henkilo(const std::string&, const int&, const Osoite&);
	Henkilo(const Henkilo&);
	~Henkilo();

	const std::string getNimi();
	void setNimi(const std::string&);

	const int getIka();
	void setIka(const int&);

	const Osoite getOsoite();
	void setOsoite(const Osoite&);

	const void tulostaHenkilonTiedot();
};

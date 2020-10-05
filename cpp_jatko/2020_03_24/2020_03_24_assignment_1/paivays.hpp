#pragma once

#include <iostream>
#include <string>

class Paivays {
public:
	Paivays();
	Paivays(const int&, const int&, const int&);
	~Paivays();


	const int getPaiva();
	void setPaiva(const int&);

	const int getKuukausi();
	void setKuukausi(const int&);

	const int getVuosi();
	void setVuosi(const int&);

	const void tulostaPaivays();

	void operator++();
	void setDate();
private:
	int paiva;
	int kuukausi;
	int vuosi;
};

class Kalenterimerkinta {
private:

	Paivays paivays;
	std::string asia;
	bool muistutus;

public:

	Kalenterimerkinta();
	Kalenterimerkinta(const Paivays&, const std::string&, const bool&);
	Kalenterimerkinta(const Kalenterimerkinta&);
	~Kalenterimerkinta();

	const Paivays getPaivays();
	void setPaivays(const Paivays&);

	const std::string getAsia();
	void setAsia(const std::string&);

	const bool getMuistutus();
	void setMuistutus(const bool&);

	void tulostaMerkinta();
	void kysyTiedot();
};

template<typename T>
T get_input(const std::string&);

template<>
std::string get_input(const std::string&);

template<>
bool get_input(const std::string&);

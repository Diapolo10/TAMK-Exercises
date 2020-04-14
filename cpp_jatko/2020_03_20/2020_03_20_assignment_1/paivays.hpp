#pragma once

#include <iostream>
#include <string>

class Paivays {
public:
	Paivays();
	Paivays(int, int, int);
	~Paivays();


	const int getPaiva();
	void setPaiva(int);

	const int getKuukausi();
	void setKuukausi(int);

	const int getVuosi();
	void setVuosi(int);

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
	Kalenterimerkinta(Paivays, std::string, bool);
	~Kalenterimerkinta();

	const Paivays getPaivays();
	void setPaivays(Paivays);

	const std::string getAsia();
	void setAsia(std::string);

	const bool getMuistutus();
	void setMuistutus(bool);

	void tulostaMerkinta();
	void kysyTiedot();
};

template<typename T>
T get_input(const std::string& prompt);

template<>
std::string get_input(const std::string& prompt);

#pragma once

#include <string>

class Henkilo {
	private:
		std::string nimi;
		int ika;

	public:
		std::string getNimi();
		void setNimi(std::string);

		int getIka();
		void setIka(int);

		void tulostaHenkilonTiedot(void);
};

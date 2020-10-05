#include "henkilo.hpp"
#include "paivays.hpp"

int main() {
	Henkilo nep{ "Neptune", 21, Osoite{"428 Rainbow Road", "12345", "Planeptune"} };
	Henkilo nepgear{};
	nepgear.setNimi("Nepgear");
	nepgear.setIka(19);
	nepgear.setOsoite(Osoite{ "431 Rainbow Road", "12345", "Planeptune" });

	nep.tulostaHenkilonTiedot();
	std::cout << std::endl;
	nepgear.tulostaHenkilonTiedot();
	std::cout << std::endl;

	std::cout << std::endl;

	Kalenterimerkinta birthday{ Paivays{24, 1, 1998}, "Syntymäpäivä", false };
	Kalenterimerkinta something{};
	something.kysyTiedot();

	birthday.tulostaMerkinta();
	something.tulostaMerkinta();
}

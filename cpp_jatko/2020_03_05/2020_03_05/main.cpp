#include "henkilo.hpp"


int main() {
	Henkilo guy{};
	Henkilo gal{};

	guy.setNimi("Rey Starling");
	guy.setIka(21);

	gal.setNimi("Bayonetta");
	gal.setIka(40);

	guy.tulostaHenkilonTiedot();
	gal.tulostaHenkilonTiedot();
}
#include "paivays.hpp"

int main() {
	Paivays tanaan{};
	Paivays huomenna{};

	tanaan.setPaiva(19);
	tanaan.setKuukausi(3);
	tanaan.setVuosi(2020);

	huomenna.setPaiva(20);
	huomenna.setKuukausi(3);
	huomenna.setVuosi(2020);

	tanaan.tulostaPaivays();
	huomenna.tulostaPaivays();

	for (int _{}; _ < 30; ++_) {
		++tanaan;
		tanaan.tulostaPaivays();
	}

	Paivays uusi;
	uusi.setDate();
	uusi.tulostaPaivays();
}
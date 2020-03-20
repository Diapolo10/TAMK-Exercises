#include "henkilo.hpp"
#include "paivays.hpp"

void test_destructor() {
	// New scope, objects destroyed in reverse order of creation
	Henkilo alfred("Alfred E. Neumann", 57); // First created, last destroyed 
	Paivays something(23, 4, 5678); // Last created, first destroyed
}

int main() {
	Henkilo lari("Lari", 22); // First created, last destroyed 
	lari.tulostaHenkilonTiedot();
	Paivays bd(24, 1, 1998);
	bd.tulostaPaivays();

	Henkilo henkilot[10];

	for (auto& person : henkilot) {
		person.tulostaHenkilonTiedot();
	}

	if (true) {
		// New scope, objects destroyed in reverse order of creation
		Henkilo shulk("Shulk", 19); // First created, last destroyed 
		Paivays spam(31, 12, 2023); // Last created, first destroyed
	}

	int foo{ 1 };
	while (foo--) {
		// New scope, objects destroyed in reverse order of creation
		Henkilo john("John Romero", 42); // First created, last destroyed 
		Paivays eggs(12, 3, 2345); // Last created, first destroyed
	}

	test_destructor();

	Henkilo* pekka = new Henkilo("Pekka", 21); // First created, last destroyed 
	delete pekka; // Last created, first destroyed
}

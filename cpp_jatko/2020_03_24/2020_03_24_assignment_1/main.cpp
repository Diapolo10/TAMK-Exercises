#include <vector>

#include "henkilo.hpp"
#include "paivays.hpp"

void doSomethingArvoparametri(Kalenterimerkinta foo) {
	Kalenterimerkinta bar{ foo };
	bar.tulostaMerkinta();
}

void doSomethingViittausparametri(Kalenterimerkinta& foo) {
	Kalenterimerkinta bar{ foo };
	bar.tulostaMerkinta();
}

void task_1() {
	Kalenterimerkinta spam{};
	doSomethingArvoparametri(spam);
	doSomethingViittausparametri(spam);
}

void add_person(std::vector<Henkilo>& people) {
	auto name = get_input<std::string>("Nimi: ");
	auto age = get_input<int>("Ika: ");
	people.push_back(Henkilo{ name, age });
}

void remove_person(std::vector<Henkilo>& people) {
	auto name = get_input<std::string>("Nimi: ");

	int idx{};
	for (auto& person : people) {
		if (person.getNimi() == name) {
			std::cout << "Poistettu" << std::endl;
			people.erase(people.begin() + idx);
			return;
		}
		++idx;
	}
	std::cout << "Nimi ei luettelossa" << std::endl;
}

void task_2() {
	std::vector<Henkilo> people{};
	int option{};

	while (true) {
		option = get_input<int>(
			"1. Lisaa uusi henkilo\n"
			"2. Poista henkilo\n"
			"3. Tulosta henkilot\n"
			"4. Lopeta\n"
			"\nValitse toiminto: "
			);

		switch (option) {
		case 1:
			add_person(people);
			break;

		case 2:
			remove_person(people);
			break;

		case 3:
			for (auto& person : people) {
				std::cout << std::endl << person.getNimi();
			}
			std::cout << std::endl;
			break;
		case 4:
			return;
			break;
		default:
			std::cout << "Virheellinen komento" << std::endl;
		}
	}
}

void task_3() {
	std::vector<std::string> names{ "Harriot", "Cole", "Coomer", "Gordon", "Benry" };
	std::vector<Henkilo*> people{};
	std::vector<Henkilo> more_people{};

	std::cout << "Storing pointers" << std::endl;

	for (auto& name : names) {
		people.push_back(new Henkilo{ name, 42 });
	}

	std::cout << "Storing objects" << std::endl;

	for (auto& name : names) {
		more_people.push_back(Henkilo{ name, 42 });
	}
}

int main() {
	task_1();
	task_2();
	task_3();
}
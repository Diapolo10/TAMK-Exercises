#include <iostream>
#include <random>

#include "henkilo.hpp"

int main() {

	std::random_device rd;
	std::mt19937 rng{ rd() };
	std::uniform_int_distribution<int> distribution(0, 2);

	auto first = Student{};
	auto second = Student{ "Kalle", 42, "12345678", 42 };
	auto third = Student{ second };

	auto ichi = Teacher{};
	auto ni = Teacher{ "Valle", 49, "autonomy" };
	auto san = Teacher{ni};

	std::vector<Person*> people;

	for (int i{}; i<100; ++i) {
		switch (distribution(rng)) {
		case 0:
			people.push_back(new Person{});
			break;
		case 1:
			people.push_back(new Student{});
			break;
		case 2:
			people.push_back(new Teacher{});
			break;
		default:
			std::cout << "RNG problem\n";
		}
	}

	for (auto& p : people) {
		delete p;
	}


}
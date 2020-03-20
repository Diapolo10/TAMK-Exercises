#include "murtoluku.hpp"

int main() {
	Murtoluku test(3, 4);
	Murtoluku test2(9, 12);

	test2.sievenna();
	if (test == test2) {
		std::cout << "Sievennys onnistui\n";
	}
	test2.tulosta();

	Murtoluku foo{};
	foo.kysyTiedot();
	foo.tulosta();
}
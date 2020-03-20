#pragma once

#include <iostream>
#include <string>

template<typename T>
T get_input(const std::string& prompt) {
	T input{};

	while (true) {
		std::cout << prompt;

		if (!(std::cin >> input)) {
			std::cerr << u8"Invalid input.\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		break;
	}

	return input;
}

class Murtoluku {
private:
	int numerator;
	int denominator;

	int gcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		return this->gcd(b, a % b);
	}
public:
	Murtoluku() {
		this->numerator = 0;
		this->denominator = 0;
	}

	Murtoluku(int num, int den) {
		this->numerator = num;
		this->denominator = den;
	}

	~Murtoluku() {
		std::cout << "Number destroyed" << std::endl;
	}

	bool operator==(Murtoluku& other) {
		return this->get_numerator() == other.get_numerator() && this->get_denominator() == other.get_denominator();
	}

	int get_numerator() {
		return this->numerator;
	}

	void set_numerator(int num) {
		this->numerator = num;
	}

	int get_denominator() {
		return this->denominator;
	}

	void set_denominator(int den) {
		this->denominator = den;
	}

	void kysyTiedot() {
		this->set_numerator(get_input<int>("Osoittaja: "));
		this->set_denominator(get_input<int>("Nimittaja: "));
	}

	void tulosta() {
		std::cout << this->get_numerator() << '/' << this->get_denominator() << std::endl;
	}

	void sievenna() {
		int divisor = gcd(this->get_numerator(), this->get_denominator());
		if (divisor != 1) {
			this->set_numerator(this->get_numerator() / divisor);
			this->set_denominator(this->get_denominator() / divisor);
		}
	}

};

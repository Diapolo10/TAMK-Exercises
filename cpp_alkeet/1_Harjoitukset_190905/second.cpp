// -*- lsst-c++ -*-
/// Copyright Lari Liuhamo, 2019

#include <iostream>
#include <string>

using std::string;

int main2(void) {

	int number;
	string input = "Syota luku: ";
	string output = "Sy\x94tit luvun ";

	std::cout << input;
	std::cin >> number;

	std::cout << output << number << "\n";
	return 0;
}

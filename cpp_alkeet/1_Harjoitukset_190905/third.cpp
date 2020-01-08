// -*- lsst-c++ -*-
/// Copyright Lari Liuhamo, 2019

#include <iostream>
#include <string>

using std::string;

int main3(void) {
	int age;
	string input = "Anna ik\x84si: ";
	
	std::cout << input;
	std::cin >> age;

	std::cout << "50 vuoden kuluttua olet " << age+50 << " vuotias\n";
	return 0;
}


#include <iostream>
#include <string>
#include "fmt/format.h"

using std::string;

int main(void) {
	// Prints 'Hello, world!'
    std::cout << "Hello, world!\n";
	std::cout << "Give me a number: ";
	int num;
	std::cin >> num;
	std::cout << "Number " << num << " entered.\n";
	string foo = fmt::format("My name is {}", "Foo");
	std::cout << foo;
}

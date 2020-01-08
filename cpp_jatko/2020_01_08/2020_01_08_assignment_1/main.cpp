#include <iostream>

int main() {
	int spam = 42;
	int *eggs = &spam;
	*eggs = 7;

	std::cout << spam << "\n";
	std::cout << &spam << "\n";
	std::cout << eggs << "\n";
	std::cout << &eggs << "\n";
	std::cout << *eggs << "\n";
	
	std::cout << "spam == *eggs is " << (spam == *eggs ? "true" : "false") << "\n";

	std::cout << sizeof spam << "\n";
	std::cout << sizeof eggs << "\n";

	int* herring;
	// std::cout << *herring << "\n"; // C4700 - Uninitialised local variable 'herring' used
	herring = nullptr;
	// std::cout << *herring << "\n"; // C6011 - Dereferencing NULL pointer 'herring'

}
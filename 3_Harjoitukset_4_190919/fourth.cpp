#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

typedef double(*ScriptFunction)(double, double);

double add(double first, double second) {
	return first + second;
}

double sub(double first, double second) {
	return first - second;
}

double mul(double first, double second) {
	return first * second;
}

double divide(double first, double second) {
	if (second != 0) {
		throw "ZeroDivisionError - Cannot divide by zero!";
	}
	return first / second;
}

int main(void) {
	string input;
	std::cout << "Enter a math operator (+, -, * and / supported): ";
	std::cin >> input;
	double first, second;
	std::cout << "Enter first number: ";
	std::cin >> first;
	std::cout << "Enter second number: ";
	std::cin >> second;

	unordered_map<string, ScriptFunction> func_mapping;
	func_mapping.emplace("+" , &add);
	func_mapping.emplace("-", &sub);
	func_mapping.emplace("*", &mul);
	func_mapping.emplace("/", &divide);

	std::cout << func_mapping[input](first, second);
}
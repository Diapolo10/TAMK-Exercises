#include <iostream>
#include <string>
#include <array>
#include <unordered_map>

using std::string;
using std::string_literals::operator""s;
using std::array;
using std::unordered_map;

unordered_map<string, double> get_input() {
	const array<string, 6> vars = {
		"annual distance"s,
		"gas price"s,
		"diesel price"s,
		"gas consumption"s,
		"diesel consumption"s,
		"diesel tax"s
	};

	unordered_map<string, double> result;

	for (auto var_name : vars) {

		double input;
		std::cout << "Please enter " << var_name << ": ";
		std::cin >> input;
		result[var_name] = input;
	
	}

	return result;
}

int main(void) {
	auto vars = get_input();
	double total_cost_gas = (
		vars["annual distance"]
		* vars["gas consumption"]
		* vars["gas price"]
	);
	double total_cost_diesel = (
		vars["annual distance"]
		* vars["diesel consumption"]
		* vars["diesel price"]
		+ vars["diesel tax"]
	);

	std::cout << "Annual cost of gas car: " << total_cost_gas << "\n";
	std::cout << "Annual cost of diesel car: " << total_cost_diesel << "\n";

	double diff = total_cost_gas - total_cost_diesel;

	if (diff < 0) {
		std::cout << "Gasoline is " << diff * -1 << " euros cheaper.\n";
	}
	else if (diff > 0) {
		std::cout << "Diesel is " << diff << " euros cheaper.\n";
	}
	else {
		std::cout << "Both cost exactly the same.\n";
	}
}
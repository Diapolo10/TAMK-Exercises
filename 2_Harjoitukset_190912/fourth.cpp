#include <iostream>
#include <vector>

using std::vector;

double mass_sum(vector<double> nums) {
	double result = .0;

	for (auto num : nums) {
		result += num;
	}

	return result;
}


vector<double>& get_passenger_masses(int n=4) {
	vector<double> masses;

	for (int i = 1; i <= n; ++i) {
		double mass;

		std::cout << "Passenger #" << i << ": ";
		std::cin >> mass;

		masses.push_back(mass);
	}

	return masses;
}


int main(void) {
	double max_mass;
	vector<double> people;

	std::cout << "Elevator's maximum supported mass: ";
	std::cin >> max_mass;

	people = get_passenger_masses();

	std::cout << ((mass_sum(people) > max_mass) ? "Overweight, elevator not usable!" : "Elevator at your service!") << "\n";
	
	return 0;
}
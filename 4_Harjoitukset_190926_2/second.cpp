#include <iostream>
#include <string>

using std::string;

int main(void) {
	double salary, salary_tax;
	double city_tax = 0.1975;

	std::cout << "Annual salary: ";
	std::cin >> salary;

	double result;

	if (salary < 17600) {
		result = 0.0;
	}
	else if (17600 <= salary && salary < 26400) {
		double extra = salary - 17600;
		result = 8.00 + extra * 0.06;
	}
	else if (26400 <= salary && salary < 43500) {
		double extra = salary - 26400;
		result = 536.00 + extra * 0.1725;
	}
	else if (43500 <= salary && salary < 76100) {
		double extra = salary - 43500;
		result = 3485.75 + extra * 0.2125;
	}
	else if (76100 <= salary) {
		double extra = salary - 76100;
		result = 10413.25 + extra * 0.3125;
	}
	else {
		throw "Invalid salary value";
	}

	std::cout << "Total taxes: " << result + salary * city_tax << "\n";
}

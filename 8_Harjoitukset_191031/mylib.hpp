#pragma once

// Config
static const int BASE_SALARY { 10 };
static const int WEEKLY_WORK_HOURS { 40 };
static const double OVERTIME_SALARY {WEEKLY_WORK_HOURS / 2};

namespace nonstd {

	// Calculates the square of a given number
	long double Nelio(double num) {
		return num * num;
	}

	// Calculates the area of a rectangle with the specified width and height
	long double Suorakaide(double width, double height) {
		return width * height;
	}

	// A function that takes a travel distance, the fuel consumption of the vehicle and the price of its fuel,
	// returning the average fuel cost of the trip. Fuel consumption can not be zero.
	long double MatkanHinta(float distance, float fuel_consumption, float fuel_price) {
		long double d{ distance }, c{ fuel_consumption }, p{ fuel_price }; // Helps prevent overflows, but may not fully negate them
		return (d / c) * p;
	}

	double palkka(double tuntimaara) {

		double base_salary{ BASE_SALARY };
		double result = base_salary * tuntimaara;

		if (tuntimaara > WEEKLY_WORK_HOURS) {
			result += (tuntimaara - WEEKLY_WORK_HOURS) * (OVERTIME_SALARY);
		}

		return result;
	}

}

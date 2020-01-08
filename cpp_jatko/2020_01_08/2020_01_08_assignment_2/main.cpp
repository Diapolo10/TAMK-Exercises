#include <iostream>

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main() {

	int foo = 42, bar = 17;
	std::cout << "Before: " << foo << ", " << bar << "\n";
	swap(foo, bar);
	std::cout << "After first swap: " << foo << ", " << bar << "\n";
	swap(&foo, &bar);
	std::cout << "After second swap: " << foo << ", " << bar << "\n";
}
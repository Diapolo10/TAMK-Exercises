#include <iostream>

const int ARRAY_SIZE = 10;

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	int arr[ARRAY_SIZE]{ 1,2,3,4,5,6,7,8,9,10 };
	int* arr_end{ arr + ARRAY_SIZE-1 };

	int* ptr{ arr };
	int* back_ptr{ arr_end };

	std::cout << "Before: ";
	for (auto num : arr) {
		std::cout << num << ", ";
	}
	std::cout << std::endl;

	while (ptr <= (arr_end - ARRAY_SIZE / 2)) {
		swap(ptr++, back_ptr--);
	}

	std::cout << "After: ";
	for (auto num : arr) {
		std::cout << num << ", ";
	}
	std::cout << std::endl;
}
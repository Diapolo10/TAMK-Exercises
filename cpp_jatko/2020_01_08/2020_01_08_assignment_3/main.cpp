#include <iostream>

const int ARRAY_SIZE = 10;

void add_one_to_each(int len, int nums[]) {
	for (int i{}; i < len; ++i) {
		++nums[i];
	}
}

void add_one_to_each(int *nums) {
	for (int* i{nums}; i < nums+ARRAY_SIZE; ++i) {
		++*i;
	}
}

int main() {
	int nums[ARRAY_SIZE]{ 0 };
	
	for (auto num : nums) {
		std::cout << num;
		std::cout << ", ";
	}
	std::cout << std::endl;

	add_one_to_each(nums);

	for (auto num : nums) {
		std::cout << num;
		std::cout << ", ";
	}
	std::cout << std::endl;

	add_one_to_each(ARRAY_SIZE, nums);

	for (auto num : nums) {
		std::cout << num;
		std::cout << ", ";
	}
	std::cout << std::endl;
}


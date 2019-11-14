#include <array>
#include <iostream>
#include <string>

using std::array; // I don't like using raw C arrays, and pointers aren't part of this course
using std::string;
using namespace std::string_literals;

// Config
const size_t INPUT_COUNT {10};


template<const size_t SIZE>
array<int, SIZE> getInput(void) {

    array<int, SIZE> nums{};

    for (size_t i {}; i < SIZE; ++i) {

        int input {};
        std::cout << u8"Syötä tenttitulos #" << i+1 << u8": ";
        std::cin >> input;
        nums[i] = input;

    }

    return nums;
}

template<const size_t SIZE>
void calcMean(array<int, SIZE> nums) {
    
    double sum {};
    size_t index {};

    for (auto num : nums) {
        sum += num;
        std::cout << "Tenttitulos #" << ++index << ": " << num << "\n";
    }

    std::cout << "Keskiarvo: " << sum / nums.size() << std::endl;
}

int main(void) {
	auto results = getInput<INPUT_COUNT>();
    calcMean(results);
}

#include <iostream>
#include <random>
#include <set>

// Config
const int MAX_LOTTERY_NUMBER {40};
const int NUM_OF_LOTTERY_NUMBERS {7};


void arvoLottonumerot(int nums[], int length) {

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<unsigned int> dist(1, MAX_LOTTERY_NUMBER);

    std::set<int> contains {};

    for (size_t i{}; i < length; ++i) {
        int rand_num = dist(mt);

        if (contains.find(rand_num) == contains.end()) {
            nums[i] = rand_num;
            contains.insert(rand_num);
        }
        else {
            --i;
        }
    }
}

int main(void) {
    
    int lottery_nums[NUM_OF_LOTTERY_NUMBERS];
    arvoLottonumerot(lottery_nums, NUM_OF_LOTTERY_NUMBERS);

    std::cout << "Generated lottery numbers: ";
    for (size_t i{}; i < NUM_OF_LOTTERY_NUMBERS; ++i) {
        std::cout << lottery_nums[i] << " ";
    }
}
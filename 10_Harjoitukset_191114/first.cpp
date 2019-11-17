#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std::string_literals;


std::vector<int> throwDie(unsigned int sides, unsigned int throw_count) {

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<unsigned int> dist(1, sides);

    std::vector<int> throws(throw_count);
    for (size_t i{}; i<throw_count; ++i) {
        throws.push_back(dist(mt));
    }

    return throws;
}


template <typename T>
T get_input(std::string prompt) {
    T input {};
    bool valid = false;
    while (!valid) {
        std::cout << prompt;
        valid = (bool)(std::cin >> input);
        if (!valid) {
            std::cout << "Invalid input, try again.\n";
            std::cin.clear();
            std::cin.ignore();
        }
    }
    return input;
}


int main(void) {
    unsigned int die_sides = get_input<unsigned int>("Number of die sides: "s);
    unsigned int throw_count = get_input<unsigned int>("Number of die throws: "s);

    auto throws = throwDie(die_sides, throw_count);

    std::cout << "\nResults of the die throws: ";

    for (auto num : throws) {
        if (num != 0) {
            std::cout << num << " ";
        }
    }
    std::cout.flush();
}
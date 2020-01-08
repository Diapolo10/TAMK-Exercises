#include <array>
#include <iostream>
#include <string>

using std::array;
using std::string;
using namespace std::string_literals;

const size_t MONTHS {12};

const array<string, MONTHS> MONTH_NAMES {
    u8"Tammikuu"s,
    u8"Helmikuu"s,
    u8"Maaliskuu"s,
    u8"Huhtikuu"s,
    u8"Toukokuu"s,
    u8"Kesäkuu"s,
    u8"Heinäkuu"s,
    u8"Elokuu"s,
    u8"Syyskuu"s,
    u8"Lokakuu"s,
    u8"Marraskuu"s,
    u8"Joulukuu"s
};

template <const size_t SIZE>
void printStars(array<int, SIZE> nums) {
    for (auto num : nums) {
        string stars(num, '*');
        std::cout << stars << "\n";
    }
    std::cout.flush();
}

int main(void) {
    array<int, MONTHS> monthly_rain {};

    for (size_t i {}; i < monthly_rain.size(); ++i) {

        int input {};

        std::cout << MONTH_NAMES[i % MONTHS] << u8"n sademäärä: ";
        std::cin >> input;

        monthly_rain[i] = input;
    }
    std::cout << std::endl;

    printStars(monthly_rain);
}

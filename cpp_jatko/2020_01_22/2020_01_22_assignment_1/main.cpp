#include <iomanip>
#include <iostream>
#include <random>

// Älkää koskeko näihin
const int MINUTE{ 60 };
const int HOUR{ 60 * MINUTE };
const int DAY{ 24 * HOUR };

// Näitä voi säätää miten huvittaa
const int RANDOM_LIMIT{ 1 * DAY };
const int RUN_COUNT{ 10 };
const int INITIAL_SECONDS{ 10000 };

void sekunnit_ajaksi(int sekunnit, int& tuntia_ulos, int& minuuttia_ulos, int& sekuntia_ulos) {

    /*
     * Ensures we only care about the seconds within one day,
     * full days are skipped as they weren't part of the specification.
     */
    sekunnit %= DAY;
    tuntia_ulos = sekunnit / HOUR;
    sekunnit = sekunnit % HOUR;
    minuuttia_ulos = sekunnit / MINUTE;
    sekuntia_ulos = sekunnit % MINUTE;
}

int main() {

    int i{};
    int tunnit{}, minuutit{}, sekunnit{};
    int seconds{INITIAL_SECONDS};

    std::random_device rseed;
    std::mt19937 rng(rseed());
    std::uniform_int_distribution<int> idist(0, RANDOM_LIMIT);
    
    std::cout << "Testataan funktiota sekunnit_ajaksi kymmenellä eri sekuntiarvolla:\n\n";

    do {

        sekunnit_ajaksi(seconds, tunnit, minuutit, sekunnit);
        
        std::cout
        << std::setw(5) << seconds << " sekuntia on "
        << std::setw(2) << tunnit << " tuntia, "
        << std::setw(2) << minuutit << " minuuttia ja "
        << std::setw(2) << sekunnit << " sekuntia.\n";
        
        seconds = idist(rng);
    }
    while (++i < RUN_COUNT);

    return 0;
}

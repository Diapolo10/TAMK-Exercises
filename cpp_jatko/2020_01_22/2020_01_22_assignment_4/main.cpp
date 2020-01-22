#include <array>
#include <iomanip>
#include <iostream>
#include <string>

// Älkää koskeko näihin
const int MINUTE{ 60 };
const int HOUR{ 60 * MINUTE };
const int DAY{ 24 * HOUR };

struct aika_ty {
    int tunnit{};
    int minuutit{};
    int sekunnit{};
};

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

void aika_sekunneiksi(int tunnit, int minuutit, int sekunnit, int& sekuntia_ulos) {
    minuutit += tunnit * 60;
    sekunnit += minuutit * 60;
    sekuntia_ulos = sekunnit % DAY;
}

template<typename T>
T get_input(std::string prompt) {

    T input{};

    while (true) {

        std::cout << prompt;

        if (!(std::cin >> input)) {
            std::cerr << u8"Väärä arvotyyppi.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        break;
    }

    return input;
}


aika_ty operator-(const aika_ty& lhs, const aika_ty& rhs) {
    aika_ty result{};

    int l_seconds, r_seconds;
    aika_sekunneiksi(lhs.tunnit, lhs.minuutit, lhs.sekunnit, l_seconds);
    aika_sekunneiksi(rhs.tunnit, rhs.minuutit, rhs.sekunnit, r_seconds);

    if (l_seconds < r_seconds) {
        std::cerr << "ImplementationError: Negative dates not supported\n"; //TODO: Define behaviour
    }

    sekunnit_ajaksi(l_seconds-r_seconds, result.tunnit, result.minuutit, result.sekunnit);

    return result;
};

aika_ty aikojen_erotus(aika_ty first, aika_ty second) {
    return first - second;
}

int main() {
    std::array<aika_ty, 2> times{};
    int counter{};
    for (auto& time : times) {

        std::cout << u8"\nPäivä #" << ++counter << ":\n";

        while (true) {
            int temp = get_input<int>("Anna tunnit: ");
            if (0 > temp || temp >= 24) { // 0-23
                std::cerr << "Annettu luku ei kelpaa.\n\n";
            }
            else {
                time.tunnit = temp;
                break;
            }
        }

        while (true) {
            int temp = get_input<int>("Anna minuutit: ");
            if (0 > temp || temp >= 60) { // 0-59
                std::cerr << "Annettu luku ei kelpaa.";
            }
            else {
                time.minuutit = temp;
                break;
            }
        }

        while (true) {
            int temp = get_input<int>("Anna sekunnit: ");
            if (0 > temp || temp >= 60) { // 0-59
                std::cerr << "Annettu luku ei kelpaa.";
            }
            else {
                time.sekunnit = temp;
                break;
            }
        }
    }

    auto result = aikojen_erotus(times[0], times[1]);

    std::cout << "\nAnnettujen aikojen erotus: "
        << std::setw(2) << std::setfill('0') << result.tunnit
        << ":"
        << std::setw(2) << std::setfill('0') << result.minuutit
        << ":"
        << std::setw(2) << std::setfill('0') << result.sekunnit
        << "\n";

    return 0;
}

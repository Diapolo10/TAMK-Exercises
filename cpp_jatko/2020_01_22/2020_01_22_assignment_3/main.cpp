#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct aika_ty {
    int tunnit{};
    int minuutit{};
    int sekunnit{};
};

bool operator==(const aika_ty& lhs, const aika_ty& rhs) {
    return (
        lhs.tunnit == rhs.tunnit &&
        lhs.minuutit == rhs.minuutit &&
        lhs.sekunnit == rhs.sekunnit
    );
}

template<typename T>
T get_input(std::string prompt) {

    T input{};

    while (true) {

        std::cout << prompt;

        if (!(std::cin >> input)) {
            std::cerr << "Väärä arvotyyppi.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        break;
    }

    return input;
};

int main() {
    aika_ty aika{};

    while (true) {
        int temp = get_input<int>("Anna tunnit: ");
        if ( 0 > temp || temp >= 24) { // 0-23
            std::cerr << "Annettu luku ei kelpaa.\n\n";
        }
        else {
            aika.tunnit = temp;
            break;
        }
    }

    while (true) {
        int temp = get_input<int>("Anna minuutit: ");
        if (0 > temp || temp >= 60) { // 0-59
            std::cerr << "Annettu luku ei kelpaa.";
        }
        else {
            aika.minuutit = temp;
            break;
        }
    }

    while (true) {
        int temp = get_input<int>("Anna sekunnit: ");
        if (0 > temp || temp >= 60) { // 0-59
            std::cerr << "Annettu luku ei kelpaa.";
        }
        else {
            aika.sekunnit = temp;
            break;
        }
    }

    std::cout << "Annettu aika: "
        << std::setw(2) << std::setfill('0') << aika.tunnit
        << ":"
        << std::setw(2) << std::setfill('0') << aika.minuutit
        << ":"
        << std::setw(2) << std::setfill('0') << aika.sekunnit
        << "\n";

    auto *aika_ptr = &aika;

    std::cout << "Annettu aika osoitinmuuttujan kautta: "
        << std::setw(2) << std::setfill('0') << (*aika_ptr).tunnit
        << ":"
        << std::setw(2) << std::setfill('0') << (*aika_ptr).minuutit
        << ":"
        << std::setw(2) << std::setfill('0') << (*aika_ptr).sekunnit
        << "\n\n";

    aika_ty first{10, 10, 0}, second;

    second.tunnit = first.tunnit;
    second.minuutit = first.minuutit;
    second.sekunnit = first.sekunnit;

    std::cout << u8"Sisällot " << (first == second ? "ovat" : u8"eivät ole") << " samat.\n";

    return 0;
}

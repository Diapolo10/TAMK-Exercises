#include <iostream>
#include <string>

using std::string;
using namespace std::string_literals;

int main(void) {
    
    double first {};
    double second {};

    std::cout << u8"Ensimmäinen luku: ";
    std::cin >> first;
    std::cout << u8"Toinen luku: ";
    std::cin >> second;

    long double result {};
    int choice {};

    std::cout
        << u8"Valitse 1, jos haluat lukujen summan.\n"
        << u8"Valitse 2, jos haluat lukujen erotuksen.\n"
        << u8"Valitse 3, jos haluat lukujen tulon.\n"
        << u8"Valitse 4, jos haluat lukujen osamäärän.\n\n";
    std::cout << u8"Toiminto: ";
    std::cin >> choice;

    std::cout << std::endl;

    switch (choice) {
        case 1:
            result = [](double x, double y) { return x + y; }(first, second);
            break;
        case 2:
            result = [](double x, double y) { return x - y; }(first, second);
            break;
        case 3:
            result = [](double x, double y) { return x * y; }(first, second);
            break;
        case 4:
            result = [](double x, double y) { return x / y; }(first, second);
            break;
        default:
            std::cerr << u8"Annetulle luvulle asetettua toimintoa ei löydy\n";
            return 1;
            break;
    }

    std::cout << "Tulos: " << result << std::endl;
}
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <cmath>

using std::string;
using namespace std::string_literals;

std::vector<std::string> string_split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

enum Triangle {
    none,        // ei kolmio
    scalene,     // epäsäännöllinen
    isosceles,   // tasakylkinen
    equilateral, // tasasivuinen
    right_angled,// suorakulmainen
};

bool onKolmiollinen(double side_1, double side_2, double side_3, Triangle& triangle) {
    std::array<double, 3> sides{side_1, side_2, side_3};
    std::sort(sides.begin(), sides.end());
    auto [cathete_1, cathete_2, hypothenuse] = sides;

    if ((cathete_1 + cathete_2 < hypothenuse) || (cathete_1 < 0 || cathete_2 < 0 || hypothenuse < 0)) {
        triangle = none;
        return false;
    }

    if (cathete_1 == cathete_2 && cathete_2 == hypothenuse) {
        triangle = equilateral;
    }
    else if (cathete_1 == cathete_2) {
        triangle = isosceles;
    }
    else if (std::pow(cathete_1, 2) + std::pow(cathete_2, 2) == std::pow(hypothenuse, 2)) {
        triangle = right_angled;
    }
    else {
        triangle = scalene;
    }

    return true;
}

template<typename T>
T get_input(string prompt, int count) {

    T input{};
    
    std::vector<std::string> split_prompt = string_split(prompt, (std::string)"{}");

    while (true) {

        std::cout << split_prompt.front() << count << split_prompt.back();

        if (!(std::cin >> input)) {
            std::cout << "Input error, try again.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        break;
    }

    return input;
}

int main() {
    std::array<double, 3> lengths{};
    int count = 1;
    for (auto& num : lengths) {
        num = get_input<double>("Length of side #{}: "s, count++);
    }

    Triangle kolmio{};
    bool success = onKolmiollinen(lengths[0], lengths[1], lengths[2], kolmio);

    string triangle = "";

    if (success) {
        switch (kolmio) {
            case scalene:
                triangle = u8"epäsäännöllinen kolmio";
                break;
            case isosceles:
                triangle = "tasakylkinen kolmio";
                break;
            case equilateral:
                triangle = "tasasivuinen kolmio";
                break;
            case right_angled:
                triangle = "suorakulmainen kolmio";
                break;
            default:
                triangle = "ei-kolmio";
                break;
        }

        std::cout << "Annetuista sivuista voidaan muodostaa " << triangle << ".\n";
    }
    else {
        std::cout << "Annetuista sivuista ei voi muodostaa kolmiota.\n";
    }
    return 0;
}

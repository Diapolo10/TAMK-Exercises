#include <algorithm>
#include <array>
#include <iostream>

const int ROUNDS {5};

std::array<double, ROUNDS> dartsScores(void) {
    std::array<double, ROUNDS> scores {};

    for (size_t i{}; i < ROUNDS; ++i) {
        
        double score{};
        
        while (true) {
            
            std::cout << "Score for round #" << i+1 << ": ";
            std::cin >> score;

            if (std::cin.fail()) {
                std::cout << "Erroneous input.\n";
                std::cin.clear();
                std::cin.ignore();
            }
            else {
                break;
            }
        }

        scores[i] = score;
    }
    return scores;
}

int main(void) {
    std::array<double, ROUNDS> scores = dartsScores();

    double max = *std::max_element(scores.begin(), scores.end());
    std::cout << "Best score in " << ROUNDS << " rounds: " << max << std::endl;
}
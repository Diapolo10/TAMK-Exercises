// C++17

#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>

std::vector<std::pair<int, int>> grep(std::string file_name, std::string substring) {
	std::vector<std::pair<int, int>> line_nums{};
	std::string input;

    std::ifstream input_file;
    input_file.open(file_name);

	int line_count{};
    int matches{};
	while (input_file >> input) {

        matches = 0;
	    ++line_count;
        std::string::size_type pos = 0;

        while ((pos = input.find(substring, pos)) != std::string::npos) {
            ++matches;
            pos += substring.length();
        }

        if (matches) {
            line_nums.push_back({line_count, matches});
        }
	}

    input_file.close();

	return line_nums;
}

template<typename T>
T get_input(const std::string& prompt) {
    T input{};

    while (true) {
        std::cout << prompt;

        if (!(std::getline(std::cin, input))) {
            std::cerr << u8"Invalid input.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        break;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return input;
}

int main() {
    auto file_name = get_input<std::string>("Filename: ");
    auto query = get_input<std::string>("Substring: ");

    auto line_numbers = grep(file_name, query);

    std::cout << "Line numbers: [";

    int total_matches{};
    for (auto& [line, matches] : line_numbers) {
        total_matches += matches;
        std::cout << line << ", ";
    }
    std::cout << "]\n";
    std::cout << "Total matches: " << total_matches;
}

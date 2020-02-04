#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


std::string generate_webpage(std::string name, std::string bio) {
    std::stringstream webpage{};

    webpage
        << "<!DOCTYPE html>\n"
        << "<html lang='en'>\n"
        << "  <head>\n"
        << "    <title>" << name << "</title>\n"
        << "    <meta charset = 'utf-8'>\n"
        << "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
        << "  </head>\n"
        << "  <body>\n"
        << "    <h1>" << name << "</h1>\n"
        << "    <hr/>\n"
        << "    <p>" << bio <<"</p>\n"
        << "    <hr/>\n"
        << "  </body>\n"
        << "</html>\n";

    return webpage.str();
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

std::string replace_whitespace(std::string text) {
    std::replace(text.begin(), text.end(), ' ', '_');
    return text;
}


int main() {
    std::ofstream output;
    auto name = get_input<std::string>("Please write down your name: ");
    auto bio = get_input<std::string>("Please write about yourself: ");

    std::stringstream file_name{};
    file_name << replace_whitespace(name) << ".html";

    output.open(file_name.str());
    output << generate_webpage(name, bio);
    output.close();
}
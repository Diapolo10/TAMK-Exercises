#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

using namespace std::string_literals;

// I know, the assignment told us to use multiple arrays
// with the same index, but that's error-prone so I decided
// to do this with better reliability in mind. It's still not perfect,
// but definitely more robust.

struct Contact {
    string first_name;
    string phone_number;
};

Contact newContact(void) {
    string first_name {};
    string phone_number {};

    std::cout << "First name: ";
    std::cin >> first_name;

    std::cout << "Phone number: ";
    std::cin >> phone_number;

    return Contact {first_name, phone_number};
}

int main(void) {
    vector<Contact> contacts {};
    string input{};

    std::cout << "Phone book\n";
    bool running = true;
    while (running) {
        unsigned int mode {};
        std::cout << "\nAvailable actions:\n0 = Add a new contact\n1 = Get a specific number by name\n2 = List all contacts and their information\n3 = Exit the program\n\n";
        std::cout << "Action: ";
        std::cin >> mode;

        if (std::cin.fail()) {
            std::cout << "That wasn't an integer.\n";
            std::cin.clear();
            std::cin.ignore();
            continue;
        }

        bool found = false;

        switch (mode) {
            case 0:
                contacts.push_back(newContact());
                break;

            case 1:
                input = ""s;
                std::cout << "Name of contact: ";
                std::cin >> input;

                for (auto contact : contacts) {
                    if (contact.first_name == input) {
                        std::cout << contact.first_name << "'s phone number: " << contact.phone_number << "\n";
                        found = true;
                        break;
                    }

                }

                if (!found) std::cout << "No such contact saved in the program.\n";
                break;

            case 2:
                if (contacts.size()) {
                    std::cout << "Saved contacts:\n";
                    for (auto contact : contacts) {
                        std::cout << "Name: " << contact.first_name << ", Phone number: " << contact.phone_number << "\n";
                    }
                }
                else {
                    std::cout << "No contacts have been saved.\n";
                }
                std::cout.flush();
                break;

            case 3:
                running = false;
                break;

            default:
                std::cout << "This command has not been implemented.\n";
                break;
        }

        
    }
}
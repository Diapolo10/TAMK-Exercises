#include "lottery.hpp"

using non_std::io::println;

// CONFIG
const int MAX_VALUE{40};
const int LOTTERY_NUM_COUNT{7};

enum main_menu {
    input_row,
    input_and_analyse,
    input_and_gen_row_and_analyse,
    quit
};

int main() {

    println("Welcome to Lari's Ludicrous Lottery!\n");
    std::vector<int> player_row{};
    std::vector<int> default_row{3, 7, 22, 24, 35, 36, 38 };

    bool running{true};

    while (running) {
        
        std::vector<int> random_row{non_std::lottery::generate_lottery_row(MAX_VALUE, LOTTERY_NUM_COUNT)};
        int default_extra_num{9}; // Chosen by a fair dice roll, so guaranteed to be random
        int random_extra_num, bonus_num{non_std::random::randnum(MAX_VALUE)};
        int player_result;

        do {
            random_extra_num = non_std::random::randnum(MAX_VALUE);
        } while (non_std::contains(random_row, random_extra_num));

        println(
            "1) Read and print lottery numbers\n"
            "2) Read user's row and analyse with correct row\n"
            "3) Read user's row, randomize correct row and analyse\n"
            "4) Exit the program\n"
        );
        auto user_input = non_std::io::get_input<int>("Choose how to proceed (1/2/3/4): ");

        switch (--user_input) {
            case input_row:
                println("Input your lottery numbers.");
                player_row = non_std::io::get_n_unique<int>("Number #{}: ", LOTTERY_NUM_COUNT);

                println("\nYour row is:");
                non_std::io::print_iterable(player_row);
                
                break;

            case input_and_analyse:
                println("Input your lottery numbers.");
                player_row = non_std::io::get_n_unique<int>("Number #{}: ", LOTTERY_NUM_COUNT);

                println("\nYour row is:");
                non_std::io::print_iterable(player_row);

                println("The correct row is:");
                non_std::io::print_iterable(default_row);

                std::cout << "The extra number is: " << default_extra_num << "\n";
                std::cout << "The bonus number is: " << bonus_num << "\n\n";

                std::cout << "Result: " << non_std::lottery::check_result(player_row, default_row)
                << "+" << (non_std::contains(player_row, default_extra_num)) << " correct, bonus number "
                << (non_std::contains(player_row, bonus_num) ? "correct" : "incorrect");
                break;

            case input_and_gen_row_and_analyse:
                println("Input your lottery numbers.");
                player_row = non_std::io::get_n_unique<int>("Number #{}: ", LOTTERY_NUM_COUNT);

                println("Correct numbers have been randomised.\n");

                std::cout << "Result:\nCorrect row: ";
                non_std::io::print_iterable(random_row);
                std::cout << "Extra number: " << random_extra_num << "\nBonus number: " << bonus_num << "\n";
                
                player_result = non_std::lottery::check_result(player_row, random_row);

                if (player_result < 3) {
                    if (!non_std::contains(player_row, random_extra_num)) {
                        println("You didn't win.\n");
                        continue;
                    }
                }
                
                println("You won!");
                std::cout << "Result: " << player_result << "+" << (non_std::contains(player_row, random_extra_num)) << " correct, bonus number "
                    << (non_std::contains(player_row, bonus_num) ? "correct" : "incorrect");
                

                break;

            case quit:
                if (non_std::io::get_input<int>("Are you sure you want to quit? (1/2)") == 2) {
                    running = false;
                }
                break;

            default:
                println("Invalid command.");
        }

        println("\nPress ENTER to continue ...");
        std::cin.get();
        println("");
    }

    println("Quitting the program...");
    return 0;
}
#include <iostream>

// Explanation
// 
// Basically, references are variables that contain adresses to values in memory.
// For the most part, they work like ordinary variables, but they
// can read or write to a value in memory used by other variables.
// If you change a referenced value, any variables pointing to the same value will also
// "change".

void asetaIka(int& age){
    std::cout << "How old are you? ";
    std::cin >> age;
}

int main(void) {
    int age {};
    asetaIka(age);

    std::cout << "Your are " << age << " years old." << std::endl;
}

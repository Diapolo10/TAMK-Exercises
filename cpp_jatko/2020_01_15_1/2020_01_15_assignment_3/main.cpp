#include <iostream>

int min(int x, int y) {
    return x<y ? x : y;
}

int min(int x, int y, int z) {
    return min(min(x, y), z);
}

int min(int x, int y, int z, int w) {
    return min(min(x, y), min(z, w));
}

int main() {

    if (min(12, 23) == 12) {
        std::cout << "Passed first test case" << std::endl;
    }
    else {
        std::cout << "Failed first test case" << std::endl;
    }

    if (min(12, 34, 23) == 12) {
        std::cout << "Passed second test case" << std::endl;
    }
    else {
        std::cout << "Failed second test case" << std::endl;
    }

    if (min(32, 64, 128, 4) == 4) {
        std::cout << "Passed third test case" << std::endl;
    }
    else {
        std::cout << "Failed third test case" << std::endl;
    }

    if (min(5, 5, 8, 13) == 5) {
        std::cout << "Passed fourth test case" << std::endl;
    }
    else {
        std::cout << "Failed fourth test case" << std::endl;
    }
    
    return 0;
}

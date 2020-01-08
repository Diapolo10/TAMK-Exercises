#include <cmath>
#include <iostream>

using std::sqrt;

const int LIMIT {1000};

bool isPrime(long long n) {
    bool result = true;
    
    // By definition, numbers smaller than 2 aren't primes
    if (n < 2) {
        result = false;
    }

    else if (n == 2) {} // 2 is the only even prime, so it makes sense to detect it early, though we only need to skip the loop

    else {
        // Thanks to mathemetics, we know we only need to check up to sqrt(n) to see if n is prime
        for (size_t i {2}; i <= sqrt(n); ++i) {
            if (!(n % i)) {
                result = false;
                break;
            }
        }
    }

    return result;
}

int main(void) {

    std::cout << "All primes between 0 and " << LIMIT << ":\n";
    long long counter {};

    for (size_t i{}; i <= LIMIT; ++i) {
        if (isPrime(i)) {
            ++counter;
            std::cout << i << "\n";
        }
    }

    std::cout << "\nTotal prime numbers found: " << counter << std::endl;
}

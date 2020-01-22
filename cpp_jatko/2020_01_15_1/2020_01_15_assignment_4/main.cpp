#include <array>
#include <cmath>
#include <iostream>

// #define DEBUG_MODE

const long long LIMIT{10000};

bool isPrime(long long n) {
    bool result{true};

    auto target = std::ceil(std::sqrtl(n));

    if (n % 2 && n > 2) {
        for (size_t i{ 3 }; i < target; i += 2) {
            if (!(n % i)) {
                result = false;
                break;
            }
        }
    }
    else {
        if (n != 2) {
            result = false;
        }
    }

    return result;
}

bool prime_all(long long n) {
    bool result{ true };

    if (n % 2 && n > 2) {
        for (size_t i{ 3 }; i < n; i += 2) {
            if (!(n % i)) {
                result = false;
                break;
}
        }
    }
    else {
        if (n != 2) {
            result = false;
        }
    }

    return result;
}

bool prime_half(long long n) {
    bool result{ true };

    if (n % 2 && n > 2) {
        for (size_t i{ 3 }; i < n/2; i += 2) {
            if (!(n % i)) {
                result = false;
                break;
            }
}
    }
    else {
        if (n != 2) {
            result = false;
        }
    }

    return result;
}

bool prime_square_root(long long n) {
    bool result{ true };

    auto target = std::ceil(std::sqrtl(n));

    if (n % 2 && n > 2) {
        for (size_t i{ 3 }; i <= target; i += 2) {
            if (!(n % i)) {
                result = false;
                break;
            }
}
    }
    else {
        if (n != 2) {
            result = false;
        }
    }

    return result;
}


// Compares multiple values to each other simultaneously
template <typename T>
bool all_equal(const T& t, const T& u) {
    return t == u;
}

template <typename T, typename... Others>
bool all_equal(const T& t, const T& u, Others const&... args) {
    return (t == u) && all_equal(u, args...);
}

int main() {
    #ifdef DEBUG_MODE
    std::array<unsigned long long, 20> test_cases{0, 1, 2, 3, 5, 7, 9, 11, 12, 13, 101, 10007, 1000000007, 1111235916285193, 6089, 60899, 608999, 6089999, 60899999, 608999999 };
    for (auto test_case : test_cases) {
        std::cout << test_case << " is" << (isPrime(test_case) ? "" : " not") << " a prime number.\n";
    }
    #endif

    // b)
    std::cout << "Primes from 1 to " << LIMIT << ":\n";

    long long prime_count{};
    for (size_t i{1}; i <= LIMIT; ++i) {
        if (isPrime(i)) {
            std::cout << i << "\n";
            ++prime_count;
        }
    }
    std::cout << "Primes found: " << prime_count << "\nPrime ratio: " << std::round((prime_count / (long double)LIMIT) * 1000) / 1000 << "%\n";


    // c)
    std::cout << "Testing all versions...\n\n";

    long long disagreements{};
    for (size_t i{ 1 }; i <= LIMIT; ++i) {
        if (all_equal(prime_all(i), prime_half(i), prime_square_root(i))) {}
        else {
            std::cout << "Disagreement on number " << i << "\n";
            ++disagreements;
        }
    }

    std::cout << "\nThe functions disagreed " << disagreements << " times.\n";

    return 0;
}
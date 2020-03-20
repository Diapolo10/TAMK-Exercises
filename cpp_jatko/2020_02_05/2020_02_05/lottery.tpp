#pragma once

#include <iostream>     // std::{cout, cerr, cin, ...}
#include <random>       // std::{mt19937_64, random_device, uniform_int_distribution}
#include <set>          // std::set
#include <stdexcept>    // std::invalid_argument

#include "utility.hpp"  // non_std::{...}

std::random_device rd;
std::mt19937_64 mt(rd());

namespace non_std {
    namespace random {

        /*
         * Generates a random integer number between [start, stop].
         * Supports all interger types.
         */
        template <typename T>
        T randnum(T start, T stop) {
            std::uniform_int_distribution<T> dist(start, stop);
            return dist(mt);
        }

        /*
         * Generates a random integer number between [0, stop].
         * Supports all integer types.
         */
        template <typename T>
        T randnum(T stop) {
            std::uniform_int_distribution<T> dist(0, stop);
            return dist(mt);
        }

        /*
         * Generates a vector of random instances of a given integer type
         * between [start, stop]. The number of generated numbers is determined by count.
         */
        template <typename T>
        std::vector<T> randrange(T start, T stop, size_t count) {
            std::vector<T> result{};
            while (result.size() < count) {
                result.push_back(randnum(start, stop));
            }
            return result;
        }


        /*
         * Returns a random value from a given iterable. Supports all indexable STL containers.
         */
        template <typename T>
        typename T::value_type choice(T& values) {
            return values.at(randnum(values.size()));
        }

        /*
         * Returns an iterable with a random sample of values from a given iterable, up to n values.
         * Supports all indexable STL containers. Will throw an error if n is larger than the iterable's last index.
         * 
         * Will generate a new container from scratch for small values, on large iterables and sample sizes the function shuffles and slices instead.
         */
        template <typename T>
        T sample(T& values, size_t n) {
            
            if (values.size() >= n) {
                throw std::invalid_argument("Cannot take a sample larger than sample size\n");
            }

            T result{};

            // For short iterables, generating a new one may be faster
            if ((values.size()/2 >= n) || n < 50) {

                T result{};

                std::set<size_t> used_indexes{};

                while(result.size() < n){
                    size_t idx{randnum(n)};
                    if (used_indexes.count(idx)) {
                        continue;
                    }
                    else {
                        result.push_back(values.at(idx));
                        used_indexes.insert(idx);
                    }
                }
            }

            // For long iterables, it's best to shuffle and return the first n items
            else {
                T shuffled{shuffle(values)};
                T result{shuffled.begin(), shuffled.begin()+n};
            }

            return result;
        }

        /*
         * Returns a shuffled copy of the given indexable iterable.
         * Implements the Fisher-Yates shuffle.
         */
        template <typename T>
        T shuffle(T values) {

            for (size_t idx{ values.size()-1 }; idx > 0; --idx) {
                size_t random_idx{randnum(idx)};

                auto temp{values[idx]};
                values[idx] = values[random_idx];
                values[random_idx] = temp;
            }

            return values;
        }
    }

    namespace lottery {

        /*
         * Generates n unique random lottery numbers up to max
         */
        std::vector<int> generate_lottery_row(int max, int n) {

            std::vector<int> nums(0, max + 1); // [0, 1, 2, ..., max]

            auto result{random::sample(nums, n)};
            std::sort(result.begin(), result.end());
            
            return result;
        }


        /*
         * Checks how many correct matches there are between the player guesses and the real
         * lottery numbers, and returns a number up to the number of numbers in a row.
         */
        int check_result(std::vector<int> player_guess, std::vector<int> correct_row) {
            int result{};

            // Even when sorted, the two vectors could be off-sync if compared with one iteration, hence why O(n^2) approach
            for (auto num : correct_row) {
                if (non_std::contains(player_guess, num)) {
                    ++result;
                }
            }

            return result;
        }
    }
}

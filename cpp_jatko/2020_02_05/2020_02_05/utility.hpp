// utility.hpp - contains declarations of various utility functions
// Target specification: C++17

/*
 * LICENSE - The MIT License
 * Copyright 2019, Lari Liuhamo @ TAMK
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 * LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

namespace non_std {

	// A utility function that splits std::string objects in half from the first
	// encountered instance of the given delimiter.
	//
	// Example:
	// auto foo = string_split("Number #{}: ", "{}");
	//
	// returns: std::vector<std::string> {"Number #", ": "}
	std::vector<std::string> string_split(std::string& s, std::string delimiter) {
		size_t pos_start{}, pos_end, delim_len = delimiter.length();
		std::string token;
		std::vector<std::string> res;

		while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
			token = s.substr(pos_start, pos_end - pos_start);
			pos_start = pos_end + delim_len;
			res.push_back(token);
		}

		res.push_back(s.substr(pos_start));
		return res;
	}

	template <typename T>
	std::string string_join(T values, std::string delimiter = ", ") {

		// TODO: Improve this to work with any type
		static_assert(std::is_same<T::value_type, std::string>::value);

		std::string res;
		res.reserve(sizeof(T::value_type));

		for (auto& value : values) {
			res.append(value);
			if (value != values.back()) {
				res.append(delimiter);
			}
		}

		return res;
	}

	template <typename T>
	bool contains(T iterable, typename T::value_type item) {
		for (auto value : iterable) {
			if (value == item) {
				return true;
			}
		}

		return false;
	}

	// Simple functions that take individual parameters
	// and return a result with them; eg. reusable lambdas
	namespace functools {

		// A function wrapper for the increment operator
		template <typename T>
		T inc(T num) {
			return ++num;
		}

		// A function wrapper for the decrement operator
		template <typename T>
		T dec(T num) {
			return --num;
		}

		// A function wrapper for addition
		template <typename T>
		T add(const T num1, const T num2) {
			return num1 + num2;
		}

		// A function wrapper for substraction
		template <typename T>
		T sub(const T num1, const T num2) {
			return num1 - num2;
		}

		// A function wrapper for multiplication
		template <typename T>
		T mul(const T num1, const T num2) {
			return num1 * num2;
		}

		// A function wrapper for division
		template <typename T>
		T div(const T num1, const T num2) {
			if (num2 != 0) {
				return num1 / num2;
			}
			throw "Cannot divide by zero";
		}

		// A function wrapper for modulus
		template <typename T>
		T mod(const T num1, const T num2) {
			return num1 % num2;
		}



	}

	// Functions that deal with iterables and either
	// return them or perform a logical operation on them
	namespace itertools {

		// A function that takes an iterable as input, then iterates through it
		// until its largest value is found. If the iterable contains strings,
		// this will be the string with the largest ASCII value.
		// 
		// Example:
		// std::vector<int> foo = {1, 2, 4, -7};
		// auto bar = max(foo);
		// 
		// returns: int{4}
		template <typename T>
		typename T::value_type max(const T& iterable) {
			/* Takes an iterable of type T, returns the highest value of type T::value_type */

			auto current_max = iterable[0];

			for (auto value : iterable) {
				if (value > current_max) {
					current_max = value;
				}
			}

			return current_max;
		}

		// A function that takes an iterable as input, then iterates through it
		// until its smallest value is found. If the iterable contains strings,
		// this will be the string with the smallest ASCII value.
		// 
		// Example:
		// std::vector<int> foo = {1, 2, 4, -7};
		// auto bar = min(foo);
		// 
		// returns: int{-7}
		template <typename T>
		typename T::value_type min(const T& iterable) {
			/* Takes an iterable of type T, returns the highest value of type T */

			auto current_min = iterable[0];

			for (auto value : iterable) {
				if (value < current_min) {
					current_min = value;
				}
			}

			return current_min;
		}

		// Maps a modifier and an iterable of type T, returns
		// a new instance of an iterable of type T with the modified results.
		// Should work similiarly to Python's map-function
		template <typename T>
		typename T fmap(typename T::value_type func(typename T::value_type), const T& iterable) {

			T result{};

			for (const auto& value : iterable) {
				result.insert(result.end(), func(value));
			}

			return result;
		}

	}

	// Functions that are mathematical in nature,
	// parameters can be numeric or iterables of numbers
	namespace math {

		// Takes an iterable of values of type T::value_type that can be added together.
		// Returns the sum of the contents of the iterable.
		//
		// Example:
		// std::vector<int> foo = {1, 2, 3, 4};
		// auto bar = sum(foo);
		// 
		// returns: int{10}
		template <typename T>
		typename T::value_type sum(const T& iterable) {
			/* Adds up the contents of any iterable type T, returns the sum of its contents
			 * as type T::value_type.
			 */
			typename T::value_type result = {};

			for (const auto& num : iterable) {
				result += num;
			}

			return result;
		}

	}

	// IO-related functions that usually either take
	// input from STDIN or write to STDOUT
	namespace io {

		// Print out any iterable
		// with all contents separated
		// by a space. A newline is appended
		// at the end, and the buffer is flushed.
		template <typename T>
		void print_iterable(const T& iterable) {
			for (auto val : iterable) {
				std::cout << val << (val != iterable.back() ? " " : "");
			}
			std::cout << std::endl;
		}

		template<typename T>
		T get_input(const std::string& prompt) {
			T input{};

			while (true) {
				std::cout << prompt;

				if (!(std::cin >> input)) {
					std::cerr << u8"Invalid input.\n\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}

				break;
			}

			// std::cin.clear();
			// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			return input;
		}

		std::string get_input_line(std::string& prompt) {
			std::vector<std::string> result{};
			std::string input{};

			while ((input = get_input<std::string>(prompt)).back() != '\n') {
				result.push_back(input);
			}

			return non_std::string_join(result, " ");
		}

		// Get input of type T from the user n times, using a formatted std::string prompt.
		// Returns a vector of the given input type.
		//
		// Example:
		// auto foo = get_n_input<int>(3, "Number #{}: ");
		//
		// >>> Number #1: 3
		// >>> Number #2: 7
		// >>> Number #3: 12
		// returns: std::vector<int> {3, 7, 12}
		template <typename T>
		std::vector<T> get_n_input(const long n, std::string& prompt) {
			/* Gets n inputs from the user; returns a std::vector of type T
			 *
			 * prompt is a formattable std::string, where '{}' is used as a
			 * placeholder for the current counter value.
			 */

			std::vector<T> result;
			T input;
			long num_counter = 1L;

			std::vector<std::string> split_prompt = string_split(prompt, (std::string)"{}");

			do {
				std::stringstream formatted_prompt;
				formatted_prompt << split_prompt.front() << num_counter++ << split_prompt.back();

				input = get_input<T>(formatted_prompt.str());
				result.push_back(input);

				// Empties stringstream
				formatted_prompt.clear();
				formatted_prompt.str(std::string());

			} while (num_counter <= n);

			return result;
		}

		template <typename T>
		std::vector<T> get_n_unique(std::string prompt, size_t n) {
			/* Gets n inputs from the user; returns a std::vector of type T
			 *
			 * prompt is a formattable std::string, where '{}' is used as a
			 * placeholder for the current counter value.
			 */

			std::vector<T> result;
			T input;
			size_t num_counter{};

			std::vector<std::string> split_prompt = non_std::string_split(prompt, "{}");

			do {
				std::stringstream formatted_prompt;
				formatted_prompt << split_prompt.front() << ++num_counter << split_prompt.back();

				input = get_input<T>(formatted_prompt.str());
				
				if (!non_std::contains(result, input)) {
				    
					result.push_back(input);
				
				    // Empties stringstream
				    formatted_prompt.clear();
				    formatted_prompt.str(std::string());
				}
				else {
					--num_counter;
				}

			} while (num_counter < n);

			return result;
		}

		// A Python-like print function, currently at prototype stage
		// [[deprecated("Unfinished and may not work correctly")]]
		void println(std::string text, std::ostream& file = std::cout, std::string sep = " ", std::string end = "\n") {
			file << text << end;
		}
		template <typename T, typename... Args> // [[deprecated("Unfinished and may not work correctly")]]
			void println(T text, Args... args, std::ostream& file = std::cout, std::string sep = " ", std::string end = "\n") {
			file << text << end;
		}

	}

}

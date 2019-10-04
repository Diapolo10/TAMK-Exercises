// utility.cpp - defines various utility functions
#include <iostream>
#include <string>
#include <vector>

#include "utility.h"
#include "pch.h"

namespace nonstd {
	
	template <typename T>
	void print_iterable(T iterable) {
		for (auto val : iterable) {
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}

	template <typename T>
	std::vector<T> get_n_input(long n, std::string prompt) {
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
			std::cout << split_prompt.front() << num_counter++ << split_prompt.back();
			std::cin >> input;

			result.push_back(input);

		} while (num_counter <= n);

		return result;
	}

	std::vector<std::string> string_split(std::string s, std::string delimiter) {
		size_t pos_start = 0, pos_end, delim_len = delimiter.length();
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
}
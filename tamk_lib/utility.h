// utility.h - contains declarations of various utility functions
#pragma once

#ifdef UTILITYLIB_EXPORTS
#define UTILITYLIB_API __declspec(dllexport)
#else
#define UTILITYLIB_API __declspec(dllimport)
#endif

#include <vector>
#include <string>

namespace nonstd {

	// Print out any iterable
	// with all contents separated
	// by a space. A newline is appended
	// at the end, and the buffer is flushed.
	template <typename T>
	void print_iterable(T iterable);


	// Get input of type T from the user n times, using a formatted std::string prompt.
	// Returns a vector of the given input type.
	//
	// Example:
	// auto foo = get_n_input<int>(5, "Number #{}: ");
	//
	// >>> Number #1: 3
	// >>> Number #2: 7
	// >>> Number #3: 12
	// returns: std::vector<int> {3, 7, 12}
	template <typename T>
	std::vector<T> get_n_input(long n, std::string prompt);

	// An utility function that splits std::string objects in half from the first
	// encountered instance of the given delimiter.
	//
	// Example:
	// auto foo = string_split("Number #{}: ", "{}");
	//
	// returns: std::vector<std::string> {"Number #", ": "}
	std::vector<std::string> string_split(std::string s, std::string delimiter);
}
#include <iostream>
#include <string>
#include <vector>
#include <locale>

using std::string;
using std::vector;

using namespace std::string_literals;

struct Word {
	string word;
	string answer;
};

vector<Word> get_input(vector<string> words) {
	
	vector<Word> result;
	
	for (auto word : words) {
		string answer;

		// Bad practice, I know, but the assignment stated I had to create this string
		// yet there was no word of needing to use it
		if (word == u8"katunumero"s) {
			continue;
		}

		// TODO: How can I store UTF-8 characters properly when they're not std::string literals?
		std::cout << u8"Syötä "s << word << ": "s;
		std::cin >> answer;

		result.push_back(Word{ word, answer });
	}

	return result;
}

int main(void) {

	// Here's hoping this counts, because I didn't feel like
	// defining a bunch of separate variables
	vector<string> words = {
	    u8"etunimi"s,
		u8"sukunimi"s,
		u8"osoite"s,
		u8"katunumero"s,
		u8"postinumero"s,
		u8"kunta"s
	};

	auto answers = get_input(words);

	std::cout << u8"\nOsoitteesi on: "s;
	for (auto word : answers) {
		std::cout << word.answer << u8" "s;
	}
	std::cout << std::endl;

	std::cout << u8"Sinun nimistäsi "s << (answers[0].answer < answers[1].answer ? answers[0].word : answers[1].word) << u8" on aakkosissa ensin.\n"s;

	return EXIT_SUCCESS;
}

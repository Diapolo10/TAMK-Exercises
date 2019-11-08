#include <iostream>
#include <string>
#include <windows.h>
#include "input.hpp"

using std::string;

int main() {
	bool running = true;
	string key;
	string key2;

	while (running) {
		key = getKeyboardInput();
		key2 = getKeyboardInput();
		if (key == key2) {
			std::cout << key << " was pressed" << std::endl;
		}
	}
}

#include <iostream>
#include <string>
#include <windows.h>
#include "input.hpp"
#include "game_state.hpp"

using std::string;

// I won't use classes because I'm not comfortable with the C++ ones yet,
// but technically this is pretty similiar as I'm moving a global state around.
// May not be best practice, but I'll only refactor it if I have the time as
// this is a 'big' project.

int main() {
	tetris::global::GameState state{ true };
	string key;

	while (state.running) {
		key = getKeyboardInput(state);
		if (key != "") {
			std::cout << key << " was pressed" << std::endl;
		}
	}
}

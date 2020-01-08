// Standard library
#include <iostream>
#include <string>

// MSVC extras
#include <windows.h>

// Own headers
#include "input.hpp"
#include "game_state.hpp"
#include "tetrominos.hpp"

using std::string;

// I won't use classes because I'm not comfortable with the C++ ones yet,
// but technically this is pretty similiar as I'm moving a 'global' state around.
// May not be best practice, but I'll only refactor it if I have the time as
// this is a 'big' project.

int main() {
    tetris::global::GameState state{ true };
    string key;
	int colour = 0;
	SetConsoleTitle("Tetris");

    while (state.running) {
        key = tetris::input::getKeyboardInput(state);
        if (key != "") {
            std::cout << ANSI_FOREGROUND_COLOURS[colour++] << key << " was pressed" << std::endl;
			if (colour == ANSI_FOREGROUND_COLOURS.size()) {
				colour = 0;
			}
        }
    }
}

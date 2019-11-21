#pragma once

#include <string>
#include <Windows.h>
#include "game_state.hpp"

using std::string;

string getKeyboardInput(tetris::global::GameState state) {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD NumInputs = 0;
    DWORD InputsRead = 0;
    string result {};

    INPUT_RECORD irInput;

    GetNumberOfConsoleInputEvents(hInput, &NumInputs);

    ReadConsoleInput(hInput, &irInput, 1, &InputsRead);

    auto event = irInput.Event.KeyEvent;

    if (event.bKeyDown) {
        // https://stackoverflow.com/questions/22675708/why-do-i-receive-each-keyboard-event-twice-when-using-readconsoleinput

        switch (event.wVirtualKeyCode)
        {
        case VK_ESCAPE:
            result = "Escape";
            break;

        case VK_LEFT:
            result = "Left";
            break;

        case VK_UP:
            result = "Up";
            break;

        case VK_RIGHT:
            result = "Right";
            break;

        case VK_DOWN:
            result = "Down";
            break;

        default:
            result = "Some other key";
            break;
        }
    }
    return result;
}
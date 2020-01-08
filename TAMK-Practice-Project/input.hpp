#pragma once

// Standard library
#include <stdexcept>
#include <string>
#include <unordered_map>

// MSVC extras
#include <Windows.h>

// Own headers
#include "game_state.hpp"

using std::string;

namespace tetris {
    namespace input {
        string getKeyboardInput(tetris::global::GameState state) {
            HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
            DWORD NumInputs = 0;
            DWORD InputsRead = 0;
            string result{};

            INPUT_RECORD irInput;

            GetNumberOfConsoleInputEvents(hInput, &NumInputs);

            ReadConsoleInput(hInput, &irInput, 1, &InputsRead);

            auto event = irInput.Event.KeyEvent;

            if (event.bKeyDown) {
                // https://stackoverflow.com/questions/22675708/why-do-i-receive-each-keyboard-event-twice-when-using-readconsoleinput

                /*switch (event.wVirtualKeyCode) {
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


                }*/
                try {
                    result = tetris::mapping::keyboard_keys.at(event.wVirtualKeyCode);
                }
                catch (std::out_of_range) {
                    result = "";
                }
            }
            return result;
        }
    }
    namespace mapping {
        static const std::unordered_map<int, std::string> keyboard_keys{
            {0x01, "Left mouse button"},
            {0x02, "Right mouse button"},
            {0x03, "Control - break processing"},
            {0x04, "Middle mouse button(three - button mouse)"},
            {0x05, "X1 mouse button"},
            {0x06, "X2 mouse button"},
            {0x08, "BACKSPACE key"},
            {0x09, "TAB key"},
            {0x0C, "CLEAR key"},
            {0x0D, "ENTER key"},
            {0x10, "SHIFT key"},
            {0x11, "CTRL key"},
            {0x12, "ALT key"},
            {0x13, "PAUSE key"},
            {0x14, "CAPS LOCK key"},
            {0x1B, "ESC key"},
            {0x20, "SPACEBAR"},
            {0x21, "PAGE UP key"},
            {0x22, "PAGE DOWN key"},
            {0x23, "END key"},
            {0x24, "HOME key"},
            {0x25, "LEFT ARROW key"},
            {0x26, "UP ARROW key"},
            {0x27, "RIGHT ARROW key"},
            {0x28, "DOWN ARROW key"},
            {0x29, "SELECT key"},
            {0x2A, "PRINT key"},
            {0x2B, "EXECUTE key"},
            {0x2C, "PRINT SCREEN key"},
            {0x2D, "INS key"},
            {0x2E, "DEL key"},
            {0x30, "0 key"},
            {0x31, "1 key"},
            {0x32, "2 key"},
            {0x33, "3 key"},
            {0x34, "4 key"},
            {0x35, "5 key"},
            {0x36, "6 key"},
            {0x37, "7 key"},
            {0x38, "8 key"},
            {0x39, "9 key"},
            {0x41, "A key"},
            {0x42, "B key"},
            {0x43, "C key"},
            {0x44, "D key"},
            {0x45, "E key"},
            {0x46, "F key"},
            {0x47, "G key"},
            {0x48, "H key"},
            {0x49, "I key"},
            {0x4A, "J key"},
            {0x4C, "L key"},
            {0x4D, "M key"},
            {0x4E, "N key"},
            {0x4F, "O key"},
            {0x50, "P key"},
            {0x51, "Q key"},
            {0x52, "R key"},
            {0x54, "T key"},
            {0x55, "U key"},
            {0x56, "V key"},
            {0x57, "W key"},
            {0x58, "X key"},
            {0x59, "Y key"},
            {0x5A, "Z key"},
            {0x5B, "Left Windows key(Natural keyboard)"},
            {0x5C, "Right Windows key(Natural keyboard)"},
            {0x5D, "Applications key(Natural keyboard)"},
            {0x5F, "Computer Sleep key"},
            {0x60, "Numeric keypad 0 key"},
            {0x61, "Numeric keypad 1 key"},
            {0x62, "Numeric keypad 2 key"},
            {0x63, "Numeric keypad 3 key"},
            {0x64, "Numeric keypad 4 key"},
            {0x65, "Numeric keypad 5 key"},
            {0x66, "Numeric keypad 6 key"},
            {0x67, "Numeric keypad 7 key"},
            {0x68, "Numeric keypad 8 key"},
            {0x69, "Numeric keypad 9 key"},
            {0x6A, "Multiply key"},
            {0x6B, "Add key"},
            {0x6C, "Separator key"},
            {0x6D, "Subtract key"},
            {0x6E, "Decimal key"},
            {0x6F, "Divide key"},
            {0x70, "F1 key"},
            {0x71, "F2 key"},
            {0x72, "F3 key"},
            {0x73, "F4 key"},
            {0x74, "F5 key"},
            {0x75, "F6 key"},
            {0x76, "F7 key"},
            {0x77, "F8 key"},
            {0x78, "F9 key"},
            {0x79, "F10 key"},
            {0x7A, "F11 key"},
            {0x7B, "F12 key"},
            {0x7C, "F13 key"},
            {0x7D, "F14 key"},
            {0x7E, "F15 key"},
            {0x7F, "F16 key"},
            {0x80, "F17 key"},
            {0x81, "F18 key"},
            {0x82, "F19 key"},
            {0x83, "F20 key"},
            {0x84, "F21 key"},
            {0x85, "F22 key"},
            {0x86, "F23 key"},
            {0x87, "F24 key"},
            {0x90, "NUM LOCK key"},
            {0x91, "SCROLL LOCK key"},
            {0x92 - 96, "OEM specific"},
            {0xA0, "Left SHIFT key"},
            {0xA1, "Right SHIFT key"},
            {0xA2, "Left CONTROL key"},
            {0xA3, "Right CONTROL key"},
            {0xA4, "Left MENU key"},
            {0xA5, "Right MENU key"},
            {0xA6, "Browser Back key"},
            {0xA7, "Browser Forward key"},
            {0xA8, "Browser Refresh key"},
            {0xA9, "Browser Stop key"},
            {0xAA, "Browser Search key"},
            {0xAB, "Browser Favorites key"},
            {0xAC, "Browser Start and Home key"},
            {0xAD, "Volume Mute key"},
            {0xAE, "Volume Down key"},
            {0xAF, "Volume Up key"},
            {0xB0, "Next Track key"},
            {0xB1, "Previous Track key"},
            {0xB2, "Stop Media key"},
            {0xB3, "Play / Pause Media key"},
            {0xB4, "Start Mail key"},
            {0xB5, "Select Media key"},
            {0xBB, "+"},
            {0xBC, ","},
            {0xBD, "-"},
            {0xBE, "."}
        };
    }
}

#pragma once

#include <array>
#include <string>

using std::array;
using std::string;

// https://en.wikipedia.org/wiki/Geometric_Shapes

namespace tetris {
    namespace config {

        const struct CHARS {
            char tetris_block;
            char square_left;
            char square_right;
            char square_up;
            char square_down;
        };

        static const CHARS CHARS_ASCII{ 0x2563, 0x25E7, 0x25E8, 0x25E9, 0x25EA };

        const string T_BLOCK{ CHARS_ASCII.tetris_block };
        const string SQUARE_LEFT_BLOCK{ CHARS_ASCII.square_left };
        const string SQUARE_RIGHT_BLOCK{ CHARS_ASCII.square_right };
        const string SQUARE_UP_BLOCK{ CHARS_ASCII.square_up };
        const string SQUARE_DOWN_BLOCK{ CHARS_ASCII.square_down };

		array<string, 16> ANSI_COLOURS{
			// Dim colours
			u8"\x1b[30m", // black
			u8"\x1b[31m", // red
			u8"\x1b[32m", // green
			u8"\x1b[33m", // yellow
			u8"\x1b[34m", // blue
			u8"\x1b[35m", // magenta
			u8"\x1b[36m", // cyan
			u8"\x1b[37m", // white

			// Bright colours
			u8"\x1b[90m", // black
			u8"\x1b[91m", // red
			u8"\x1b[92m", // green
			u8"[93m", // yellow
			u8"\x1b[94m", // blue
			u8"\x1b[95m", // magenta
			u8"\x1b[96m", // cyan
			u8"\x1b[97m", // white
		};
    }
}

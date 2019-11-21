#pragma once

#include <string>

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
    }
}

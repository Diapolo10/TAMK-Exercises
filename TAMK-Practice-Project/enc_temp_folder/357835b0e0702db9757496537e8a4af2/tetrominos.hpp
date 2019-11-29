#pragma once

#include <string>

#include "constants.hpp"

using std::string;
using namespace std::string_literals;

using tetris::config::ANSI_COLOURS;

namespace tetris {
	namespace game_object {

		struct Block {
			string symbol;
			string colour;
		};
	}
}
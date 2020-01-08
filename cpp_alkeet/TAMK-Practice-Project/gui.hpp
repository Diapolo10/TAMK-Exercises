#pragma once

#include <string>
#include <vector>
#include <windows.h>

#include "constants.hpp"

using std::string;
using namespace std::string_literals;

bool clear_screen(HANDLE hConsole) {
	COORD coordScreen { 0, 0 };    // home for the cursor 
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	// Get the number of character cells in the current buffer. 
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return false;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.

	if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer 
		(TCHAR)' ',     // Character to write to the buffer
		dwConSize,       // Number of cells to write 
		coordScreen,     // Coordinates of first cell 
		&cCharsWritten))// Receive number of characters written
	{
		return false;
	}

	// Get the current text attribute.

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return false;
	}

	// Set the buffer's attributes accordingly.

	if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer 
		csbi.wAttributes, // Character attributes to use
		dwConSize,        // Number of cells to set attribute 
		coordScreen,      // Coordinates of first cell 
		&cCharsWritten)) // Receive number of characters written
	{
		return false;
	}

	// Put the cursor at its home coordinates.

	SetConsoleCursorPosition(hConsole, coordScreen);

	return true;
}

bool write_ui(char str[]) {
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	LPSTR output = str;
	DWORD cWritten;

	if (!clear_screen(hOutput)) {
		return false;
	}
	
	if (!WriteConsole(
		hOutput,
		output,
		lstrlen(output),
		&cWritten,
		NULL
	)) {
		return false;
	}

	return true;
}
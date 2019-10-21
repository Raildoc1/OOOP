#include <string>
#include <iostream>
#include <Windows.h>

void ColorError(std::string text) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12); // Red Color
	std::cout << "[Error]:";
	SetConsoleTextAttribute(hConsole, 15); // White Color
	std::cout << text << std::endl;
}
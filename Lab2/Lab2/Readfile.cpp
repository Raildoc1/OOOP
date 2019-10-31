#include "Readfile.h"

std::string Readfile::execute(std::string & text) {
	std::ifstream fin(inputFile);
	if (!fin) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12); // Red Color
		std::cout << "[Error]:";
		SetConsoleTextAttribute(hConsole, 15); // White Color
		std::cout << " Can't open file " << inputFile << "!" << std::endl;
		exit(0);
	}
	std::string output((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
	std::cout << output << std::endl;
	return output;
}

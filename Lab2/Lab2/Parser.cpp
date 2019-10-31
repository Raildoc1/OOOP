#include "Parser.h"

#include <fstream>

void Parser::readCommands(std::string &fileName, Worker** commands, int* executeOrder) {

	std::ifstream fin(fileName);

	if (!fin) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12); // Red Color
		std::cout << "[Error]:";
		SetConsoleTextAttribute(hConsole, 15); // White Color
		std::cout << " Can't open file " << fileName << "!" << std::endl;
		exit(0);
	}

	std::string buffer;
	std::getline(fin, buffer);

	if (buffer != "desc") {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12); // Red Color
		std::cout << "[Error]:";
		SetConsoleTextAttribute(hConsole, 15); // White Color
		std::cout << " Invalid input file beginning. \"desc\" is missing! " << std::endl;
		exit(0);
	}

	while (buffer != "csed") {

		std::getline(fin, buffer);

		if (fin.eof()) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 12); // Red Color
			std::cout << "[Error]:";
			SetConsoleTextAttribute(hConsole, 15); // White Color
			std::cout << " Invalid input file beginning. \"csed\" is missing! " << std::endl;
			exit(0);
		}
	}

	fin.close();

}

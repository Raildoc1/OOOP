#include "dump.h"

std::string Dump::execute(std::string & text) {
	std::ofstream fout(text);
	if (!fout) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12); // Red Color
		std::cout << "[Error]:";
		SetConsoleTextAttribute(hConsole, 15); // White Color
		std::cout << " Can't open file " << outputFile << "!" << std::endl;
		exit(0);
	}

	fout << text;

	fout.close();

	return text;
}

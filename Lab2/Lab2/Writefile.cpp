#include "Writefile.h"

std::string Writefile::execute(std::string text) {
	std::ofstream fout(outputFile);
	if (!fout) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12); // Red Color
		std::cout << "[Error]:";
		SetConsoleTextAttribute(hConsole, 15); // White Color
		std::cout << " Can't open file " << outputFile << "!" << std::endl;
		exit(0);
	}

	fout << text;

	std::string result = "";
	return result;
}

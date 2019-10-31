#include "Writefile.h"
#include <iostream>

std::string Writefile::execute(std::string & text) {
	std::ofstream fout(outputFile);
	if (!fout) {
		//colorMessages::RedError(" Can't open file " + outputFile + "!");
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

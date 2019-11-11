#include "Executor.h"

#include "ColorMessages.h"

int main(int argc, char* argv[]) {
	try {
		if (argc < 2) throw std::string("input file expected!Correct input is \"Worker.exe input.txt\".");
	}
	catch (std::string e) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12); // Red Color
		std::cout << "[Error]: ";
		SetConsoleTextAttribute(hConsole, 15); // White Color
		std::cout << " " << e << std::endl;
		exit(0);
	}

	std::string iParam("");
	std::string oParam("");

	if (argc == 4) {
		if (std::string(argv[2]) == "-i") iParam = std::string(argv[3]);
		else if (std::string(argv[2]) == "-o") oParam = std::string(argv[3]);
	}

	if (argc == 6) {
		if (std::string(argv[2]) == "-i") iParam = std::string(argv[3]);
		else if (std::string(argv[2]) == "-o") oParam = std::string(argv[3]);
		if (std::string(argv[4]) == "-i") iParam = std::string(argv[5]);
		else if (std::string(argv[4]) == "-o") oParam = std::string(argv[5]);
	}

	if(iParam != "" || oParam != "") Executor::GetInstance().ExecuteWorkFlow(std::string(argv[1]), iParam, oParam);
	else Executor::GetInstance().ExecuteWorkFlow(std::string(argv[1]));

	return 0;
}
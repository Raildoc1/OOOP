#include "Executor.h"

void Executor::ExecuteWorkFlow(std::string fileName) {

	// Parse

	Parser parser;

	parser.readCommands(fileName, commands, executeOrder);

	// Execute

	for (int x : executeOrder) {
		if (commands[x] == nullptr) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 12); // Red Color
			std::cout << "[Error]:   ";
			SetConsoleTextAttribute(hConsole, 15); // White Color
			std::cout << "nullptr set as an instance of a command!" << std::endl;
			break;
		}
		buffer = commands[x]->execute(buffer);
	}

	// Clean

	for (auto x : commands) {
		delete x;
	}
}

void Executor::ExecuteWorkFlow(std::string fileName, std::string in, std::string out) {

	// Parse

	Parser parser;

	parser.readCommands(fileName, commands, executeOrder);

	// Execute

	if (in != "") buffer = Readfile(in).execute(buffer);

	for (int x : executeOrder) {
		if (commands[x] == nullptr) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 12); // Red Color
			std::cout << "[Error]:   ";
			SetConsoleTextAttribute(hConsole, 15); // White Color
			std::cout << "nullptr set as an instance of a command!" << std::endl;
			break;
		}
		buffer = commands[x]->execute(buffer);
	}

	if (out != "") buffer = Writefile(out).execute(buffer);

	// Clean

	for (auto x : commands) {
		delete x;
	}
}

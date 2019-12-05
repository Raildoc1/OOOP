#include "Executor.h"


void Executor::ExecuteWorkFlow(std::string fileName, ICommand* in, ICommand* out) {

	// Parse

	Parser parser;

	try {
		parser.readCommands(fileName, commands, executeOrder);
	}
	catch (std::string e) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12); // Red Color
		std::cout << "[Error]: ";
		SetConsoleTextAttribute(hConsole, 15); // White Color
		std::cout << " " << e << std::endl;
		exit(0);
	}

	// Execute

	if (in != nullptr) buffer = in->execute(buffer);

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

	if (out != nullptr) buffer = out->execute(buffer);

	// Clean

	for (auto x : commands) {
		delete x;
	}
}

/*void Executor::ExecuteWorkFlow1(std::string fileName) {

	// Parse

	Parser parser;

	try {
		parser.readCommands(fileName, commands, executeOrder);
	} catch (std::string e) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12); // Red Color
		std::cout << "[Error]: ";
		SetConsoleTextAttribute(hConsole, 15); // White Color
		std::cout << " " << e << std::endl;
		exit(0);
	}

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

	try {
		parser.readCommands(fileName, commands, executeOrder);
	} catch (std::string e) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12); // Red Color
		std::cout << "[Error]: ";
		SetConsoleTextAttribute(hConsole, 15); // White Color
		std::cout << " " << e << std::endl;
		exit(0);
	}

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
}*/


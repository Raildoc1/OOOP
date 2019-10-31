#include "Parser.h"

#include <fstream>

void Parser::readCommands(std::string &fileName, std::vector<Worker*>& commands, std::vector<int> & executeOrder) {

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

	std::getline(fin, buffer);

	while (buffer != "csed") {

		std::string sIndex = buffer.substr(0, buffer.find(" = "));
		std::string sCommand = buffer;

		sCommand.erase(0, 3 + sCommand.find(" = "));

		int index = std::atoi(sIndex.c_str());

		if (commands.size() <= index) commands.resize(index + 1);

		std::string key = sCommand.substr(0, sCommand.find(" "));
		std::string parametrs = sCommand.erase(0, 1 + sCommand.find(" "));

		commands[index] = WorkerFactory::GetInstance().Create(key, parametrs);

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

	{

		std::getline(fin, buffer);

		int commandIndex;

		while (buffer.find("->") != std::string::npos) {
			commandIndex = atoi(buffer.c_str());
			executeOrder.push_back(commandIndex);
			buffer.erase(0, 2 + buffer.find("->"));
		}

		commandIndex = atoi(buffer.c_str());
		executeOrder.push_back(commandIndex);
	}

	fin.close();

}

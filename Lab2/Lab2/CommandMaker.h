#pragma once

#include "ICommandMaker.h"
#include "CommandFactory.h"

template <typename T>
class CommandMaker : public ICommandMaker {
public:

	CommandMaker(const std::string& key) {
		try {
			CommandFactory::Instance().RegisterMaker(key, this);
		}
		catch (std::string e) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 12); // Red Color
			std::cout << "[Error]:";
			SetConsoleTextAttribute(hConsole, 15); // White Color
			std::cout << " " << e << std::endl;
			exit(0);
		}
	}

	T* Create(std::string parametrs) const {
		return new T(parametrs);
	}
};
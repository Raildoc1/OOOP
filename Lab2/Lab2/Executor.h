#pragma once

#include <string>
#include "Parser.h"

class Executor
{
private:
	Executor() {}
	Executor(const Executor&);
	Executor& operator = ( Executor&);

	std::vector<ICommand*> commands;
	std::vector<int> executeOrder;

	std::string buffer = "";
public:
	static Executor& GetInstance() {
		static Executor instance;
		return instance;
	}

	//void ExecuteWorkFlow(std::string fileName);
	//void ExecuteWorkFlow(std::string fileName, std::string in, std::string out);
	void ExecuteWorkFlow(std::string fileName, ICommand* in = nullptr, ICommand* out = nullptr);

};


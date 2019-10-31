#pragma once

#include <string>
#include <list>

#include "Parser.h"

class Executor
{
private:
	Executor() {}
	Executor(const Executor&);
	Executor& operator = ( Executor&);

	Worker** commands;
	int * executeOrder;

public:
	static Executor& GetInstance() {
		static Executor instance;
		return instance;
	}

	void ExecuteWorkFlow(std::string);

};


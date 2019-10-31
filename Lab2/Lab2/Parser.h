#pragma once

#include "WorkerFactory.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>

class Parser {

private:
public:
	Parser() {}
	~Parser() {}
	void readCommands(std::string& fileName, std::vector<Worker*>& commands, std::vector<int> & executeOrder);
};


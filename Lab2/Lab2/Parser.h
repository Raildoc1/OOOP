#pragma once

#include "CommandFactory.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>

class Parser {

private:
public:
	Parser() {}
	~Parser() {}
	void readCommands(std::string& fileName, std::vector<ICommand*>& commands, std::vector<int> & executeOrder);
};


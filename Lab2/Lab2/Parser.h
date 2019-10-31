#pragma once

#include "Readfile.h"
#include "Writefile.h"
#include "Grep.h"
#include "Sort.h"
#include "Dump.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>

class Parser {

private:
	std::map <int, Worker*> commands;
public:
	Parser() {}
	~Parser() {}
	void readCommands(std::string& fileName, std::vector<Worker*> * commands, std::vector<int> * executeOrder);

};


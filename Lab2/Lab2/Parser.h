#pragma once

#include "Readfile.h"
#include "Writefile.h"
#include "Grep.h"
#include "Sort.h"
#include "Dump.h"

#include<string>
#include<map>

class Parser {

private:
	std::map <int, Worker*> commands;
public:
	Parser() {}
	~Parser() {}
	void readCommands(std::string &fileName);

};


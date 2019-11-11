#pragma once

#include <string>
#include <map>

#include "ICommandMaker.h"

#include "Writefile.h"
#include "Readfile.h"
#include "Replace.h"
#include "Grep.h"
#include "Sort.h"
#include "Dump.h"

class CommandFactory {
private:
	std::map<std::string, ICommandMaker*> _makers;

public:
	static CommandFactory& Instance();

	void RegisterMaker(const std::string& key, ICommandMaker* maker);
	ICommand* CreateCommand(const std::string& key, const std::string& parametrs);
};
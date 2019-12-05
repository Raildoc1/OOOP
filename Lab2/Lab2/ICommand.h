#pragma once

#include <list>
#include <string>

#include <Windows.h>

class ICommand {
public:
	virtual std::string execute(std::string & text) = 0;
};


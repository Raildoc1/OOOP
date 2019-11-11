#pragma once

#include <list>
#include <string>

#include <Windows.h>

#include "ColorMessages.h"

class ICommand {
public:
	virtual std::string execute(std::string & text) = 0;
};


#pragma once

#include <list>
#include <string>

#include <Windows.h>

#include "ColorMessages.h"

class Worker {
protected:

	//std::list<std::string> * parametrs;

	//std::string input;

public:

	virtual std::string execute(std::string text) = 0;
};


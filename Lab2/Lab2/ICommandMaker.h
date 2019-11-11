#pragma once

#include <string>

#include "ICommand.h"

class ICommandMaker {
public:
	virtual ICommand* Create(std::string parametrs) const = 0;
};


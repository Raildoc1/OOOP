#pragma once

#include "ICommand.h"

#include <iostream>
#include <fstream>

class Sort : public ICommand {

private:
	std::string word;
public:

	Sort() {}
	Sort(std::string args) {}

	std::string execute(std::string & text) override;
};
#pragma once

#include "ICommand.h"

#include <iostream>
#include <fstream>

class Dump : public ICommand {

private:
	std::string outputFile;
public:

	Dump(std::string outputFile) {
		this->outputFile = outputFile;
	}

	std::string execute(std::string & text) override;

};
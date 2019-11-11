#pragma once

#include "ICommand.h"

#include <fstream>

class Writefile : public ICommand {

private:
	std::string outputFile;
public:
	Writefile(std::string outputFile) {
		this->outputFile = outputFile;
	}

	std::string execute(std::string & text) override;

};


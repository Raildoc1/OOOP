#pragma once

#include "Worker.h"

#include <fstream>

class Writefile : public Worker {

private:
	std::string outputFile;
public:
	Writefile(std::string outputFile) {
		this->outputFile = outputFile;
	}

	std::string execute(std::string & text) override;

};


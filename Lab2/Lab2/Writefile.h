#pragma once

#include "Worker.h"

#include <iostream>
#include <fstream>

class Writefile : public Worker {

private:
	std::string outputFile;
public:
	Writefile(unsigned id, std::string outputFile) {
		this->outputFile = outputFile;
	}

	std::string execute(std::string text) override;

};


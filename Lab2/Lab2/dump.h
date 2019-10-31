#pragma once

#include "Worker.h"

#include <iostream>
#include <fstream>

class Dump : public Worker {

private:
	std::string outputFile;
public:

	Dump(std::string outputFile) {
		this->outputFile = outputFile;
	}

	std::string execute(std::string text) override;

};
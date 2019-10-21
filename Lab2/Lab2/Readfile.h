#pragma once

#include "Worker.h"

#include <iostream>
#include <fstream>

class Readfile : public Worker {

private:
	std::string inputFile;
public:
	Readfile(unsigned id, std::string inputFile){
		this->inputFile = inputFile;
	}

	std::string execute(std::string text) override;

};


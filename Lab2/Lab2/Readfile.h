#pragma once

#include "ICommand.h"

#include <iostream>
#include <fstream>

class Readfile : public ICommand {

private:
	std::string inputFile;
public:
	Readfile(std::string inputFile){
		this->inputFile = inputFile;
	}

	std::string execute(std::string & text) override;

};


#pragma once

#include "ICommand.h"

#include <iostream>
#include <fstream>

class Grep : public ICommand {

private:
	std::string word;
public:
	Grep(std::string word) {
		this->word = word;
	}

	std::string execute(std::string & text) override;

};
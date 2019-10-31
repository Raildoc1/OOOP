#pragma once

#include "Worker.h"

#include <iostream>
#include <fstream>

class Grep : public Worker {

private:
	std::string word;
public:
	Grep(std::string word) {
		this->word = word;
	}

	std::string execute(std::string text) override;

};
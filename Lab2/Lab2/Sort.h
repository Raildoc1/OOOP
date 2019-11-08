#pragma once

#include "Worker.h"

#include <iostream>
#include <fstream>

class Sort : public Worker {

private:
	std::string word;
public:

	std::string execute(std::string & text) override;
};
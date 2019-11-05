#pragma once

#include "Worker.h"

#include <iostream>
#include <fstream>

class Replace : public Worker {

private:
	std::string word1;
	std::string word2;
public:

	Replace(std::string args) {
		word1 = args.substr(0, args.find(" "));
		word2 = args.erase(0, 1 + args.find(" "));
	}

	std::string execute(std::string& text) override;

};
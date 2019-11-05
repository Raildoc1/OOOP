#include "grep.h"

std::string Grep::execute(std::string & text) {
	
	std::string temp = "";
	std::string result = "";

	for (unsigned i = 0; i < text.length(); i++) {
		if (text[i] == '\n') {
			if (temp.find(word) != std::string::npos) result = result + temp + "\n";
			temp = "";
		}
		else {
			temp += text[i];
		}
	}

	return result;
}
#include "grep.h"

bool hasWord(std::string& text, std::string& word) {
	std::string temp = "";

	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') {
			if (temp == word) return true;
			temp = "";
		}
		else {
			temp += text[i];
		}
	}

	return false;
}

std::string Grep::execute(std::string text) {
	std::string temp = "";

	std::list<std::string> lines;
	std::list<std::string>::iterator it = lines.end();

	for (unsigned i = 0; i < text.length(); i++) {
		if (text[i] == '\n') {
			if (hasWord(temp, word)) {
				it = lines.end();
				lines.insert(it, temp);
			}
			temp = "";
		}
		else {
			temp += text[i];
		}
	}

	std::string result = *lines.begin();

	for (it = lines.begin()++; it != lines.end(); it++) {
		result += "\n";
		result += *it;
	}

	return result;
}
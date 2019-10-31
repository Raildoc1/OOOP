#include "Sort.h"

bool compareStrings(const std::string &s1, const std::string &s2) {
	int maxLen = (s1.length() > s2.length()) ? s2.length() : s1.length();
	for (int i = 0; i < maxLen; i++) {
		if (s1[i] != s2[i]) return (s1[i] < s2[i]);
	}
	return s1.length() < s2.length();
}

std::string Sort::execute(std::string & text) {
	std::string temp = "";

	std::list<std::string> lines;
	std::list<std::string>::iterator it = lines.end();

	for (unsigned i = 0; i < text.length(); i++) {
		if (text[i] == '\n') {
			it = lines.end();
			lines.insert(it, temp);
			temp = "";
		}
		else {
			temp += text[i];
		}
	}

	lines.sort(compareStrings);

	std::string result = *lines.begin();

	for (it = ++lines.begin(); it != lines.end(); it++) {
		result += "\n";
		result += *it;
	}

	return result;
}

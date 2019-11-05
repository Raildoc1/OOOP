#include "Replace.h"

std::string Replace::execute(std::string& text) {

	size_t pos = text.find(word1);

	while (pos != std::string::npos) {
		text.replace(pos, word1.length(), word2);
		pos = text.find(word1);
	}

	return text;
}

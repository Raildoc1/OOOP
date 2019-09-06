#include "WordFreq.h"
#include <iostream>

namespace WordCounter {
	WordFreq::WordFreq(string word, int64_t freq) : word(word), freq(freq) {}
	WordFreq::~WordFreq() {}

	void WordFreq::IncFreq() {
		WordFreq::IncFreq(1);
	}

	void WordFreq::IncFreq(int64_t n) { 
		if (n <= INT64_MAX - freq) {
			freq += n;
		} else
		cerr << word << " freq overflow!" << endl;
	}
}

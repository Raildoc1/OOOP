#pragma once

#include<string>


namespace WordCounter {
	using namespace std;

	class WordFreq {
	public:
		WordFreq(string word, int64_t freq);
		~WordFreq();

		void IncFreq();
		void IncFreq(int64_t);

		string GetWord() { return word; }
		int64_t GetFreq() { return freq; }
	private:
		string word;
		int64_t freq;
	};
}


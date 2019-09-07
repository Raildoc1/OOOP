#pragma once

#include<string>
#include<map>
#include <set>
#include <functional>
#include <fstream>


namespace WordCounter {

	using namespace std;

	typedef function<bool(pair < string, pair<int64_t, float>>, pair<string, pair<int64_t, float>>)> Comparator;

	class WordsParser {
	private:
		int64_t WordsAmount = 0;

		void UpdateFreq();

		map<string, pair<int64_t, float>> *Words;
	public:

		WordsParser();
		~WordsParser();

		void AddWord(string word);
		void AddWord(string word, int64_t amount);

		void AddLine(string line);

		set <pair<string, pair<int64_t, float>>, Comparator> MapToSortedSet();

		void SetToCSV(set <pair<string, pair<int64_t, float>>, Comparator>, string);
	};
}


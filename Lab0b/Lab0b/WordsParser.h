#pragma once

#include<string>
#include<map>
#include <set>
#include <functional>
#include <fstream>


namespace WordCounter {

	using namespace std;

	typedef pair <string, pair<int64_t, float>> TableRow; // Table row contains WORD AMOUNT FREQ
	typedef function<bool(TableRow, TableRow)> Comparator; // Function to sort rows

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

		set <TableRow, Comparator> MapToSortedSet();

		void SetToCSV(set <TableRow, Comparator>, string);
	};
}


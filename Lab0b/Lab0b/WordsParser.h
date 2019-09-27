#pragma once

#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


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

		void AddLine(string line);

		vector<TableRow> MapToSortedVector();

		void VectorToCSV(vector<TableRow> set, string file);
	};
}


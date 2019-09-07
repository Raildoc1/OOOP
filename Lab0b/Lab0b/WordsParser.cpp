#include "WordsParser.h"
#include <iostream>

namespace WordCounter {
	
	WordsParser::WordsParser() {
		Words = new map<string, pair<int64_t, float>>();
	}

	WordsParser::~WordsParser() {
		delete Words;
	}

	void WordsParser::AddWord(string word) {

		WordsAmount++;

		map<string, pair<int64_t, float>>::iterator it = Words->find(word);

		if (it != Words->end()) {
			it->second.first++;
		} else {
			Words->insert(it, TableRow(word, pair<int64_t, float>(1, 0)));
		}

		UpdateFreq();
		
	}

	void WordsParser::AddWord(string word, int64_t amount) {

		WordsAmount += amount;

		map<string, pair<int64_t, float>>::iterator it = Words->find(word);

		if (it != Words->end()) {
			it->second.first += amount;
		} else {
			Words->insert(it, TableRow(word, pair<int64_t, float>(amount, 0)));
		}

		UpdateFreq();
	}

	void WordsParser::AddLine(string line) {

		string word = "";

		for (auto x : line) {
			if (x == ' ' || x == '\n') {
				AddWord(word);
				word = "";
			} else {
				word += x;
			}
		}

		if(word != "") AddWord(word);
	}

	set<TableRow, Comparator> WordsParser::MapToSortedSet() {
		Comparator compFunctor =
			[](TableRow elem1, TableRow elem2) {
			if (elem2.second.second == elem1.second.second) return elem2.first[0] > elem1.first[0];
			return elem2.second.second < elem1.second.second;
		};
		set <TableRow, Comparator> WordsSet(Words->begin(), Words->end(), compFunctor);
		return WordsSet;
	}

	void WordsParser::SetToCSV(set <TableRow, Comparator> set, string file) {
		ofstream output(file);

		if (!output) {
			cerr << "Can't open file " << file << endl;
			return;
		}

		for (auto element : set) {
			output << element.first << ", " << element.second.first << ", " << element.second.second << "\n";
		}
	}



	void WordsParser::UpdateFreq() {
		for (auto it = Words->begin(); it != Words->end(); ++it) {
			it->second.second = (float)it->second.first / (float)WordsAmount;
		}
	}

}

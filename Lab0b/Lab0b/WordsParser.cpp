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
			Words->insert(it, pair<string, pair<int64_t, float>>(word, pair<int64_t, float>(1, 0)));
		}

		UpdateFreq();

		/*
		for (auto it = Words->begin(); it != Words->end(); ++it) {
			cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
		}
		cout << "\n";
		*/
	}

	void WordsParser::AddWord(string word, int64_t amount) {

		WordsAmount += amount;

		map<string, pair<int64_t, float>>::iterator it = Words->find(word);

		if (it != Words->end()) {
			it->second.first += amount;
		} else {
			Words->insert(it, pair<string, pair<int64_t, float>>(word, pair<int64_t, float>(amount, 0)));
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

	set<pair<string, pair<int64_t, float>>, Comparator> WordsParser::MapToSortedSet() {
		Comparator compFunctor =
			[](pair<string, pair<int64_t, float>> elem1, pair<string, pair<int64_t, float>> elem2) {
			if (elem2.second.second == elem1.second.second) return elem2.first[0] > elem1.first[0];
			return elem2.second.second < elem1.second.second;
		};
		set <pair<string, pair<int64_t, float>>, Comparator> WordsSet(Words->begin(), Words->end(), compFunctor);
		return WordsSet;
	}

	void WordsParser::SetToCSV(set <pair<string, pair<int64_t, float>>, Comparator> set, string file) {
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

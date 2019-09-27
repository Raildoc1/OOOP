#include "WordsParser.h"

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
	}

	void WordsParser::AddLine(string line) {

		string word = "";

		for (auto x : line) {
			if (!((x <= 'Z' && x >= 'A') || (x <= 'z' && x >= 'a') || (x <= '9' && x >= '0'))) {
				AddWord(word);
				word = "";
			} else {
				word += x;
			}
		}

		if(word != "") AddWord(word);
	}

	std::vector<TableRow> WordsParser::MapToSortedVector() {

		UpdateFreq();

		Comparator compFunctor = [](TableRow const & elem1, TableRow const & elem2) {
			if (elem2.second.second == elem1.second.second) return elem2.first[0] > elem1.first[0];
			return elem2.second.second < elem1.second.second;
		};

		vector <TableRow> WordsVector(Words->begin(), Words->end());

		return WordsVector;
	}

	void WordsParser::VectorToCSV(vector<TableRow> set, string file) {
		ofstream output(file);

		if (!output) {
			cerr << "Can't open file " << file << endl;
			return;
		}

		for (auto element : set) {
			output << element.first << ", " << element.second.first << ", " << element.second.second << "\n";
		}

		output.close();
	}

	void WordsParser::UpdateFreq() {
		for (auto it = Words->begin(); it != Words->end(); ++it) {
			it->second.second = (float)it->second.first / (float)WordsAmount;
		}
	}

}

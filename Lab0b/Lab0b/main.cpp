#include <iostream>
#include "WordsParser.h"

using namespace std;
using namespace WordCounter;

int main(int argc, char **argv) {

	#pragma region CheckInput

	if (argc < 3) {
		cerr << "Not enought arguments!" << endl;
		cerr << "Right function call is \"word_count.exe input.txt output.csv\"" << endl;
		return 0;
	}

	ifstream fin;

	fin.open(argv[1]);

	if (!fin) {
		cerr << "Can't open file " << argv[1] << endl;
		return 0;
	}

	#pragma endregion

	WordsParser wordsParser;

	string line;

	while (getline(fin, line)) wordsParser.AddLine(line);

	#pragma region Output

	wordsParser.VectorToCSV(wordsParser.MapToSortedVector(), argv[2]);

	#pragma endregion

	fin.close();
	return 0;
}
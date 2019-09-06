#include <fstream>
#include <iostream>

using namespace std;

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



	fin.close();

}
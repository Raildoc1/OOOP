#include"Parser.h"

int main(int argc, char* argv[]) {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (argc < 2) {
		SetConsoleTextAttribute(hConsole, 12); // Red Color
		std::cout << "[Error]:";
		SetConsoleTextAttribute(hConsole, 15); // White Color
		std::cout << " input file expected! Correct input is \"Worker.exe input.txt\"." << std::endl;
	}

	Readfile read(1, "input.txt");
	Writefile write(2, "output.txt");
	Grep grep(3, "replace");
	Sort sort;

	write.execute(sort.execute(read.execute("")));

	return 0;
}
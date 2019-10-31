#include "Executor.h"

#include "ColorMessages.h"

int main(int argc, char* argv[]) {

	if (argc < 2) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12); // Red Color
		std::cout << "[Error]:";
		SetConsoleTextAttribute(hConsole, 15); // White Color
		std::cout << "input file expected!Correct input is \"Worker.exe input.txt\"." << std::endl;
	}

	Executor::GetInstance().ExecuteWorkFlow("input.txt");

	/*Readfile read(1, "input.txt");
	Writefile write(2, "output.txt");
	Grep grep(3, "replace");
	Sort sort;

	write.execute(sort.execute(read.execute("")));*/

	std::string s = "134 = bla bla bla";

	std::string s1 = s.substr(0, s.find(" = "));
	std::string s2 = s.erase(0, 3 + s.find(" = "));

	int i = std::atoi(s1.c_str());

	return 0;
}
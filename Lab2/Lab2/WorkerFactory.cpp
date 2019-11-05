#include "WorkerFactory.h"

WorkerFactory& WorkerFactory::GetInstance() {
	static WorkerFactory instance;
	return instance;
}

Worker* WorkerFactory::Create(std::string key, std::string parametrs) const {

	if (key == "readfile") 
	{
		return new Readfile(parametrs);
	}
	else if (key == "writefile")
	{
		return new Writefile(parametrs);
	}
	else if (key == "grep")
	{
		return new Grep(parametrs);
	}
	else if (key == "sort")
	{
		return new Sort();
	}
	else if (key == "replace")
	{
		return new Replace(parametrs);
	}
	else if (key == "dump")
	{
		return new Dump(parametrs);
	}
	else {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14); // Red Color
		std::cout << "[Warning]:";
		SetConsoleTextAttribute(hConsole, 15); // White Color
		std::cout << " command " << key << " not found!" << std::endl;
		return nullptr;
	}
}

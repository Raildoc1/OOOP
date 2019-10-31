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
		// return new replace
	}
	else if (key == "dump")
	{
		return new Dump(parametrs);
	}
	
	return nullptr;
}

#pragma once

#include "Worker.h"

#include "Readfile.h"
#include "Writefile.h"
#include "Grep.h"
#include "Sort.h"
#include "Dump.h"

class WorkerFactory {

public:
	static WorkerFactory& GetInstance();
	Worker* Create(std::string key, std::string parametrs) const;

};


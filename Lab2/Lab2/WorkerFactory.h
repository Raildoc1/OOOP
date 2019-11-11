#pragma once

#include "ICommand.h"

#include "Writefile.h"
#include "Readfile.h"
#include "Replace.h"
#include "Grep.h"
#include "Sort.h"
#include "Dump.h"

class WorkerFactory {

public:
	static WorkerFactory& GetInstance();
	ICommand* Create(std::string key, std::string parametrs) const;

};


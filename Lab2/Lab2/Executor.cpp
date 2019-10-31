#include "Executor.h"

void Executor::ExecuteWorkFlow(std::string fileName) {

	// Parse

	Parser parser;

	parser.readCommands(fileName, commands, executeOrder);

	// Execute

	for (int x : executeOrder) {
		buffer = commands[x]->execute(buffer);
	}

	return;
}

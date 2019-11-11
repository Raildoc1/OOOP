#include "CommandFactory.h"

CommandFactory& CommandFactory::Instance() {
	static CommandFactory instance;
	return instance;
}

void CommandFactory::RegisterMaker(const std::string& key, ICommandMaker* maker) {
	if (_makers.find(key) != _makers.end())
	{
		throw new std::string("Multiple makers for given key!");
	}
	_makers[key] = maker;
}

ICommand* CommandFactory::CreateCommand(const std::string& key, const std::string& parametrs) {

	auto i = _makers.find(key);

	if (i == _makers.end()) {
		throw std::string(key + " command does not exist!");
	}

	ICommandMaker* maker = i->second;
	return maker->Create(parametrs);
}

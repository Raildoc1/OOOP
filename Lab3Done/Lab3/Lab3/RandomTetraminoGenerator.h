#pragma once

#include <random>
#include <string>
#include <map>

#include "Tetramino.h"


class RandomTetraminoGenerator {

	std::map<int, Tetramino *> tetraminoes;

public:

	static RandomTetraminoGenerator& Instance();

	void RegisterTetramino(const int & id, Tetramino * tetramino);

	Tetramino * Generate() {
		int randomId = rand() % tetraminoes.size();
		return tetraminoes[randomId];
	}
};


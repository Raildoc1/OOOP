#pragma once

#include <random>
#include <string>
#include <map>

#include "Tetramino.h"
#include <time.h>


class RandomTetraminoGenerator {

	std::map<int, Tetramino *> tetraminoes;

public:

	static RandomTetraminoGenerator& Instance();

	void RegisterTetramino(const int & id, Tetramino * tetramino);

	Tetramino * Generate() {
		srand(time(NULL));
		int randomId = rand() % tetraminoes.size();
		return tetraminoes[randomId];
	}
};


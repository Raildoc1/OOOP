#include "RandomTetraminoGenerator.h"

RandomTetraminoGenerator& RandomTetraminoGenerator::Instance() {
	static RandomTetraminoGenerator instance;
	return instance;
}

void RandomTetraminoGenerator::RegisterTetramino(const int& id, Tetramino * tetramino) {
	if (tetraminoes.find(id) != tetraminoes.end()) {
		throw std::string("Same id for different tetraminoes selected!");
	}
	tetraminoes[id] = tetramino;
}

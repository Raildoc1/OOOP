#pragma once
#include "Player.h"

class RandomPlayer : public Player {
public:
	RandomPlayer() {
		field = new Field();
	}
	~RandomPlayer() {
		delete field;
	}
	void Update();
};


#pragma once
#include "Player.h"

class SmartPlayer : public Player {
private:
	int counter = 0;
	int moveLeft = 0;
	int moveRight = 0;
	int max_depth = 0;
	int column = 0;
public:
	SmartPlayer() {
		field = new Field();
	}
	~SmartPlayer() {
		delete field;
	}
	void Update();
};


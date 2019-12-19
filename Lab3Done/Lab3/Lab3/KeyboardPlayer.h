#pragma once
#include "Player.h"
#include <Windows.h>

class KeyboardPlayer : public Player {
public:
	KeyboardPlayer() {
		field = new Field();
	}
	~KeyboardPlayer() {
		delete field;
	}
	void Update();
	int GetSymbol(int i, int j) { return field->GetSymbol(i, j); }
	int GetScore() { return field->GetScore(); }
	int GetLines() { return field->GetLines(); }
};




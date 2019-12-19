#pragma once
#include "Field.h"

class Player {
protected:
	Field* field;
public:
	bool inGame = true;
	virtual void Update() = 0;
	virtual int GetSymbol(int i, int j) { return field->GetSymbol(i, j); }
	virtual int GetScore() { return field->GetScore(); }
	virtual int GetLines() { return field->GetLines(); }
};

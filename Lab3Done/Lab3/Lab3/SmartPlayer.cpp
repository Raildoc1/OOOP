#include "SmartPlayer.h"

void SmartPlayer::Update() {

	if (!inGame) return;

	field->Update();

	if (moveLeft > 0) {
		field->MoveLeft();
		if (--moveLeft == 0) moveLeft = -1;
	}

	if (moveRight > 0) {
		field->MoveRight();
		if (--moveRight == 0) moveRight = -1;
	}

	if (!field->IsMoving()) {
		for (int j = 0; j < field->FIELD_WIDTH; j++) {
			for (int i = 0; i < field->FIELD_HEIGHT; i++) {
				if (GetSymbol(i, j) == 0) {
					if (i > max_depth) {
						max_depth = i;
						column = j;
					}
				}
				else {
					break;
				}
			}
		}
		if (column <= 4) {
			moveLeft = 5 - column;
			moveRight = 0;
		}
		else {
			moveLeft = 0;
			moveRight = column - 5;
		}
		max_depth = 0;
		column = 0;
	}
}
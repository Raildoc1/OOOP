#include "SmartPlayer.h"

void SmartPlayer::Update() {

	field->Update();

	/*std::string currentTetramino = "";

	if (field->GetTetramino()->GetShape(1) == 1) {
		if (field->GetTetramino()->GetShape(2) == 1 && field->GetTetramino()->GetShape(4) == 1 && field->GetTetramino()->GetShape(5) == 1) currentTetramino = "S";
		else if (field->GetTetramino()->GetShape(0) == 1) {
			if (field->GetTetramino()->GetShape(2) == 1) {
				if (field->GetTetramino()->GetShape(5) == 1) {
					currentTetramino = "T";
				} else if (field->GetTetramino()->GetShape(3) == 1) {
					currentTetramino = "I";
				} else if (field->GetTetramino()->GetShape(4) == 1) {
					currentTetramino = "G";
				} else if (field->GetTetramino()->GetShape(6) == 1) {
					currentTetramino = "IG";
				}
			} else if (field->GetTetramino()->GetShape(5) == 1) {
				if (field->GetTetramino()->GetShape(4) == 1) {
					currentTetramino = "Q";
				}
				else if (field->GetTetramino()->GetShape(6) == 1) {
					currentTetramino = "Z";
				}
			}
		}
	}

	int max_depth = 0;
	int column = 0;

	for (int j = 0; j < field->FIELD_WIDTH; j++) {
		for (int i = 0; i < field->FIELD_HEIGHT; i++) {
			if (field->GetSymbol(i, j) == 0) {
				if (i > max_depth) {
					max_depth = i;
					column = j;
				}
			}
		}
	}

	if (column < 4) {
		for (int i = 4; i > column; i--) {
			field->MoveLeft();
		}
	}
	else {
		for (int i = 4; i < column; i++) {
			field->MoveRight();
		}
	}

	currentTetramino = "";*/


	/*if (moveLeft == 0 && moveRight == 0) {
		switch (counter) {
		case 0:
			moveLeft = 4;
			break;
		case 1:
			moveLeft = 2;
			break;
		case 2:
			moveLeft = 0;
			break;
		case 3:
			moveRight = 2;
			break;
		case 4:
			moveLeft = 4;
			break;
		default:
			break;
		}

		counter = (counter + 1) % 5;
	}*/

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
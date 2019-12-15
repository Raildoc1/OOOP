#include "RandomTetraminoGenerator.h"
#include "Field.h"

void Field::Update(){

	if (!moving) {
		spawnFigure();
	}
	else {
		moveFigure();
		Render();
	}

	CheckFilledLines();

}

void Field::Render() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (currentTetramino->GetShape(i, j, OldRotation) == 1) {
				field[OldYloc + i][OldXloc + j] = 0;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (currentTetramino->GetShape(i, j, rotation) == 1) {
				field[Yloc + i][Xloc + j] = 2;
			}
		}
	}

	if (!moving) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (currentTetramino->GetShape(i, j, rotation) == 1) {
					field[Yloc + i][Xloc + j] = 1;
				}
			}
		}
	}

	OldRotation = rotation;
	OldXloc = Xloc;
	OldYloc = Yloc;
}

void Field::spawnFigure() {
	currentTetramino = RandomTetraminoGenerator::Instance().Generate();

	Xloc = 4;
	Yloc = 0;

	moving = true;
}

bool Field::moveFigure() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (currentTetramino->GetShape(i, j, rotation) == 1) {
				if (GetSymbol(Yloc + i + 1, Xloc + j) == 1 || GetSymbol(Yloc + i + 1, Xloc + j) == -1) {
					moving = false;
					break;
				}
			}
		}
	}
	if (moving) OldYloc = Yloc++;
	return false;
}

void Field::Rotate(){

	bool rotating = true;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (currentTetramino->GetShape(i, j, (rotation + 1) % 4) == 1) {
				if (GetSymbol(Yloc + i, Xloc + j) == 1 || GetSymbol(Yloc + i, Xloc + j) == -1) {
					rotating = false;
					break;
				}
			}
		}
	}

	if (rotating) {
		OldRotation = rotation;
		rotation = (rotation + 1) % 4;
	}
}

void Field::MoveRight() {

	bool moveRight = true;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (currentTetramino->GetShape(i, j, rotation) == 1) {
				if (GetSymbol(Yloc + i, Xloc + j + 1) == 1 || GetSymbol(Yloc + i, Xloc + j + 1) == -1) {
					moveRight = false;
					break;
				}
			}
		}
	}

	if (moveRight) {
		OldXloc = Xloc;
		Xloc++;
	}
}

void Field::MoveLeft(){
	/*OldXloc = Xloc;
	Xloc--;
	if (Xloc < 0) Xloc = 0;*/

	bool moveLeft = true;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (currentTetramino->GetShape(i, j, rotation) == 1) {
				if (GetSymbol(Yloc + i, Xloc + j - 1) == 1 || GetSymbol(Yloc + i, Xloc + j - 1) == -1) {
					moveLeft = false;
					break;
				}
			}
		}
	}

	if (moveLeft) {
		OldXloc = Xloc;
		Xloc--;
	}
}

void Field::CheckFilledLines() {
	for (int i = 0; i < FIELD_HEIGHT; i++) {
		for (int j = 0; j < FIELD_WIDTH; j++) {
			if (field[i][j] != 1) break;
			if (field[i][j] == 1 && j == FIELD_WIDTH - 1) DeleteLine(i);
		}
	}
}

void Field::DeleteLine(int i) {
	for (int j = i; j > 0; j--) {
		for (int m = 0; m < FIELD_WIDTH; m++) {
			field[j][m] = field[j - 1][m];
		}
	}
	for (int m = 0; m < FIELD_WIDTH; m++) {
		field[0][m] = 0;
	}
	score += SCORE_FOR_LINE;
	lines += 1;
}

int Field::GetSymbol(int i, int j) {
	if (i < FIELD_HEIGHT && j < FIELD_WIDTH && i >= 0 && j >= 0) {
		return field[i][j];
	}
	else return -1;
}

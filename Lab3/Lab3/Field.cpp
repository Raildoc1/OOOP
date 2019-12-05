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

	//field[OldYloc][OldXloc] = 0;
	//field[Yloc][Xloc] = 3;

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
	/*OldXloc = Xloc;
	Xloc++;
	if (Xloc > 6) Xloc = 6;*/


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

int Field::GetSymbol(int i, int j) {
	if (i < FIELD_HEIGHT && j < FIELD_WIDTH && i >= 0 && j >= 0) {
		return field[i][j];
	}
	else return -1;
}

#include "RandomPlayer.h"

void RandomPlayer::Update() {

	if (!inGame) return;

	field->Update();

	srand(time(NULL));

	switch (rand() % 3) {
	case 0: field->MoveLeft();
		break;
	case 1: field->MoveRight();
		break;
	case 2: field->Rotate();
		break;
	}
}

#include "KeyboardPlayer.h"

void KeyboardPlayer::Update() {

	if (!inGame) return;

	field->Update();

	if (GetAsyncKeyState(65)) {
		field->MoveLeft();
	}
	else if (GetAsyncKeyState(68)) {
		field->MoveRight();
	}
	else if (GetAsyncKeyState(82)) {
		field->Rotate();
	}
}

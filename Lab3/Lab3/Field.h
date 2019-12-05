#pragma once
class Field {
private:

	const int GAMESPEED = 20000;

	Tetramino* currentTetramino;

	int rotation = 0;
	int OldRotation = 0;

	int OldXloc = 4;
	int OldYloc = 0;

	int Xloc = 0;
	int Yloc = 0;

	bool moving = false;

	int time = 0;

public:

	static const int FIELD_HEIGHT = 25;
	static const int FIELD_WIDTH = 10;
private:
	int field[FIELD_HEIGHT][FIELD_WIDTH] = { 0 };
public:
	void Update();
	void Render();
	void spawnFigure();

	bool moveFigure();

	void Rotate();
	void MoveRight();
	void MoveLeft();

	int GetSymbol(int i, int j);
};


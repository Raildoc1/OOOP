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

	int score = 0;
	int lines = 0;

public:
	const int SCORE_FOR_LINE = 1520;
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

	void CheckFilledLines();
	void DeleteLine(int i);

	int GetSymbol(int i, int j);
	int GetScore() { return score; }
	int GetLines() { return lines; }
};


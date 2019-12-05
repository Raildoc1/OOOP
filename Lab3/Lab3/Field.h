#pragma once
class Field {
private:

	const int GAMESPEED = 20000;

	int field[20][10] = {0};
	int time = 0;

public:

	void Update();
	void Render();
	void spawnFigure();

	bool moveFigure();
};


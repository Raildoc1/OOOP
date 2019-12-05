#include "Field.h"

void Field::Update(){

	if (time < GAMESPEED) {
		time++;
	} else {
		time = 0;
		if (!moveFigure()) {
			spawnFigure();
		}
	}

}

void Field::Render()
{
}

void Field::spawnFigure()
{
}

bool Field::moveFigure()
{
	return false;
}

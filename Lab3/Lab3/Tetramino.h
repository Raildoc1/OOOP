#pragma once
class Tetramino {
private:
	int shape[4][2] = {0};
	// 0 1 2 3
	// 4 5 6 7
public:
	Tetramino(int first, int second, int third, int fourth) {
		shape[first % 4][first / 4] = 1;
		shape[second % 4][second / 4] = 1;
		shape[third % 4][third / 4] = 1;
		shape[fourth % 4][fourth / 4] = 1;
	}
};


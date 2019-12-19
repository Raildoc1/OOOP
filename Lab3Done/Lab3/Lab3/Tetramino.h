#pragma once
class Tetramino {
private:
	int shape[4][2] = { { 0, 0 } , { 0, 0 } , { 0, 0 } , { 0, 0 } };
	// 0 1 2 3
	// 4 5 6 7
public:
	Tetramino(int first, int second, int third, int fourth) {
		shape[first % 4][first / 4] = 1;
		shape[second % 4][second / 4] = 1;
		shape[third % 4][third / 4] = 1;
		shape[fourth % 4][fourth / 4] = 1;
	}

	int GetShape(int i) {
		return shape[i % 4][i / 4];
	}

	int GetShape(int i, int j, int r) {
		switch (r) {
			case 0:	
				if (j <= 0 || j >= 3 || i >= 4) return 0;
				return shape[i][j - 1];
				break;

			case 1:
				if (j >= 4 || i <= 0 || i >= 3) return 0;
				return shape[3 - j][i - 1];
				break;

			case 2:
				if (j <= 0 || j >= 3 || i >= 4) return 0;
				return shape[3 - i][1 - (j - 1)];
				break;

			case 3:
				if (j >= 4 || i <= 0 || i >= 3) return 0;
				return shape[j][1 - (i - 1)];
				break;

			default: return -1;
		}
	}
};


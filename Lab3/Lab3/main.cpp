#include <iostream>
#include <windows.h>

#include "RandomTetraminoGenerator.h"
#include "Field.h"


int main() {

	const int UPDATES_IN_FRAME = 50000000;

	static Tetramino T(0, 1, 2, 5);
	static Tetramino Z(0, 1, 5, 6);
	static Tetramino S(1, 2, 4, 5);
	static Tetramino I(0, 1, 2, 3);
	static Tetramino G(0, 1, 2, 4);
	static Tetramino IG(0, 1, 2, 6);
	static Tetramino Q(0, 1, 4, 5);

	RandomTetraminoGenerator::Instance().RegisterTetramino(0, &T);
	RandomTetraminoGenerator::Instance().RegisterTetramino(1, &Z);
	RandomTetraminoGenerator::Instance().RegisterTetramino(2, &S);
	RandomTetraminoGenerator::Instance().RegisterTetramino(3, &I);
	RandomTetraminoGenerator::Instance().RegisterTetramino(4, &G);
	RandomTetraminoGenerator::Instance().RegisterTetramino(5, &IG);
	RandomTetraminoGenerator::Instance().RegisterTetramino(6, &Q);

	int field[29][23] = {
		{201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187},
		{186, 83 , 67 , 79 , 82 , 69 , 32 , 32 , 32 , 32 , 32 , 186, 83 , 67 , 79 , 82 , 69 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 186, 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{204, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 185},
		{186, 76 , 73 , 78 , 69 , 83 , 186, 32 , 32 , 32 , 32 , 186, 76 , 73 , 78 , 69 , 83 , 186, 32 , 32 , 32 , 32 , 186},
		{186, 32 , 48 , 48 , 48 , 32 , 186, 32 , 32 , 32 , 32 , 186, 32 , 48 , 48 , 48 , 32 , 186, 32 , 32 , 32 , 32 , 186},
		{204, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 185},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 186},
		{200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188}
	};

	bool running = true;

	int count = 0;

	/*for (int i = 0; i < 255; i++)
	{
		std::cout << i << " - " << static_cast<char>(i) << std::endl;
	}*/

	Field player1;
	Field player2;

	while (running) {
		if ((count++) > UPDATES_IN_FRAME) {

			player1.Update();
			player2.Update();

			switch (rand() % 3) {
				case 0: player1.MoveLeft();
					break;
				case 1: player1.MoveRight();
					break;
				case 2: player1.Rotate();
					break;
			}

			switch (rand() % 3) {
			case 0: player2.MoveLeft();
				break;
			case 1: player2.MoveRight();
				break;
			case 2: player2.Rotate();
				break;
			}

			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < Field::FIELD_WIDTH; j++) {
					field[8 + i][1 + j] = player1.GetSymbol(i + (Field::FIELD_HEIGHT - 20), j) == 1 || player1.GetSymbol(i + (Field::FIELD_HEIGHT - 20), j) == 2 ? 254 : 32;
					field[8 + i][12 + j] = player2.GetSymbol(i + (Field::FIELD_HEIGHT - 20), j) == 1 || player2.GetSymbol(i + (Field::FIELD_HEIGHT - 20), j) == 2 ? 254 : 32;
				}
			}

			system("cls");
			for (int i = 0; i < 29; i++) {
				for (int j = 0; j < 23; j++) {
					std::cout << static_cast<char>(field[i][j]);
				}
				std::cout << std::endl;
			}

			for (int i = 0; i < Field::FIELD_WIDTH; i++) {
				if (player1.GetSymbol((Field::FIELD_HEIGHT - 21), i) == 1) running = false;
				if (player2.GetSymbol((Field::FIELD_HEIGHT - 21), i) == 1) running = false;
			}

			/*system("cls");

			for (int i = 0; i < Field::FIELD_HEIGHT; i++) {
				for (int j = 0; j < Field::FIELD_WEIDTH; j++) {
					switch (player1.GetSymbol(i, j))
					{
					case 1: std::cout << static_cast<char>(66);
						break;
					case 2: std::cout << static_cast<char>(77);
						break;
					case 3: std::cout << static_cast<char>(42);
						break;
					default: std::cout << static_cast<char>(32);
						break;
					}
				}
				std::cout << std::endl;
			}*/

			count = 0;
		}

	}

	system("cls");

	std::cout << "GAME OVER!";

	return 0;
}
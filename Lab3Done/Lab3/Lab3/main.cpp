﻿#include <iostream>
#include <windows.h>

#include "RandomTetraminoGenerator.h"
#include "KeyboardPlayer.h"
#include "RandomPlayer.h"
#include "SmartPlayer.h"

int main() {

	const int UPDATES_IN_FRAME = 50'000'000;

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

	const int SCORE_LENGTH = 1000000;

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

	int count = 500000000;

	SmartPlayer player1;
	KeyboardPlayer player2;

	while (running) {
		if ((count++) > UPDATES_IN_FRAME) {

			player1.Update();
			player2.Update();

			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < Field::FIELD_WIDTH; j++) {
					field[8 + i][1 + j] = player1.GetSymbol(i + (Field::FIELD_HEIGHT - 20), j) == 1 || player1.GetSymbol(i + (Field::FIELD_HEIGHT - 20), j) == 2 ? 254 : 32;
					field[8 + i][12 + j] = player2.GetSymbol(i + (Field::FIELD_HEIGHT - 20), j) == 1 || player2.GetSymbol(i + (Field::FIELD_HEIGHT - 20), j) == 2 ? 254 : 32;
				}
			}

			int buffer = SCORE_LENGTH;

			for (int i = 0; i < 6; i++) {
				field[2][i + 5] = (player1.GetScore() % buffer) / (buffer / 10) + '0';
				field[2][i + 16] = (player2.GetScore() % buffer) / (buffer / 10) + '0';
				buffer /= 10;
			}

			system("cls");

			for (int i = 0; i < 29; i++) {
				for (int j = 0; j < 23; j++) {
					std::cout << static_cast<char>(field[i][j]);
				}
				std::cout << std::endl;
			}

			for (int i = 0; i < Field::FIELD_WIDTH; i++) {
				if (player1.GetSymbol((Field::FIELD_HEIGHT - 21), i) == 1) player1.inGame = false;
				if (player2.GetSymbol((Field::FIELD_HEIGHT - 21), i) == 1) player2.inGame = false;
			}

			if (!player1.inGame) {
				if (player1.GetScore() <= player2.GetScore()) {
					system("cls");
					std::cout << "Player 2 Win!" << std::endl << std::endl;
					std::cout << "Player 1 Score: " << player1.GetScore() << std::endl;
					std::cout << "Player 2 Score: " << player2.GetScore() << std::endl;
					return 0;
				}
			}

			if (!player2.inGame) {
				if (player2.GetScore() <= player1.GetScore()) {
					system("cls");
					std::cout << "Player 1 Win!" << std::endl << std::endl;
					std::cout << "Player 1 Score: " << player1.GetScore() << std::endl;
					std::cout << "Player 2 Score: " << player2.GetScore() << std::endl;
					return 0;
				}
			}

			count = 0;
		}
	}

	return 0;
}
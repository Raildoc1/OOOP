﻿#include <windows.h>
#include <iostream>

#include "RandomTetraminoGenerator.h"

int main() {

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

	for (int i = 0; i < 255; i++)
	{
		std::cout << i << " - " << static_cast<char>(i) << std::endl;
	}

	//system("cls");

	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 23; j++) {
			std::cout << static_cast<char>(field[i][j]);
		}
		std::cout << std::endl;
	}

	return 0;
}
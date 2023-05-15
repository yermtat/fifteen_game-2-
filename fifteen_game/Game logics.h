#pragma once
#include "Data.h"
#include"helper functions.h"
#include"file operations.h"

void fillFields(ushort game_field[][4]) {
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			game_field[i][j] = i * 4 + j + 1;
		}
	}
}

void movement(ushort game_field[][4], int side) {
	coord = findEmptyCell(game_field);

	switch (side)
	{
	case LEFT:
		if (coord.y + 1 <= 3) {
			swap(game_field[coord.x][coord.y], game_field[coord.x][coord.y + 1]);
		}
		break;
	case RIGHT:
		if (coord.y - 1 >= 0) {
			swap(game_field[coord.x][coord.y], game_field[coord.x][coord.y - 1]);
		}
		break;
	case UP:
		if (coord.x + 1 <= 3) {
			swap(game_field[coord.x][coord.y], game_field[coord.x + 1][coord.y]);
		}
		break;
	case DOWN:
		if (coord.x - 1 >= 0) {
			swap(game_field[coord.x][coord.y], game_field[coord.x - 1][coord.y]);
		}
		break;
	}
	save(game_field);
}

void startPosition(ushort game_field[][4], levels level) {
	unsigned int random_side{};
	int sides[]{ LEFT, RIGHT, UP, DOWN };
	for (size_t i = 0; i < level; i++)
	{
		random_side = rand() % 4;
		movement(game_field, sides[random_side]);
	}
}

bool isWin(ushort game_field[][4]) {
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (!isRightPosition(game_field, Coord{ ushort(i), ushort(j) })) return false;
		}
	}
	return true;
}


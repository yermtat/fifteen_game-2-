#pragma once
#include"Data.h"

bool isRightPosition(ushort game_field[][4], Coord c) {
	return game_field[c.x][c.y] == c.x * 4 + c.y + 1;
	// 2 3 - 2 * 4 + 3 + 1 = 8 + 3 + 1 = 12
}

Coord findEmptyCell(ushort game_field[][4]) {
	for (ushort i = 0; i < 4; i++)
	{
		for (ushort j = 0; j < 4; j++)
		{
			if (game_field[i][j] == 16) {
				return Coord{ i, j };
			}
		}
	}
}

char* encrypt(const char plain_text[], int key) {
	char* cipher_text = new char[50];
	for (int i = 0; i < strlen(plain_text); i++) {
		if (plain_text[i]>= 'A' && plain_text[i] <= 'Z') {
			cipher_text[i] = char(int(plain_text[i] + key - 65) % 26 + 65);
		}
		else if (plain_text[i] >= 'a' && plain_text[i] <= 'z') {
			cipher_text[i] = char(int(plain_text[i] + key - 97) % 26 + 97);
		}
		else
		{
			cipher_text[i] = plain_text[i];
		}
	}
	cipher_text[strlen(plain_text)] = '\0';
	return cipher_text;
}

char* decrypt(const char cipher_text[], int key) {
	char* plain_text = new char[50];
	for (int i = 0; i < strlen(cipher_text); i++) {
		if (cipher_text[i] >= 'A' && cipher_text[i] <= 'Z') {
			plain_text[i] = char((int(cipher_text[i] - key - 65) % 26 + 26) % 26 + 65);
		}
		else if (cipher_text[i] >= 'a' && cipher_text[i] <= 'z') {
			plain_text[i] = char((int(cipher_text[i] - key - 97) % 26 + 26) % 26 + 97);
		}
		else {
			plain_text[i] = cipher_text[i];
		}
	}
	plain_text[strlen(cipher_text)] = '\0';
	return plain_text;
}

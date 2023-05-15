#pragma once
#include"Data.h"
#include"helper functions.h"


void startIntro() {
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	const char* intro[]{
	"11   555555          GGGGGGG     AAAAA    MMM     MMM   EEEEEE",
	"11   55              GG         AA   AA   MMMM   MMMM   EE    ",
	"11   555555          GG         AAAAAAA   MM  MMM MMM   EEEEEE",
	"11        55         GG  GGG    AA   AA   MM   M   MM   EE    ",
	"11   555555          GGGGGGG    AA   AA   MM       MM   EEEEEE"
	};

	c.X = 20;
	c.Y = 7;
	
	for (size_t i = 0; i < 5; i++)
	{
		SetConsoleCursorPosition(h, c);
		++c.Y;
		for (size_t j = 0; j < strlen(intro[i]); j++)
		{
			cout << intro[i][j];
			Sleep(10);
		}
		cout << '\n';
	}
	Sleep(2000);
	system("cls");
}

void showFields(ushort game_field[][4]) {
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (game_field[i][j] == 16) {
				SetConsoleTextAttribute(h, 0);
			}
			else if (isRightPosition(game_field, Coord{ ushort(i), ushort(j) })) {
				SetConsoleTextAttribute(h, 10);
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
			}
			cout << setw(5) << right << game_field[i][j];
		SetConsoleTextAttribute(h, 0);
		}
		cout << "\n\n";
	}
}

void winAnimation() {
	for (size_t i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
		{
			SetConsoleTextAttribute(h, 10);
		}
		else
		{
			SetConsoleTextAttribute(h, 12);
		}
		cout << "You WIN!!!";
		Sleep(500);
		system("cls");
	}
	SetConsoleTextAttribute(h, 0);
}

ushort menu(const char* Menu[], ushort length) {
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned char key{};
	short menuPos = 0;
	
	while (true)
	{
		c.X = 40;
		c.Y = 10;
		menuPos %= length;
		if (menuPos < 0) menuPos = length - 1;
		for (size_t i = 0; i < length; i++)
		{			
			SetConsoleCursorPosition(h, c);
			++c.Y;
			if (i == menuPos)
				SetConsoleTextAttribute(h, 79);
			else
			{
				SetConsoleTextAttribute(h, 15);
			}
			cout << setw(15) << left << Menu[i] << endl;
		}
		SetConsoleTextAttribute(h, 0);
		key = _getch();
		if (key == 224) {
			key = _getch();
			switch (key)
			{
			case UP:
				menuPos--;
				break;
			case DOWN:
				menuPos++;
				break;
			}
		}
		else {
			if (key == 13)
			{
				SetConsoleTextAttribute(h, 15);
				return menuPos + 1;
			}
		}
		system("cls");
	}

	
}

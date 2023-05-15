#pragma once
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<time.h>
#include<Windows.h>

using namespace std;

HANDLE h;

COORD c;


FILE* file;

typedef unsigned short ushort;

enum controllers { 
	LEFT = 75, 
	RIGHT = 77, 
	UP = 72, 
	DOWN = 80 
};

enum levels 
{
	EASY = 100,
	NORMAL = 250,
	HARD = 700
};

struct Coord {
	ushort x : 3;
	ushort y : 3;
} coord;

const levels levelArray[3]{ EASY, NORMAL, HARD };

struct User
{
	char username[50];
	char password[50];
	ushort game_field[4][4]{};
};

int length = 1;
User* users = new User[length];


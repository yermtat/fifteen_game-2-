#pragma once
#include"Data.h"

void save(ushort game_field[][4]) {
	fopen_s(&file, "fifteen.dat", "wb");

	fwrite((char*)game_field, sizeof(int), 16, file);

	fclose(file);
}

void load(ushort game_field[][4]) {
	fopen_s(&file, "fifteen.dat", "rb");

	fread((char*)game_field, sizeof(int), 16, file);

	fclose(file);
}

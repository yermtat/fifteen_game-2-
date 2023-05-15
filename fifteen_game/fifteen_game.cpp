#include"Game logics.h"
#include"UI.h"
#include"users operations.h"

void game(ushort game_field[][4]) {
	unsigned char arrow{};
	while (!isWin(game_field))
	{
		arrow = _getch();
		arrow = _getch();

		system("cls");

		movement(game_field, arrow);

		showFields(game_field);
	}
}

int main() {
	srand(time(NULL));
	User admin;
	strcpy_s(admin.username, 50, "Admin");
	strcpy_s(admin.password, 50, encrypt("P@ssw0rd", 3));
	users[0] = admin;

	User currentUser{};

	/*startIntro();*/
	ushort game_field[4][4]{};
	ushort menuItem = 0;

	const char* introMenu[] =
	{
		"   Sign In",
		"   Sign Up",
		"   Exit"
	};


	const char* startMenu[] = {
		"   New game",
		"   Load Game",
		"   Exit"
	};

	const char* levelMenu[] = {
		"   Easy",
		"   Medium",
		"   Hard"
	};

	menuItem = menu(introMenu, 3);
	system("cls");
	char login[50]{};
	char password[50]{};
	char confirmPassword[50]{};
	int index{};
	switch (menuItem)
	{
	case 1:
		while (true)
		{
			cout << "Enter your login:" << endl;
			cin >> login;
			cout << "Enter your password:" << endl;
			cin >> password;
			index = isUser(users, length, login);
			if (index != -1
				&& strcmp(encrypt(password, 3), users[index].password) == 0)
			{
				system("cls");
				currentUser = users[index];
				break;
			}
			else {
				cout << "Login or password incorrect" << endl;
				system("pause");
				system("cls");
			}
		}

		break;
	case 2:
		while (true)
		{
			cout << "Enter your login:" << endl;
			cin >> login;
			cout << "Enter your password:" << endl;
			cin >> password;
			cout << "Confirm your password:" << endl;
			cin >> confirmPassword;
			index = isUser(users, length, login);
			if (index == -1) {
				if (strcmp(password, confirmPassword) == 0) {
					strcpy_s(currentUser.username, 50, login);
					strcpy_s(currentUser.password, 50, encrypt(password, 3));
					users = addUser(users, length, currentUser);
					system("cls");
					break;
				}
				else {
					cout << "Password and confirm passwor is not match" << endl;
				}
			}
			else
			{
				cout << "User is alredy registered" << endl;
			}
			system("pause");
			system("cls");
		}

		break;
	case 3:
		return 0;
	}

	menuItem = menu(startMenu, 3);
	switch (menuItem)
	{
	case 1:
		system("cls");
		menuItem = menu(levelMenu, 3);
		fillFields(currentUser.game_field);
		startPosition(currentUser.game_field, levelArray[menuItem - 1]);
		save(currentUser.game_field);
		break;
	case 2:
		load(currentUser.game_field);
		break;
	case 3: return 0;
	}
	system("cls");

	showFields(currentUser.game_field);

	game(currentUser.game_field);

	winAnimation();
}




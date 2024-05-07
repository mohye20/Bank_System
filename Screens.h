#pragma once
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <windows.h>
#include "AdminManager.h"
using namespace std;

class Screens{
private:
	static void bankName() {
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "\t\t      #########  ######    ######      ##     ##     #######   ########  ####    ##  ##   ##\n";
		cout << "\t\t          #      ##       ##    ##     ###   ###     ##    ##  ##    ##  ## ##   ##  ##  ##\n";
		cout << "\t\t          #      ######   ########     ## # # ##     #######   ########  ##  ##  ##  ## #\n";
		cout << "\t\t          #      ##       ##    ##     ##  #  ##     ##    ##  ##    ##  ##   ## ##  ##  ##\n";
		cout << "\t\t          #      ######   ##    ##     ##     ##     #######   ##    ##  ##    ####  ##   ##\n   ";
	}
	static void welcome() {
		system("Color 2f");
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t##       ##   ######    ##      #######  ########   ##     ##   ######\n";
		cout << "\t\t\t##   #   ##   ##        ##      ##       ##    ##   ###   ###   ##\n";
		cout << "\t\t\t##  # #  ##   ######    ##      ##       ##    ##   ## # # ##   ######\n";
		cout << "\t\t\t## #   # ##   ##        ##      ##       ##    ##   ##  #  ##   ##\n";
		cout << "\t\t\t###     ###   ######    ######  #######  ########   ##     ##   ######\n";
	
		bankName();
		Sleep(3000);
		system("cls");
		system("Color 0f");
		
	}
	static void loginOptions() {
		cout << "(1) Admin" << endl;
		cout << "(2) Employee" << endl;
		cout << "(3) Client\n" << endl;
		cout << "Login as: ";

	}
	static int loginAs() {
		loginOptions();
		int choice;
		cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3) {
			system("cls");
			return choice;
		}
		else {
			system("cls");
			return loginAs();
		}
	}
	static void invalid(int c) {
		system("cls");
		cout << "Incorrect id or password.\n" << endl;
		loginScreen(c);
	}
	static void logout() {
		system("cls");
		loginScreen(loginAs());
	}
	static void loadingBar()
	{
		// 0 - black background,
		// A - Green Foreground
		system("color 0A");

		// Initialize char for printing
		// loading bar
		char a = 177, b = 219;

		printf("\n\n\n\n");
		printf("\n\n\n\n\t\t\t\t\t"  "Loading...\n\n");
		printf("\t\t\t\t\t");

		// Print initial loading bar
		for (int i = 0; i < 26; i++)
			printf("%c", a);

		// Set the cursor again starting
		// point of loading bar
		printf("\r");
		printf("\t\t\t\t\t");
		
		// Print loading bar progress
		for (int i = 0; i < 26; i++) {
			printf("%c", b);

			// Sleep for 1 second
			Sleep(100);
		}

		cout << "\n\n\n\n\n\n\t\t\t\t\t\tBY  Mohye";
		Sleep(3000);

		system("cls");

		return;
	}

	static void loginScreen(int c) {
		int choice = c, id;
		string pass;
		cout << "Enter id: ";
		cin >> id;
		cout << "Enter password: ";
		cin >> pass;
		switch (choice)
		{
		case 1:
			if (AdminManager::login(id, pass) != NULL) { 
				while (AdminManager::adminOptions(AdminManager::login(id, pass)) != false);
				logout();
			}
			else invalid(1);
			break;
		case 2:
			if (EmployeeManager::login(id, pass) != NULL) {
				while (EmployeeManager::employeeOptions(EmployeeManager::login(id, pass)) != false);
				logout();
			}
			else invalid(2);
			break;
		case 3:
			if (ClientManager::login(id, pass) != NULL)
			{
				while (ClientManager::clientOptions(ClientManager::login(id, pass)) != false);
				logout();
			}
			else invalid(3);
			break;
		default:
			system("cls");
			loginOptions();
		}


	}
public:
	static void runApp() {
		FileManager::getAllData();
		loadingBar();
		welcome();
	

		loginScreen(loginAs());
		
	}
};
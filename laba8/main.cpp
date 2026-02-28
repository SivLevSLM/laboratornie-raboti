#include "HomeDyn15.h"
#include "BackRec5.h"
#include "HomeDyn3.h"
#include <iostream>
#include <windows.h>

int main() {
	using namespace std;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;
	do {
		cout << "\n";
		cout << "----------------------\n";
		cout << "Выберите задачу:\n";
		cout << "1. BackRec5\n";
		cout << "2. HomeDyn3\n";
		cout << "3. HomeDyn15\n";
		cout << "\nНажми 0, чтобы выйти\n";
		cout << "----------------------\n";

			cin >> choice;

			switch (choice) {
			case 1:
				BackRec5();
				break;
			case 2:
				HomeDyn3();
				break;
			case 3:
				HomeDyn15();
				break;
			case 0:
				cout << "Пока\n";
				break;
			default:
				cout << "Неверный ввод\n";
				break;
			}

		} while (choice != 0);
		return 0;
}
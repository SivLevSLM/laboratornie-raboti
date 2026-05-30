#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "STL5Assoc2.h"
#include "STL5Assoc17.h"
#include "STL5Assoc21.h"
#include "validation.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned>(time(nullptr)));

    int choice;
    do {
        std::cout << "1 - STL5Assoc2\n";
        std::cout << "2 - STL5Assoc17\n";
        std::cout << "3 - STL5Assoc21\n";
        std::cout << "0 - Выход\n";
        choice = Validation::getIntRange("Ваш выбор: ", 0, 3);

        switch (choice) {
        case 1: STL5Assoc2(); break;
        case 2: STL5Assoc17(); break;
        case 3: STL5Assoc21(); break;
        case 0: std::cout << "До свидания!\n"; break;
        }
        if (choice != 0) {
            std::cout << "\nНажмите Enter для возврата в меню...";
            std::cin.get();
            std::cin.get();
            system("cls");
        }
    } while (choice != 0);

    return 0;
}
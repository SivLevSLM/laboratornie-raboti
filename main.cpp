#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Dynamic5.h"
#include "Dynamic27.h"
#include "ListWork13.h"
#include "ListWork22.h"
#include "ListWork60.h"

int main() {
    srand(time(nullptr));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;

    do {
        std::cout << "1. Dynamic5" << std::endl;
        std::cout << "2. Dynamic27" << std::endl;
        std::cout << "3. ListWork13" << std::endl;
        std::cout << "4. ListWork22" << std::endl;
        std::cout << "5. ListWork60" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: Dynamic5(); break;
        case 2: Dynamic27(); break;
        case 3: ListWork13(); break;
        case 4: ListWork22(); break;
        case 5: ListWork60(); break;
        case 0: std::cout << "Завершение программы." << std::endl; break;
        default: std::cout << "Неверный выбор." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
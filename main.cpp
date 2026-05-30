#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "ListWork67.h"
#include "ListWork42.h"
#include "ListWork63.h"
#include "ListWork46.h"
#include "validation.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(nullptr));
    int number;
    do {
        std::cout << "1 - ListWork67\n";
        std::cout << "2 - ListWork42\n";
        std::cout << "3 - ListWork63\n";
        std::cout << "4 - ListWork46\n";
        std::cout << "0 - Выход\n";
        std::cout << "Ваш выбор: ";
        number = Validation::getIntRange(0, 4);
        switch (number) {
        case 1: ListWork67(); break;
        case 2: ListWork42(); break;
        case 3: ListWork63(); break;
        case 4: ListWork46(); break;
        case 0: std::cout << "Выход\n"; break;
        }
        if (number != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.get();
            std::cin.get();
            system("cls");
        }
    } while (number != 0);
    return 0;
}
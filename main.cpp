#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "STL3Alg3.h"
#include "STL3Alg28.h"
#include "STL3Alg38.h"
#include "STL3Alg60.h"
#include "validation.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned>(time(nullptr)));

    int choice;
    do {
        std::cout << "\n=^.^= Лабораторная работа №13 (Вариант 13) =^.^=\n";
        std::cout << "1 - STL3Alg3 (удалить первый и последний нулевой элемент списка)\n";
        std::cout << "2 - STL3Alg28 (скопировать положительные из второй половины списка в начало)\n";
        std::cout << "3 - STL3Alg38 (три конечных элемента после сортировки в порядке убывания)\n";
        std::cout << "4 - STL3Alg60 (средние арифметические соседних элементов)\n";
        std::cout << "0 - Выход\n";
        choice = Validation::getIntRange("Ваш выбор: ", 0, 4);

        switch (choice) {
        case 1: STL3Alg3(); break;
        case 2: STL3Alg28(); break;
        case 3: STL3Alg38(); break;
        case 4: STL3Alg60(); break;
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
#include "STL3Alg28.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include "validation.h"

void STL3Alg28() {
    using namespace std;

    list<int> L;
    int choice;
    cout << "\n--- STL3Alg28: скопировать положительные из второй половины списка в начало ---\n";
    cout << "Выберите способ заполнения списка (чётное количество):\n";
    cout << "1 - С клавиатуры\n2 - Из файла\n3 - Случайно\n";
    choice = Validation::getIntRange("Ваш выбор: ", 1, 3);

    if (choice == 1) {
        int n = Validation::getIntMin("Количество элементов (чётное): ", 2);
        while (n % 2 != 0)
            n = Validation::getIntMin("Ошибка! Введите чётное число: ", 2);
        cout << "Введите " << n << " чисел:\n";
        for (int i = 0; i < n; ++i) {
            cout << "  Элемент " << i + 1 << ": ";
            L.push_back(Validation::getInt());
        }
    }
    else if (choice == 2) {
        while (true) {
            string fname = Validation::getValidFile();
            ifstream f(fname);
            list<int> temp((istream_iterator<int>(f)), istream_iterator<int>());
            f.close();
            if (temp.size() % 2 != 0 || temp.empty()) {
                cout << "Ошибка! Количество элементов должно быть чётным.\n";
                continue;
            }
            L = temp;
            break;
        }
        cout << "Загружено " << L.size() << " чисел.\n";
    }
    else {
        int n = Validation::getIntMin("Количество элементов (чётное): ", 2);
        while (n % 2 != 0)
            n = Validation::getIntMin("Ошибка! Введите чётное число: ", 2);
        for (int i = 0; i < n; ++i)
            L.push_back(rand() % 201 - 100);
        cout << "Сгенерировано " << n << " случайных чисел.\n";
    }

    if (L.empty()) {
        cout << "Список пуст!\n";
        return;
    }

    cout << "\nИсходный список: ";
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Итератор на начало второй половины
    auto mid = L.begin();
    advance(mid, L.size() / 2);

    // Копируем положительные элементы из второй половины в начало
    list<int> temp;
    remove_copy_if(mid, L.end(), front_inserter(temp),
        [](int x) { return x <= 0; });
    // front_inserter даёт обратный порядок, разворачиваем
    temp.reverse();
    L.insert(L.begin(), temp.begin(), temp.end());

    cout << "Результат (положительные из второй половины скопированы в начало):\n";
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get(); cin.get();
}
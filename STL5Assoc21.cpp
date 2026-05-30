#include "STL5Assoc21.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "validation.h"

void STL5Assoc21() {
    using namespace std;
    srand(static_cast<unsigned>(time(nullptr)));

    vector<int> V;
    cout << "\n--- Заполнение вектора чисел ---\n";
    cout << "Выберите способ заполнения:\n";
    cout << "1 - С клавиатуры\n2 - Из файла\n3 - Случайно\n";
    int choice = Validation::getIntRange("Ваш выбор: ", 1, 3);

    if (choice == 1) {
        int n = Validation::getIntMin("Количество элементов: ", 1);
        cout << "Введите " << n << " чисел:\n";
        for (int i = 0; i < n; ++i) {
            cout << "  Элемент " << i + 1 << ": ";
            V.push_back(Validation::getInt());
        }
    }
    else if (choice == 2) {
        string fname = Validation::getValidFile();
        ifstream f(fname);
        V.assign((istream_iterator<int>(f)), istream_iterator<int>());
        f.close();
        cout << "Загружено " << V.size() << " чисел.\n";
    }
    else {
        int n = Validation::getIntMin("Количество элементов: ", 1);
        for (int i = 0; i < n; ++i)
            V.push_back(rand() % 1000);
        cout << "Сгенерировано " << n << " чисел.\n";
    }

    if (V.empty()) {
        cout << "Вектор пуст!\n";
        return;
    }

    cout << "\nИсходный вектор: ";
    copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    multimap<int, int> M;
    for (int num : V) {
        int lastDigit = abs(num) % 10;
        M.insert({ lastDigit, num });
    }

    cout << "\nРезультат группировки (последняя цифра - число):\n";
    for (const auto& p : M) {
        cout << p.first << " - " << p.second << endl;
    }

    cout << "\nНажмите Enter для продолжения...";
    cin.get(); cin.get();
}
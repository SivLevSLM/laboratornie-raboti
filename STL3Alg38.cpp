#include "STL3Alg38.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "validation.h"

void STL3Alg38() {
    using namespace std;

    vector<int> V;
    int choice;
    cout << "\n--- STL3Alg38: три конечных элемента после сортировки в порядке убывания ---\n";
    cout << "Выберите способ заполнения вектора (не менее 3 элементов):\n";
    cout << "1 - С клавиатуры\n2 - Из файла\n3 - Случайно\n";
    choice = Validation::getIntRange("Ваш выбор: ", 1, 3);

    if (choice == 1) {
        int n = Validation::getIntMin("Количество элементов (>=3): ", 3);
        cout << "Введите " << n << " чисел:\n";
        V.resize(n);
        for (int i = 0; i < n; ++i) {
            cout << "  Элемент " << i + 1 << ": ";
            V[i] = Validation::getInt();
        }
    }
    else if (choice == 2) {
        while (true) {
            string fname = Validation::getValidFile();
            ifstream f(fname);
            vector<int> temp((istream_iterator<int>(f)), istream_iterator<int>());
            f.close();
            if (temp.size() < 3) {
                cout << "Ошибка! В файле менее 3 чисел.\n";
                continue;
            }
            V = temp;
            break;
        }
        cout << "Загружено " << V.size() << " чисел.\n";
    }
    else {
        int n = Validation::getIntMin("Количество элементов (>=3): ", 3);
        V.resize(n);
        for (int i = 0; i < n; ++i)
            V[i] = rand() % 100;
        cout << "Сгенерировано " << n << " случайных чисел.\n";
    }

    cout << "\nИсходный вектор: ";
    copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Сортировка по возрастанию
    sort(V.begin(), V.end());

    cout << "Отсортированный вектор: ";
    copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Три конечных элемента в порядке убывания
    cout << "Три конечных элемента в порядке убывания: ";
    auto it = V.rbegin();
    for (int i = 0; i < 3 && it != V.rend(); ++i, ++it)
        cout << *it << " ";
    cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get(); cin.get();
}
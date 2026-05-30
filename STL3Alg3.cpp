#include "STL3Alg3.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include "validation.h"

void STL3Alg3() {
    using namespace std;

    list<int> L;
    int choice;
    cout << "\n--- STL3Alg3: удалить первый и последний нулевой элемент списка ---\n";
    cout << "Выберите способ заполнения списка:\n";
    cout << "1 - С клавиатуры\n2 - Из файла\n3 - Случайно\n";
    choice = Validation::getIntRange("Ваш выбор: ", 1, 3);

    if (choice == 1) {
        int n = Validation::getIntMin("Количество элементов: ", 1);
        cout << "Введите " << n << " чисел:\n";
        for (int i = 0; i < n; ++i) {
            cout << "  Элемент " << i + 1 << ": ";
            L.push_back(Validation::getInt());
        }
    }
    else if (choice == 2) {
        string fname = Validation::getValidFile();
        ifstream f(fname);
        int x;
        while (f >> x) L.push_back(x);
        f.close();
        cout << "Загружено " << L.size() << " чисел.\n";
    }
    else {
        int n = Validation::getIntMin("Количество элементов: ", 1);
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

    // Находим первый ноль
    auto firstZero = find(L.begin(), L.end(), 0);
    // Находим последний ноль (прямым обходом)
    auto lastZero = L.end();
    for (auto it = L.begin(); it != L.end(); ++it) {
        if (*it == 0) lastZero = it;
    }

    if (firstZero == L.end() && lastZero == L.end()) {
        cout << "Нулевых элементов нет. Список не изменён.\n";
    }
    else if (firstZero != L.end() && lastZero != L.end()) {
        if (firstZero == lastZero) {
            L.erase(firstZero);
            cout << "Удалён единственный нулевой элемент.\n";
        }
        else {
            // Удаляем последний ноль (чтобы не сместить первый)
            L.erase(lastZero);
            // Затем удаляем первый ноль (он мог остаться на месте)
            firstZero = find(L.begin(), L.end(), 0);
            if (firstZero != L.end())
                L.erase(firstZero);
            cout << "Удалены первый и последний нулевые элементы.\n";
        }
    }
    else if (firstZero != L.end()) {
        L.erase(firstZero);
        cout << "Удалён первый (и единственный) нулевой элемент.\n";
    }
    else {
        L.erase(lastZero);
        cout << "Удалён последний (и единственный) нулевой элемент.\n";
    }

    cout << "Результат: ";
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get(); cin.get();
}
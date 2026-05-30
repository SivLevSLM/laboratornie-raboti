#include "STL2Seq7.h"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>
#include "validation.h"

void STL2Seq7() {
    using namespace std;
    vector<int> V;
    int n = Validation::getIntMin("Вектор: чётное количество элементов (>=2): ", 2);
    while (n % 2 != 0)
        n = Validation::getIntMin("Ошибка! Введите чётное число: ", 2);
    cout << "Введите " << n << " чисел:\n";
    for (int i = 0; i < n; ++i) {
        cout << "  Элемент " << i + 1 << ": ";
        V.push_back(Validation::getInt());
    }
    deque<int> D;
    n = Validation::getIntMin("Дек: чётное количество элементов (>=2): ", 2);
    while (n % 2 != 0)
        n = Validation::getIntMin("Ошибка! Введите чётное число: ", 2);
    cout << "Введите " << n << " чисел:\n";
    for (int i = 0; i < n; ++i) {
        cout << "  Элемент " << i + 1 << ": ";
        D.push_back(Validation::getInt());
    }

    // ========== Список ==========
    list<int> L;
    n = Validation::getIntMin("Список: чётное количество элементов (>=2): ", 2);
    while (n % 2 != 0)
        n = Validation::getIntMin("Ошибка! Введите чётное число: ", 2);
    cout << "Введите " << n << " чисел:\n";
    for (int i = 0; i < n; ++i) {
        cout << "  Элемент " << i + 1 << ": ";
        L.push_back(Validation::getInt());
    }

    cout << "\nИсходные данные:\n";
    cout << "Вектор V: "; copy(V.begin(), V.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    cout << "Дек D: "; copy(D.begin(), D.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    cout << "Список L: "; copy(L.begin(), L.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    size_t mid = V.size() / 2;
    swap(V[mid - 1], V[mid]);

    mid = D.size() / 2;
    swap(D[mid - 1], D[mid]);

    auto it = L.begin();
    advance(it, L.size() / 2 - 1);
    auto it2 = it; ++it2;
    swap(*it, *it2);

    cout << "\nПосле замены двух средних элементов:\n";
    cout << "Вектор V: "; copy(V.begin(), V.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    cout << "Дек D: "; copy(D.begin(), D.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    cout << "Список L: "; copy(L.begin(), L.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get(); cin.get();
}
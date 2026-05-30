#include "STL2Seq24.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "validation.h"

void STL2Seq24() {
    using namespace std;

    list<int> L1;
    int n = Validation::getIntMin("L1: количество элементов (нечётное, >=1): ", 1);
    while (n % 2 == 0)
        n = Validation::getIntMin("Ошибка! Введите нечётное число: ", 1);
    cout << "Введите " << n << " чисел:\n";
    for (int i = 0; i < n; ++i) {
        cout << "  Элемент " << i + 1 << ": ";
        L1.push_back(Validation::getInt());
    }

    list<int> L2;
    n = Validation::getIntMin("L2: количество элементов (>=0): ", 0);
    cout << "Введите " << n << " чисел:\n";
    for (int i = 0; i < n; ++i) {
        cout << "  Элемент " << i + 1 << ": ";
        L2.push_back(Validation::getInt());
    }

    cout << "\nИсходные данные:\n";
    cout << "L1: "; copy(L1.begin(), L1.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    cout << "L2: "; copy(L2.begin(), L2.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    auto mid = L1.begin();
    advance(mid, L1.size() / 2);

    L2.splice(L2.end(), L1, mid);

    cout << "\nПосле перемещения среднего элемента L1 в конец L2:\n";
    cout << "L1: "; copy(L1.begin(), L1.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    cout << "L2: "; copy(L2.begin(), L2.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get(); cin.get();
}
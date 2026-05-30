#include "STL2Seq12.h"
#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>
#include "validation.h"

void STL2Seq12() {
    using namespace std;

    // Дек D
    deque<int> D;
    int n = Validation::getIntMin("Дек: количество элементов (>=5): ", 5);
    cout << "Введите " << n << " чисел:\n";
    for (int i = 0; i < n; ++i) {
        cout << "  Элемент " << i + 1 << ": ";
        D.push_back(Validation::getInt());
    }

    // Список L
    list<int> L;
    n = Validation::getIntMin("Список: количество элементов (>=5): ", 5);
    cout << "Введите " << n << " чисел:\n";
    for (int i = 0; i < n; ++i) {
        cout << "  Элемент " << i + 1 << ": ";
        L.push_back(Validation::getInt());
    }

    cout << "\nИсходные данные:\n";
    cout << "Дек D: "; copy(D.begin(), D.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    cout << "Список L: "; copy(L.begin(), L.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    // Последние 5 элементов дека D в обратном порядке
    deque<int> last5;
    auto rit = D.rbegin();
    for (int i = 0; i < 5 && rit != D.rend(); ++i, ++rit)
        last5.push_back(*rit);
    reverse(last5.begin(), last5.end());

    auto pos = L.end();
    advance(pos, -5);
    L.insert(pos, last5.begin(), last5.end());

    cout << "\nРезультат (последние 5 элементов дека в обратном порядке вставлены перед 5-м с конца элементом списка):\n";
    cout << "Список L: "; copy(L.begin(), L.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get(); cin.get();
}
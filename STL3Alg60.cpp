#include "STL3Alg60.h"
#include <iostream>
#include <list>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iomanip>
#include "validation.h"

class Average {
public:
    double operator()(int a, int b) const {
        return (a + b) / 2.0;
    }
};

void STL3Alg60() {
    using namespace std;

    list<int> L;
    int choice;
    cout << "\n--- STL3Alg60: средние арифметические соседних элементов ---\n";
    cout << "Выберите способ заполнения списка (минимум 2 элемента):\n";
    cout << "1 - С клавиатуры\n2 - Из файла\n3 - Случайно\n";
    choice = Validation::getIntRange("Ваш выбор: ", 1, 3);

    if (choice == 1) {
        int n = Validation::getIntMin("Количество элементов (>=2): ", 2);
        cout << "Введите " << n << " чисел:\n";
        for (int i = 0; i < n; ++i) {
            cout << "  Элемент " << i + 1 << ": ";
            L.push_back(Validation::getInt());
        }
    }
    else if (choice == 2) {
        string fname = Validation::getValidFile();
        ifstream f(fname);
        list<int> temp((istream_iterator<int>(f)), istream_iterator<int>());
        f.close();
        if (temp.size() < 2) {
            cout << "Ошибка! В файле менее 2 чисел.\n";
            return;
        }
        L = temp;
        cout << "Загружено " << L.size() << " чисел.\n";
    }
    else {
        int n = Validation::getIntMin("Количество элементов (>=2): ", 2);
        for (int i = 0; i < n; ++i)
            L.push_back(rand() % 100);
        cout << "Сгенерировано " << n << " чисел.\n";
    }

    if (L.size() < 2) {
        cout << "Список слишком мал!\n";
        return;
    }

    cout << "\nИсходный список: ";
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<double> V;
    adjacent_difference(L.begin(), L.end(), back_inserter(V), Average());
    V.erase(V.begin()); // удаляем первый элемент (копию первого числа)

    cout << fixed << setprecision(1);
    cout << "Средние арифметические соседних элементов: ";
    copy(V.begin(), V.end(), ostream_iterator<double>(cout, " "));
    cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get(); cin.get();
}
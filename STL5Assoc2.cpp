#include "STL5Assoc2.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "validation.h"

void STL5Assoc2() {
    using namespace std;
    srand(static_cast<unsigned>(time(nullptr)));

    // ========== Ввод V0 ==========
    vector<int> V0;
    cout << "\n--- Заполнение эталонного вектора V0 ---\n";
    cout << "Выберите способ заполнения:\n";
    cout << "1 - С клавиатуры\n2 - Из файла\n3 - Случайно\n";
    int choice = Validation::getIntRange("Ваш выбор: ", 1, 3);

    if (choice == 1) {
        int n = Validation::getIntMin("Количество элементов: ", 1);
        cout << "Введите " << n << " чисел:\n";
        V0.resize(n);
        for (int i = 0; i < n; ++i) {
            cout << "  Элемент " << i + 1 << ": ";
            V0[i] = Validation::getInt();
        }
    }
    else if (choice == 2) {
        string fname = Validation::getValidFile();
        ifstream f(fname);
        V0.assign((istream_iterator<int>(f)), istream_iterator<int>());
        f.close();
        cout << "Загружено " << V0.size() << " чисел.\n";
    }
    else {
        int n = Validation::getIntMin("Количество элементов: ", 1);
        V0.resize(n);
        for (int i = 0; i < n; ++i)
            V0[i] = rand() % 201 - 100;
        cout << "Сгенерировано " << n << " чисел.\n";
    }

    if (V0.empty()) {
        cout << "V0 пуст!\n";
        return;
    }

    set<int> setV0(V0.begin(), V0.end());
    cout << "\nV0: "; copy(V0.begin(), V0.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    cout << "Уникальные элементы V0: "; copy(setV0.begin(), setV0.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    // ========== Ввод количества векторов Vi ==========
    int N = Validation::getIntMin("Введите количество векторов N: ", 1);
    int count = 0;

    for (int i = 1; i <= N; ++i) {
        cout << "\n--- Заполнение вектора V" << i << " ---\n";
        cout << "Выберите способ заполнения:\n";
        cout << "1 - С клавиатуры\n2 - Из файла\n3 - Случайно\n";
        int ch = Validation::getIntRange("Ваш выбор: ", 1, 3);

        vector<int> Vi;
        if (ch == 1) {
            int n = Validation::getIntMin("Количество элементов (>= " + to_string(setV0.size()) + "): ", setV0.size());
            cout << "Введите " << n << " чисел:\n";
            Vi.resize(n);
            for (int j = 0; j < n; ++j) {
                cout << "  Элемент " << j + 1 << ": ";
                Vi[j] = Validation::getInt();
            }
        }
        else if (ch == 2) {
            string fname = Validation::getValidFile();
            ifstream f(fname);
            Vi.assign((istream_iterator<int>(f)), istream_iterator<int>());
            f.close();
            if (Vi.size() < setV0.size()) {
                cout << "Ошибка! В файле меньше " << setV0.size() << " элементов.\n";
                continue;
            }
            cout << "Загружено " << Vi.size() << " чисел.\n";
        }
        else {
            int n = Validation::getIntMin("Количество элементов (>= " + to_string(setV0.size()) + "): ", setV0.size());
            Vi.resize(n);
            for (int j = 0; j < n; ++j)
                Vi[j] = rand() % 201 - 100;
            cout << "Сгенерировано " << n << " чисел.\n";
        }

        if (Vi.empty()) continue;

        cout << "V" << i << ": "; copy(Vi.begin(), Vi.end(), ostream_iterator<int>(cout, " ")); cout << endl;

        set<int> setVi(Vi.begin(), Vi.end());
        if (includes(setVi.begin(), setVi.end(), setV0.begin(), setV0.end())) {
            ++count;
            cout << "--> V" << i << " содержит все элементы V0\n";
        }
        else {
            cout << "--> V" << i << " НЕ содержит все элементы V0\n";
        }
    }

    cout << "\nРезультат: " << count << " векторов содержат все элементы V0\n";

    cout << "\nНажмите Enter для продолжения...";
    cin.get(); cin.get();
}
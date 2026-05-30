#include "STL1Iter15.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "validation.h"

void STL1Iter15() {
    using namespace std;

    vector<int> numbers;
    int n = Validation::getIntMin("Введите количество чисел: ", 1);
    cout << "Введите " << n << " целых чисел:\n";
    for (int i = 0; i < n; ++i) {
        cout << "  Число " << i + 1 << ": ";
        numbers.push_back(Validation::getInt());
    }

    string name;
    cout << "Введите имя выходного файла: ";
    cin >> name;

    ofstream out(name);
    if (!out) {
        cerr << "Ошибка создания файла!\n";
        return;
    }

    // replace_copy: копируем в out, заменяя 0 на 10, разделитель – два пробела
    replace_copy(numbers.begin(), numbers.end(),
        ostream_iterator<int>(out, "  "), 0, 10);
    out.close();

    cout << "Результат записан в файл " << name << endl;

    // Вывод на экран для наглядности
    cout << "Исходные числа: ";
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout << "\nПосле замены 0 -> 10: ";
    replace_copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, "  "), 0, 10);
    cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get(); cin.get();
}
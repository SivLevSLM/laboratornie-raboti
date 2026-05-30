#include "STL5Assoc17.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cctype>
#include "validation.h"

bool isUpperWord(const std::string& word) {
    if (word.empty()) return false;
    for (char c : word)
        if (c < 'A' || c > 'Z') return false;
    return true;
}

void STL5Assoc17() {
    using namespace std;
    srand(static_cast<unsigned>(time(nullptr)));

    vector<string> V;
    cout << "\n--- Заполнение вектора слов (заглавные латинские буквы) ---\n";
    cout << "Выберите способ заполнения:\n";
    cout << "1 - С клавиатуры\n2 - Из файла\n3 - Случайно\n";
    int choice = Validation::getIntRange("Ваш выбор: ", 1, 3);

    if (choice == 1) {
        int n = Validation::getIntMin("Количество слов: ", 1);
        cout << "Введите " << n << " слов заглавными латинскими буквами:\n";
        for (int i = 0; i < n; ++i) {
            string word;
            cout << "  Слово " << i + 1 << ": ";
            cin >> word;
            while (!isUpperWord(word)) {
                cout << "Ошибка! Только заглавные латинские буквы (A-Z): ";
                cin >> word;
            }
            V.push_back(word);
        }
    }
    else if (choice == 2) {
        string fname = Validation::getValidFile();
        ifstream f(fname);
        string word;
        bool allUpper = true;
        while (f >> word) {
            if (!isUpperWord(word)) {
                allUpper = false;
                break;
            }
            V.push_back(word);
        }
        f.close();
        if (!allUpper) {
            cout << "Ошибка! Файл содержит недопустимые символы.\n";
            return;
        }
        cout << "Загружено " << V.size() << " слов.\n";
    }
    else {
        int n = Validation::getIntMin("Количество слов: ", 1);
        for (int i = 0; i < n; ++i) {
            int len = rand() % 10 + 3;
            string word;
            for (int j = 0; j < len; ++j)
                word += 'A' + rand() % 26;
            V.push_back(word);
        }
        cout << "Сгенерировано " << n << " слов.\n";
    }

    if (V.empty()) {
        cout << "Вектор пуст!\n";
        return;
    }

    cout << "\nИсходные слова: ";
    copy(V.begin(), V.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    map<char, int> M;
    for (const string& w : V) {
        M[w[0]] += w.size();
    }

    cout << "\nРезультат (буква - суммарная длина слов):\n";
    for (const auto& p : M) {
        cout << p.first << " - " << p.second << endl;
    }

    cout << "\nНажмите Enter для продолжения...";
    cin.get(); cin.get();
}
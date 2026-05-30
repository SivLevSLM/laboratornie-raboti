#include <iostream>
#include "ListWork60.h"
#include "list.h"

void ListWork60() {
    using namespace std;

    LinkedList list;

    cout << "Заполнение упорядоченного списка (все значения по возрастанию)." << endl;
    cout << "Выберите способ:" << endl;
    cout << "1 - ввести значения с клавиатуры (только по возрастанию!)" << endl;
    cout << "2 - загрузить из файла (только по возрастанию!)" << endl;
    cout << "3 - сгенерировать случайно по возрастанию" << endl;
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        int n, val;
        cout << "Введите количество элементов: ";
        cin >> n;
        cout << "Введите " << n << " чисел в порядке возрастания:" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> val;
            list.append(val);
        }
    }
    else if (choice == 2) {
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        list.fillFromFile(filename);
    }
    else if (choice == 3) {
        int n;
        cout << "Введите количество элементов: ";
        cin >> n;
        int current = 0;
        for (int i = 0; i < n; ++i) {
            current += rand() % 10 + 1;
            list.append(current);
        }
    }
    else {
        cout << "Неверный выбор." << endl;
        return;
    }

    if (list.isEmpty()) {
        cout << "Список пуст. Операция невозможна." << endl;
        return;
    }

    cout << "\nИсходный список: ";
    list.print();
    Node* P1_original = list.getHead();

    int M;
    cout << "Введите значение M для вставки в новый список: ";
    cin >> M;

    cout << "\nСоздаем копию исходного списка..." << endl;
    LinkedList listCopy = list;

    cout << "Копия списка (до вставки M): ";
    listCopy.print();

    cout << "Вставляем M = " << M << " в копию с сохранением упорядоченности..." << endl;
    listCopy.insertSorted(M);

    Node* P2 = listCopy.getHead();

    cout << "\nРезультат:" << endl;
    cout << "Оригинальный список (не изменился): ";
    list.print();
    cout << "P1 (голова оригинала): " << P1_original
        << ", значение: " << (P1_original ? P1_original->data : 0) << endl;

    cout << "Новый список с M: ";
    listCopy.print();
    cout << "P2 (голова нового списка): " << P2
        << ", значение: " << (P2 ? P2->data : 0) << endl;

    cout << "\nВведите число для поиска в новом списке: ";
    int n;
    cin >> n;
    listCopy.find(n);
}
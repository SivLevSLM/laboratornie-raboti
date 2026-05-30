#include <iostream>
#include "ListWork13.h"
#include "list.h"

void ListWork13() {
    using namespace std;

    LinkedList list;

    cout << "Выберите способ создания списка:" << endl;
    cout << "1 - с клавиатуры" << endl;
    cout << "2 - из файла" << endl;
    cout << "3 - случайно" << endl;
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        list.fillFromKeyboard();
        break;
    case 2: {
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        list.fillFromFile(filename);
        break;
    }
    case 3: {
        int n;
        cout << "Введите количество элементов: ";
        cin >> n;
        list.fillRandom(n);
        list.append(3); // гарантируем наличие элемента, кратного 3
        break;
    }
    default:
        cout << "Неверный выбор." << endl;
        return;
    }

    Node* P1 = list.getHead();
    if (!P1) {
        cout << "Список пуст. Операция невозможна." << endl;
        return;
    }

    cout << "\nИсходный список: ";
    list.print();
    cout << "P1 (голова списка): " << P1 << " (значение: " << P1->data << ")" << endl;

    cout << "\nЭлементы, кратные 3:" << endl;
    Node* current = list.getHead();
    int position = 1;
    bool found = false;

    while (current) {
        if (current->data % 3 == 0) {
            cout << "Позиция: " << position << ", Адрес: " << current
                << ", Значение: " << current->data << endl;
            found = true;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        cout << "В списке нет элементов, кратных 3 (нарушено условие задачи)." << endl;
    }

    cout << "\nДемонстрация поиска по значению:" << endl;
    cout << "Введите число для поиска: ";
    int n;
    cin >> n;
    list.find(n);
    cout << endl;

    cout << "Демонстрация копирования:" << endl;
    LinkedList listCopy = list;
    cout << "Оригинальный список: ";
    list.print();
    cout << "Копия списка: ";
    listCopy.print();

    cout << "\nИзменяем оригинал (добавляем '1337' в конец)..." << endl;
    list.append(1337);
    cout << "Оригинал после изменения: ";
    list.print();
    cout << "Копия не изменилась: ";
    listCopy.print();
}
#include <iostream>
#include "ListWork22.h"
#include "list.h"

void ListWork22() {
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
        break;
    }
    default:
        cout << "Неверный выбор" << endl;
        return;
    }

    if (list.isEmpty()) {
        cout << "Список пуст. Операция невозможна." << endl;
        return;
    }

    int M;
    cout << "\nВведите значение M для вставки: ";
    cin >> M;

    Node* P1 = list.getHead();
    cout << "\nИсходный список:" << endl;
    list.print();
    cout << "P1 (адрес головы): " << P1
        << ", значение первого элемента: " << (P1 ? P1->data : 0) << endl;

    // Вставка после каждого ВТОРОГО элемента
    list.insertAfterEveryK(2, M);

    Node* P2 = list.getLastNode();

    cout << "\nРезультирующий список:" << endl;
    list.print();
    cout << "P2 (адрес последнего элемента): " << P2
        << ", значение: " << (P2 ? P2->data : 0) << endl;

    cout << "\nДемонстрация поиска: ";
    cout << "Введите число для поиска: ";
    int n;
    cin >> n;
    list.find(n);

    cout << "\nДемонстрация копирования:" << endl;
    LinkedList listCopy = list;
    cout << "Оригинал: ";
    list.print();
    cout << "Копия: ";
    listCopy.print();

    cout << "Изменяем оригинал (добавляем 6752)..." << endl;
    list.append(6752);
    cout << "Оригинал после изменения: ";
    list.print();
    cout << "Копия не изменилась: ";
    listCopy.print();
}
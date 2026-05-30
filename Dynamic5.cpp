#include <iostream>
#include "Dynamic5.h"
#include "stack.h"

void Dynamic5() {
    using namespace std;

    Stack stack;

    cout << "Выберите способ создания стека:" << endl;
    cout << "1 - с клавиатуры" << endl;
    cout << "2 - из файла" << endl;
    cout << "3 - случайно" << endl;
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        stack.fillFromKeyboard();
        break;
    case 2: {
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        stack.fillFromFile(filename);
        break;
    }
    case 3: {
        int n;
        cout << "Введите количество элементов: ";
        cin >> n;
        stack.fillRandom(n);
        break;
    }
    default:
        cout << "Неверный выбор. Создан пустой стек." << endl;
        return;
    }

    if (stack.isEmpty()) {
        cout << "ОШИБКА: стек должен быть непустым!" << endl;
        return;
    }

    cout << "\nИсходный ";
    stack.print();

    Node* P1 = stack.getTop();
    cout << "P1 (адрес вершины ДО извлечения): " << P1 << endl;

    int D = stack.pop();

    Node* P2 = stack.getTop();

    cout << "\nРезультат:" << endl;
    cout << "Извлеченное значение D = " << D << endl;
    cout << "P2 (адрес новой вершины): " << P2;

    if (P2 == nullptr) {
        cout << " (стек стал пустым)";
    }
    else {
        cout << ", значение новой вершины: " << stack.peek();
    }
    cout << endl;

    cout << "\nПосле извлечения ";
    stack.print();

    cout << "\nВведите число которое нужно найти: ";
    int n;
    cin >> n;
    stack.find(n);
    cout << endl;

    cout << "Демонстрация копирования" << endl;
    cout << "Создаем копию стека:" << endl;

    Stack stackCopy = stack;

    cout << "Оригинальный стек: ";
    stack.print();
    cout << "Копия стека: ";
    stackCopy.print();

    cout << "\nИзменяем оригинал (удаляем верхний элемент)" << endl;
    stack.pop();

    cout << "Оригинальный стек (изменился): ";
    stack.print();
    cout << "Копия стека (не изменилась): ";
    stackCopy.print();
    cout << endl;
}
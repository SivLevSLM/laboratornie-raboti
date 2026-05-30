#include <iostream>
#include <sstream>   
#include <string>   
#include "Dynamic27.h"
#include "stack.h"

template<typename T>
std::string toString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

void Dynamic27() {
    using namespace std;

    Stack stack1, stack2;

    cout << "Заполнение первого стека" << endl;
    cout << "Выберите способ:" << endl;
    cout << "1 - с клавиатуры" << endl;
    cout << "2 - из файла" << endl;
    cout << "3 - случайно" << endl;
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        stack1.fillFromKeyboard();
        break;
    case 2: {
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        stack1.fillFromFile(filename);
        break;
    }
    case 3: {
        int n;
        cout << "Введите количество элементов: ";
        cin >> n;
        stack1.fillRandom(n);
        break;
    }
    default:
        cout << "Неверный выбор. Стек останется пустым." << endl;
        break;
    }

    cout << "\nЗаполнение второго стека (случайными числами)" << endl;
    stack2.fillRandom(3);

    if (stack1.isEmpty() || stack2.isEmpty()) {
        cout << "\nОШИБКА: Для выполнения задачи оба стека должны быть непустыми." << endl;
        return;
    }

    Node* P1_start = stack1.getTop();
    Node* P2_start = stack2.getTop();

    cout << "\nИсходное состояние:" << endl;
    cout << "Первый стек (вершина -> дно): ";
    stack1.print();
    cout << "P1 (вершина первого стека): " << P1_start << " (значение: " << P1_start->data << ")" << endl;

    cout << "Второй стек (вершина -> дно): ";
    stack2.print();
    cout << "P2 (вершина второго стека): " << P2_start << " (значение: " << P2_start->data << ")" << endl;

    cout << "\nПеремещаем элементы из первого стека во второй, пока не встретится четное..." << endl;

    while (!stack1.isEmpty()) {
        int topValue = stack1.peek();
        int movedValue = stack1.pop();
        stack2.push(movedValue);
        cout << "Перемещено значение: " << movedValue << " из стека 1 в стек 2." << endl;
        if (topValue % 2 == 0) {
            cout << "Найдено четное значение (" << topValue << "). Остановка." << endl;
            break;
        }
    }

    if (stack1.isEmpty()) {
        cout << "Первый стек опустел в процессе перемещения." << endl;
    }

    Node* new_P1 = stack1.getTop();
    Node* new_P2 = stack2.getTop();

    cout << "\nРезультирующее состояние:" << endl;
    cout << "Первый стек (вершина -> дно): ";
    stack1.print();
    cout << "Новый P1 (вершина первого стека): "
        << (new_P1 ? toString(new_P1->data) : "nullptr") << endl;

    cout << "Второй стек (вершина -> дно): ";
    stack2.print();
    cout << "Новый P2 (вершина второго стека): "
        << (new_P2 ? toString(new_P2->data) : "nullptr") << endl;
}
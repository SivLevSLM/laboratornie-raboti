#include "ListWork42.h"
#include "CircularDlist.h"
#include "validation.h"
#include <fstream>
#include <vector>

void ListWork42() {
    using namespace std;
    CircularDoubleList list;
    int choice;
    cout << "\n--- ListWork42 (удаление элементов с равными соседями) ---\n";
    cout << "1 - С клавиатуры\n2 - Из файла\n3 - Случайно\nВыбор: ";
    choice = Validation::getIntRange(1, 3);

    if (choice == 1) {
        int n = Validation::getIntMin("Количество элементов (>=2): ", 2);
        cout << "Введите " << n << " чисел:\n";
        for (int i = 0; i < n; ++i) {
            cout << "  Элемент " << i + 1 << ": ";
            list.append(Validation::getInt());
        }
    }
    else if (choice == 2) {
        string fname = Validation::getValidFile();
        ifstream f(fname);
        int x;
        while (f >> x) list.append(x);
        f.close();
        cout << "Загружено из файла.\n";
    }
    else {
        int n = Validation::getIntMin("Количество элементов (>=2): ", 2);
        list.fillRandom(n);
        cout << "Сгенерировано " << n << " чисел.\n";
    }

    if (list.isEmpty()) {
        cout << "Список пуст!\n";
        return;
    }

    DNode* P1 = list.getHead();
    cout << "\nИсходный список: ";
    list.print();
    cout << "P1 (адрес первого): " << P1;
    if (P1) cout << ", значение: " << P1->data;
    cout << endl;

    // Копия
    cout << "\nСоздаём копию списка.\n";
    CircularDoubleList listCopy = list;

    // Обработка
    cout << "\nВыполняем удаление...\n";
    DNode* lastElement = list.removeIfNeighborsEqual();

    cout << "\nРезультат: ";
    list.print();
    cout << "Указатель на последний элемент: " << lastElement;
    if (lastElement) cout << ", значение: " << lastElement->data;
    cout << endl;

    // Демонстрация копии
    cout << "\nДемонстрация копии:\n";
    cout << "Оригинал: "; list.print();
    cout << "Копия: "; listCopy.print();
    listCopy.append(6752);
    cout << "Копия после добавления 6752: "; listCopy.print();

    cout << "\nПоиск в копии: ";
    int x = Validation::getInt("Введите число: ");
    listCopy.find(x);

    cout << "\nНажмите Enter...";
    cin.get(); cin.get();
}
#include "ListWork67.h"
#include "list.h"
#include "validation.h"
#include <fstream>
#include <vector>

void ListWork67() {
    using namespace std;
    CircularList list;
    int choice;
    cout << "\n--- ListWork67 (шаг 2) ---\n";
    cout << "1 - С клавиатуры\n2 - Из файла\n3 - Случайно\nВыбор: ";
    choice = Validation::getIntRange(1, 3);

    if (choice == 1) {
        int n = Validation::getIntMin("Количество элементов: ", 1);
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
        int n = Validation::getIntMin("Количество элементов: ", 1);
        list.fillRandom(n);
        cout << "Сгенерировано " << n << " чисел.\n";
    }

    if (list.isEmpty()) {
        cout << "Список пуст!\n";
        return;
    }

    Node* P1 = list.getHead();
    cout << "\nИсходный список: ";
    list.print();
    cout << "P1 (адрес первого): " << P1;
    if (P1) cout << ", значение: " << P1->data;
    cout << endl;

    // Копия до обработки
    cout << "\nСоздаём копию списка.\n";
    CircularList listCopy = list;

    string filename = "listwork67_result.txt";
    cout << "Результат будет сохранён в " << filename << endl;
    list.processWithStepToFile(2, filename);

    cout << "\nДемонстрация копии:\n";
    cout << "Оригинал после обработки: "; list.print();
    cout << "Копия (до обработки): "; listCopy.print();

    cout << "\nДобавляем 6752 в копию:\n";
    listCopy.append(6752);
    cout << "Оригинал: "; list.print();
    cout << "Копия: "; listCopy.print();

    cout << "\nПоиск в копии: ";
    int x = Validation::getInt("Введите число: ");
    listCopy.find(x);

    cout << "\nНажмите Enter...";
    cin.get(); cin.get();
}
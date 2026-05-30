#include "ListWork46.h"
#include "LinearDoubleList.h"
#include "validation.h"
#include <fstream>

DNode* ConvertToCircularWithBarrier(LinearDoubleList& list) {
    DNode* first = list.getFirst();
    DNode* last = list.getLast();
    DNode* barrier = new DNode(0);
    if (list.isEmpty()) {
        barrier->next = barrier;
        barrier->prev = barrier;
    }
    else {
        barrier->next = first;
        barrier->prev = last;
        first->prev = barrier;
        last->next = barrier;
    }
    return barrier;
}

void ListWork46() {
    using namespace std;
    LinearDoubleList list;
    int choice;
    cout << "\n--- ListWork46 (преобразование в циклический с барьером) ---\n";
    cout << "1 - С клавиатуры\n2 - Из файла\n3 - Случайно (может быть 0)\nВыбор: ";
    choice = Validation::getIntRange(1, 3);

    if (choice == 1) {
        int n = Validation::getIntMin("Количество элементов (0 - пустой): ", 0);
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
        int n = Validation::getIntRange("Количество элементов (0-15): ", 0, 15);
        list.fillRandom(n);
        cout << "Сгенерировано " << n << " чисел.\n";
    }

    cout << "\nИсходный линейный список: ";
    list.print();

    // Копия
    LinearDoubleList listCopy = list;

    // Преобразование
    DNode* barrier = ConvertToCircularWithBarrier(list);

    cout << "\nРезультат преобразования:\n";
    cout << "Барьерный элемент: " << barrier << ", значение " << barrier->data << "\n";
    if (list.isEmpty()) {
        cout << "Список был пуст: barrier->next = barrier, barrier->prev = barrier\n";
    }
    else {
        cout << "barrier->next = " << barrier->next << " (значение " << barrier->next->data << ")\n";
        cout << "barrier->prev = " << barrier->prev << " (значение " << barrier->prev->data << ")\n";
        cout << "Обход циклического списка: ";
        DNode* cur = barrier->next;
        int cnt = 0;
        while (cur != barrier && cnt < 20) {
            cout << cur->data << " ";
            cur = cur->next; ++cnt;
        }
        cout << "...\n";
    }

    // Очистка памяти
    if (barrier->next != barrier) {
        DNode* cur = barrier->next;
        while (cur != barrier) {
            DNode* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
    delete barrier;
    cout << "Память очищена.\n";

    // Демонстрация копии
    cout << "\nДемонстрация копии (независимость):\n";
    cout << "Копия исходного списка: "; listCopy.print();
    listCopy.append(777);
    cout << "После добавления 777 в копию: "; listCopy.print();

    cout << "\nПоиск в копии: ";
    int x = Validation::getInt("Введите число: ");
    listCopy.find(x);

    cout << "\nНажмите Enter...";
    cin.get(); cin.get();
}
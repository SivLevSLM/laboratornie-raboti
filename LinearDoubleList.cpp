#include "LinearDoubleList.h"
#include <cstdlib>

LinearDoubleList::LinearDoubleList() : first(nullptr), last(nullptr) {}

LinearDoubleList::LinearDoubleList(const LinearDoubleList& other) : first(nullptr), last(nullptr) {
    DNode* cur = other.first;
    while (cur) {
        append(cur->data);
        cur = cur->next;
    }
    std::cout << "Конструктор копирования LinearDoubleList\n";
}

LinearDoubleList::~LinearDoubleList() {
    clear();
}

void LinearDoubleList::clear() {
    DNode* cur = first;
    while (cur) {
        DNode* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    first = last = nullptr;
}

void LinearDoubleList::append(int val) {
    DNode* newNode = new DNode(val);
    if (isEmpty()) {
        first = last = newNode;
    }
    else {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
}

bool LinearDoubleList::isEmpty() const {
    return first == nullptr;
}

void LinearDoubleList::print() const {
    if (isEmpty()) {
        std::cout << "(пусто)\n";
        return;
    }
    DNode* cur = first;
    while (cur) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

void LinearDoubleList::find(int val) const {
    if (isEmpty()) {
        std::cout << "Список пуст\n";
        return;
    }
    DNode* cur = first;
    int pos = 1;
    while (cur) {
        if (cur->data == val) {
            std::cout << "Найдено: позиция " << pos << ", адрес " << cur << std::endl;
            return;
        }
        cur = cur->next;
        ++pos;
    }
    std::cout << "Не найдено\n";
}

void LinearDoubleList::fillRandom(int count) {
    for (int i = 0; i < count; ++i)
        append(rand() % 100);
}

void LinearDoubleList::reversePrintAndDeleteToFile(const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return;
    }
    if (isEmpty()) {
        out << "Список пуст\n";
        out.close();
        return;
    }
    out << "Исходный список: ";
    DNode* cur = first;
    while (cur) {
        out << cur->data << " ";
        cur = cur->next;
    }
    out << "\nОбратный порядок: ";
    while (!isEmpty()) {
        int val = last->data;
        out << val << " ";
        if (first == last) {
            delete first;
            first = last = nullptr;
        }
        else {
            DNode* prev = last->prev;
            prev->next = nullptr;
            delete last;
            last = prev;
        }
    }
    out << "\nВсего удалено элементов: " << (!first ? "все" : "???") << "\n";
    out.close();
}
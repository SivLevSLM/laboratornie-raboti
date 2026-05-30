#include "CircularDlist.h"
#include <cstdlib>
#include <iostream>

CircularDoubleList::CircularDoubleList() : head(nullptr), tail(nullptr) {}

void CircularDoubleList::copyFrom(const CircularDoubleList& other) {
    if (other.head == nullptr) {
        head = tail = nullptr;
        return;
    }
    DNode* cur = other.head;
    head = new DNode(cur->data);
    head->prev = nullptr;
    head->next = nullptr;
    tail = head;

    cur = cur->next;
    while (cur != other.head) {
        DNode* newNode = new DNode(cur->data);
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
        cur = cur->next;
    }
}

CircularDoubleList::CircularDoubleList(const CircularDoubleList& other) {
    copyFrom(other);
    std::cout << "Конструктор копирования CircularDoubleList выполнил глубокое копирование\n";
}

CircularDoubleList::~CircularDoubleList() {
    if (isEmpty()) return;
    tail->next = nullptr;
    head->prev = nullptr;
    DNode* cur = head;
    while (cur) {
        DNode* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    head = tail = nullptr;
}

CircularDoubleList& CircularDoubleList::operator=(const CircularDoubleList& other) {
    if (this != &other) {
        this->~CircularDoubleList();
        copyFrom(other);
    }
    return *this;
}

void CircularDoubleList::append(int val) {
    DNode* newNode = new DNode(val);
    if (isEmpty()) {
        head = tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
}

bool CircularDoubleList::isEmpty() const {
    return head == nullptr;
}

void CircularDoubleList::print() const {
    if (isEmpty()) {
        std::cout << "(пусто)\n";
        return;
    }
    DNode* cur = head;
    do {
        std::cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);
    std::cout << std::endl;
}

void CircularDoubleList::find(int val) const {
    if (isEmpty()) {
        std::cout << "Список пуст\n";
        return;
    }
    DNode* cur = head;
    int pos = 1;
    do {
        if (cur->data == val) {
            std::cout << "Найдено: позиция " << pos << ", адрес " << cur << std::endl;
            return;
        }
        cur = cur->next;
        ++pos;
    } while (cur != head);
    std::cout << "Не найдено\n";
}

void CircularDoubleList::fillRandom(int count) {
    for (int i = 0; i < count; ++i)
        append(rand() % 100);
}

DNode* CircularDoubleList::removeIfNeighborsEqual() {
    if (isEmpty() || head == tail) return tail;

    bool changed;
    do {
        changed = false;
        DNode* cur = head;
        do {
            if (cur->prev->data == cur->next->data) {
                DNode* toDel = cur;
                if (toDel == head) head = head->next;
                if (toDel == tail) tail = tail->prev;
                toDel->prev->next = toDel->next;
                toDel->next->prev = toDel->prev;
                DNode* nextNode = toDel->next;
                delete toDel;
                changed = true;
                cur = nextNode;
                if (head == tail) return head;
            }
            else {
                cur = cur->next;
            }
        } while (cur != head && !isEmpty());
    } while (changed && !isEmpty());

    return tail;
}
#include "list.h"
#include <cstdlib>
#include <vector>

CircularList::CircularList() : head(nullptr) {}

CircularList::CircularList(const CircularList& other) : head(nullptr) {
    if (other.head) {
        Node* cur = other.head;
        do {
            append(cur->data);
            cur = cur->next;
        } while (cur != other.head);
    }
}

CircularList::~CircularList() {
    if (isEmpty()) return;
    Node* cur = head;
    Node* last = head;
    while (last->next != head) last = last->next;
    last->next = nullptr;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    head = nullptr;
}

void CircularList::append(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        head = newNode;
        newNode->next = head;
    }
    else {
        Node* last = head;
        while (last->next != head) last = last->next;
        last->next = newNode;
        newNode->next = head;
    }
}

bool CircularList::isEmpty() const {
    return head == nullptr;
}

void CircularList::print() const {
    if (isEmpty()) {
        std::cout << "(пусто)\n";
        return;
    }
    Node* cur = head;
    do {
        std::cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);
    std::cout << std::endl;
}

void CircularList::find(int val) const {
    if (isEmpty()) {
        std::cout << "Список пуст.\n";
        return;
    }
    Node* cur = head;
    int pos = 1;
    do {
        if (cur->data == val) {
            std::cout << "Элемент " << val << " найден на позиции " << pos
                << ", адрес " << cur << std::endl;
            return;
        }
        cur = cur->next;
        ++pos;
    } while (cur != head);
    std::cout << "Элемент " << val << " не найден.\n";
}

void CircularList::fillRandom(int count) {
    for (int i = 0; i < count; ++i)
        append(rand() % 100);
}

void CircularList::processWithStepToFile(int step, const std::string& filename) {
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
    out << "Результат обработки с шагом " << step << "\n";
    out << "Исходный список: ";
    Node* t = head;
    do {
        out << t->data << " ";
        t = t->next;
    } while (t != head);
    out << "\nПоследовательность удаления: ";

    Node* current = head;
    int stepCount = 1;
    while (!isEmpty()) {
        if (stepCount == 1) {
            current = head;
        }
        else {
            for (int i = 0; i < step; ++i)
                current = current->next;
        }
        int val = current->data;
        out << val << " ";
        if (head->next == head) {
            delete head;
            head = nullptr;
            break;
        }
        Node* prev = head;
        while (prev->next != current) prev = prev->next;
        if (current == head) head = head->next;
        prev->next = current->next;
        delete current;
        current = prev->next;
        ++stepCount;
    }
    out << "\nВсего удалено элементов: " << (stepCount - 1) << "\n";
    out.close();
}
#pragma once
#include "nodes.h"
#include <iostream>

class CircularDoubleList {
private:
    DNode* head;
    DNode* tail;
    void copyFrom(const CircularDoubleList& other);

public:
    CircularDoubleList();
    CircularDoubleList(const CircularDoubleList& other);
    ~CircularDoubleList();

    CircularDoubleList& operator=(const CircularDoubleList& other);

    void append(int val);
    bool isEmpty() const;
    DNode* getHead() const { return head; }
    DNode* getTail() const { return tail; }
    void print() const;
    void find(int val) const;
    void fillRandom(int count);
    DNode* removeIfNeighborsEqual();
};
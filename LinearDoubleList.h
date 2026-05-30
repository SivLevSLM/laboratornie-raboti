#pragma once
#include "nodes.h"
#include <iostream>
#include <fstream>

class LinearDoubleList {
private:
    DNode* first;
    DNode* last;
public:
    LinearDoubleList();
    LinearDoubleList(const LinearDoubleList& other);
    ~LinearDoubleList();
    void append(int val);
    bool isEmpty() const;
    DNode* getFirst() const { return first; }
    DNode* getLast() const { return last; }
    void clear();
    void print() const;
    void find(int val) const;
    void fillRandom(int count);
    void reversePrintAndDeleteToFile(const std::string& filename);
};
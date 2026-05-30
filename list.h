#pragma once
#include "nodes.h"
#include <iostream>
#include <fstream>

class CircularList {
private:
    Node* head;
public:
    CircularList();
    CircularList(const CircularList& other);
    ~CircularList();
    void append(int val);
    bool isEmpty() const;
    Node* getHead() const { return head; }
    void print() const;
    void find(int val) const;
    void fillRandom(int count);
    void processWithStepToFile(int step, const std::string& filename);
};
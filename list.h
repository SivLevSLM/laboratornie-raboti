#pragma once

#include "node.h"
#include <iostream>
#include <fstream>

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    ~LinkedList();

    Node* getNthNode(int n) const;
    void insertAfterEveryK(int k, int val);
    Node* getLastNode() const;
    void insertSorted(int val);

    void append(int val);
    bool isEmpty() const;
    void find(int val) const;
    Node* getHead() const { return head; }
    void fillFromKeyboard();
    void fillFromFile(const std::string& filename);
    void fillRandom(int count);
    void print() const;
};

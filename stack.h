#pragma once

#include "node.h"
#include <iostream>
#include <fstream>

class Stack {
private:
    Node* top;

public:
    Stack();
    Stack(const Stack& other);
    ~Stack();

    void push(int val);
    int pop();
    int peek() const;
    void find(int val) const;
    bool isEmpty() const;
    Node* getTop() const { return top; }

    void fillFromKeyboard();
    void fillFromFile(const std::string& filename);
    void fillRandom(int count);
    void print() const;
};
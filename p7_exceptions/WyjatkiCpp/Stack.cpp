#include "Stack.hpp"

Stack::Stack() {
    this->maxStackSize = 10000;
}

Stack::Stack(int max) {
    this->maxStackSize = max;
}

void Stack::push(int newItem) {
    if(maxStackSize > this->dfs.size()) {
        this->dfs.push_back(newItem);
    } else throw StackFullException("Stack is full", newItem, this->maxStackSize);
}

int Stack::pop() {
    int temp = 0;
    if(!this->dfs.empty()) {
        temp = this->dfs.back();
        return temp;
    } else throw StackEmptyException("Stack is empty!");
}
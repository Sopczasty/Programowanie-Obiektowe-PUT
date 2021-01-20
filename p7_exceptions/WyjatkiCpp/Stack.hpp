#include <iostream>
#include <vector>
#include "StackEmptyException.cpp"
#include "StackFullException.cpp"

class Stack {
private:
    int maxStackSize;
    std::vector<int> dfs;
    int top;
public: 
    Stack();
    Stack(int max);
    void push(int newItem);
    int pop();
};
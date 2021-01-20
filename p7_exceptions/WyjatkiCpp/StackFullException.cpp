#include <iostream>

#include "StackException.cpp"

class StackFullException : public StackException {
    int element = 0;
    int maxStackSize = 0;
    std::string message;
    std::string fullmessage;
public:
    StackFullException() {}
    StackFullException(std::string p, int e, int s) {
        this->element = e;
        this->maxStackSize = s;
        this->message = p;
        this->fullmessage = message + " Element: " + std::to_string(element) + " MaxStackSize: " + std::to_string(maxStackSize);
    }
    virtual const char* what() const noexcept override {
        return this->fullmessage.c_str();
    }
};
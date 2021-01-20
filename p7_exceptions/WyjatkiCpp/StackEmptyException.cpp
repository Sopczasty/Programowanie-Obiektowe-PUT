#include <iostream>
#include <string>

#include "StackException.cpp"

class StackEmptyException : public StackException {
    std::string message;
public:
    StackEmptyException() {}
    StackEmptyException(std::string p) {
        this->message = p;
    }
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};
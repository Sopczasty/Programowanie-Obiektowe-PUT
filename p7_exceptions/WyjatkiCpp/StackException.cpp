#pragma once
#include <iostream>

class StackException : public std::exception {
public:
    StackException() {}
    virtual const char* what() const noexcept override {
        return "Bledna operacja na stosie!";
    }
}; //override method what() from std::exception, w javie wszystkie metody, ktore mozna overwrite'owac sa automatycznie zapisane jako virtual 
//w cpp metoda bez virtual jest static, wiec nie mozna jej overwrite'owac
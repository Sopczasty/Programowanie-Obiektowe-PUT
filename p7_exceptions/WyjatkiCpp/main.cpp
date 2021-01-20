#include <iostream>
#include "Stack.hpp"
#include "StackException.cpp"

void foo(Stack &s) {
    try {
        for(int i = 0; i < 11; ++i)
            s.push(i);
    } catch (StackException e) {
        std::cout << e.what() << std::endl; 
    }
}

void bar(Stack &s) {
    try {
        s.pop();
    } catch (StackException &e) {
        std::cout << e.what() << std::endl;
    }
}

void interaction(Stack &s) {
    std::string choice; 
    bool run;
    int x;
    std::cout << "Dostepne komendy: push, pop, quit" << std::endl; 
    while(run) {
        std::cout << "Podaj komende: ";
            std::cin >> choice;
            if (choice == "push") {
                std::cout << "Podaj liczbe: ";
                std::cin>>x;
                try {
                    s.push(x);
                } catch(StackException &e) {
                    std::cout << e.what() << std::endl;
                } catch(std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
            } else if (choice == "pop") {
                try {
                    s.pop();
                } catch(StackException &e) {
                    std::cout << e.what() << std::endl;
                } catch(std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
            } else if (choice == "quit") {
                run = false;
            }

    }
}

int main() {
    Stack stack(5);
    bar(stack);
    foo(stack);
    bool run = 1;
    std::string choice; 
    int x;

    Stack stacknew(2);
    puts("");  
    interaction(stacknew);

}
#include <iostream>
#include <vector>

class kid {

};


class ul {
    public:
    ul(): amountOfBees(nullptr), x(nullptr), y(nullptr), name(nullptr), Honey(nullptr) { //Konstruktor

    }

    ul(ul &&Ul): amountOfBees(Ul.amountOfBees), x(Ul.x), y(Ul.y), name(Ul.name), Honey(Ul.Honey)  {} // Konstruktor przenoszący

    ul(const ul &Ul): amountOfBees(Ul.amountOfBees), x(Ul.x), y(Ul.y), name(Ul.name), Honey(Ul.Honey) {} // Konstruktor kopiujący

    ~ul() { 
        if(amountOfBees != nullptr) delete(amountOfBees);
        if(x != nullptr) delete(x);
        if(y != nullptr) delete(y);
        if(name != nullptr) delete(name);
        if(Honey != nullptr) delete(Honey);
    } // Destruktor

    protected:
    int *amountOfBees; 
    int *x;
    int *y;
    std::string *name;
    std::vector<float> *Honey;
};



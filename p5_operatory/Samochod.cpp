#include "Samochod.h"

Samochod::Samochod() {
    this->pojemnosc_baku = 5;
    this->liczba_kilometrow = 0;
    this->poziom_paliwa = 100;
    this->model = "";
}

Samochod::Samochod(float pojemnosc_baku, std::string model) { 
    this->pojemnosc_baku = pojemnosc_baku;
    this->model = model;
    this->liczba_kilometrow = 0;
    this->poziom_paliwa = 100;
}

Samochod::~Samochod() {
    std::cout<<"Desktrukcja obiektu"<<std::endl;
}

Samochod::operator bool() const {
    if(model == "") return true;
    return false;
}

bool Samochod::operator !() const { 
    if(model != "") return true;
    return false;
}
bool Samochod::operator < (const Samochod &samochod) const { //funckja const wykonuje operacje odczytanie i nie zapisuje, stad tutaj uzycie const. operator ten sluzy porownaniu i zwroceniu bool'a
    return this->model < samochod.model;
}
void Samochod::drive(float dest) {
    if(this->poziom_paliwa / this->pojemnosc_baku > dest) {
        this->poziom_paliwa -= dest/pojemnosc_baku * 100;
    } else if (this->poziom_paliwa / this->pojemnosc_baku < dest)
    {
        std::cout << "Nie mozesz przejechac " << dest << ". \n";
    } else this->poziom_paliwa = 0;
    
}

void Samochod::setName(std::string name) {
    this->model = name;
}

void Samochod::addFuel(float amount) {
    if(amount >= this->pojemnosc_baku)
        this->poziom_paliwa = 100;
    else if (amount < this->pojemnosc_baku) {
        if (this->poziom_paliwa + amount / this->pojemnosc_baku * 100 == 100)
            this->poziom_paliwa = 100;
        else this->pojemnosc_baku += amount / this->pojemnosc_baku * 100;
    }
}

std::ostream & operator << (std::ostream &os, const Samochod &samochod) {
        os << samochod.model << " " << samochod.pojemnosc_baku << "\n";
        return os;
}

float Samochod::readPojemnosc() const {
    return pojemnosc_baku;
}

void Samochod::operator ++() {
    this->liczba_kilometrow += 1;
}
Samochod Samochod::operator |= (Samochod &samochod) {
    return samochod;
}
Samochod Samochod::operator ,(Samochod &samochod) const {
    samochod.model += this->model; 
    samochod.liczba_kilometrow += this->liczba_kilometrow;
    samochod.pojemnosc_baku += this->liczba_kilometrow;
    samochod.poziom_paliwa += this->poziom_paliwa;
    return samochod;
}

#include <iostream>

class Samochod {
private:
    float pojemnosc_baku;
    float poziom_paliwa;
    unsigned int liczba_kilometrow;
    std::string model;    

public:
    Samochod();
    Samochod(float pojemnosc_baku, std::string model);
    ~Samochod();

    void drive(float dest);
    void setName(std::string name);
    void addFuel(float amount);
    float readPojemnosc() const;

    void operator ++();
    Samochod operator |= (Samochod &samochod);
    Samochod operator ,(Samochod &samochod) const;
    operator bool() const;
    bool operator !() const;
    bool operator < (const Samochod &samochod) const;
    friend std::ostream & operator << (std::ostream &os, const Samochod &samochod);
};
#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "Osoba.hpp"

class Pracownik : public Osoba {
private:
    std::vector<std::string> *subjects;
public:
    Pracownik();
    Pracownik(std::string name, std::string surname, int day, int month, int year);
    Pracownik(std::string name, std::string surname, int day, int month, int year, std::string town, std::string street, std::string country, std::string postalCode);
    Pracownik(const Pracownik &os);
    Pracownik(Pracownik &&os);
    ~Pracownik();
    
    void addSubject(std::string subject);
    void removeSubject(std::string subject);
    bool checkForSubject(std::string subject);
    void readSubjects();
    void introduce();
};
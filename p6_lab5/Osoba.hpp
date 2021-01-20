#pragma once

#include <iostream>
#include "Adres.hpp"

class Osoba {
protected:
    std::string *name;
    std::string *surname;
    int *birthDate[3];
    Adres *placeOfResidence;

private:
    bool isLeap(int year);
    bool isValidDate(int d, int m, int y);

public:
    //-structors
    Osoba(); //domyślny
    Osoba(std::string name, std::string surname, int day, int month, int year);
    Osoba(std::string name, std::string surname, int day, int month, int year, std::string town, std::string street, std::string country, std::string postalCode); //konwertujący
    Osoba(const Osoba &os); //kopiujący
    Osoba(Osoba &&os); //przenoszący
    virtual ~Osoba(); //destuktor

    //Setters
    void setName(std::string name);
    void setSurname(std::string surname);
    void setBirthDate(int day, int month, int year);
    void setPlaceOfResidence(std::string town, std::string street, std::string country, std::string postalCode);
    
    //Getters
    std::string getName();
    std::string getSurname();
    int* getBirthDate();
    Adres getPlaceOfResidence();

    //Readers
    void readName();
    void readSurname();
    void readBirthDate();
    void readPlaceOfResidence();

    //virtual void introduce() = 0;
    //Jezeli chcemy uzywac obiektow tej klasy to nie mozemy zrobic z niej klasy abstrakcyjnej, stad blad.
    virtual void introduce();
};
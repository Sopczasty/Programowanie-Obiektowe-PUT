#include "Osoba.hpp"

Osoba::Osoba() : name(nullptr), surname(nullptr), placeOfResidence(nullptr) {
    for(int i = 0; i < 3; i++)
        birthDate[i] = nullptr;
}

Osoba::Osoba(std::string name, std::string surname, int day, int month, int year) {
    this->name = new std::string(name);
    this->surname = new std::string(surname);
    for(int i = 0; i < 3; i++)
        this->birthDate[i] = new int;
    setBirthDate(day, month, year); 
    this->placeOfResidence = nullptr;
}

Osoba::Osoba(std::string name, std::string surname, int day, int month, int year, std::string town, std::string street, std::string country, std::string postalCode) {
    this->name = new std::string(name);
    this->surname = new std::string(surname);
    for(int i = 0; i < 3; i++)
        this->birthDate[i] = new int;
    setBirthDate(day, month, year); 
    this->placeOfResidence = new Adres(town, street, country, postalCode);
}

Osoba::Osoba(const Osoba &os) : name(os.name), surname(os.surname), placeOfResidence(os.placeOfResidence) {
    for(int i = 0; i < 3; i++)
        birthDate[i] = os.birthDate[i];
}

Osoba::Osoba(Osoba &&os) : name(std::move(os.name)), surname(std::move(os.surname)), placeOfResidence(std::move(os.placeOfResidence)) {
    for(int i = 0; i < 3; i++)
        birthDate[i] = std::move(os.birthDate[i]);
}

Osoba::~Osoba() {
    if(this->name != nullptr) delete name;
    if(this->surname != nullptr) delete surname;
    for(int i = 0; i < 3; i++)
        if(this->birthDate[i] != nullptr) delete birthDate[i];
    if(placeOfResidence != nullptr)
        delete placeOfResidence;
}

bool Osoba::isLeap(int year) {
    return((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0);
}

bool Osoba::isValidDate(int d, int m, int y) {
    if (y > 2021 || y < 1900) 
        return false; 
    if (m < 1 || m > 12) 
        return false; 
    if (d < 1 || d > 31) 
        return false; 
  
    if (m == 2) { 
        if (isLeap(y)) 
        return (d <= 29); 
        else
        return (d <= 28); 
    } 
  
    if (m == 4 || m == 6 || m == 9 || m == 11) 
        return (d <= 30); 
  
    return true; 
}

void Osoba::setName(std::string name) {
    if(this->name = nullptr) this->name = new std::string;
    *this->name = name;
}

void Osoba::setSurname(std::string surname) {
    if(this->surname == nullptr) this->name = new std::string;
    *this->surname = surname;
}

void Osoba::setBirthDate(int day, int month, int year) {
    for(int i = 0; i < 3; i++)
        if(birthDate[i] == nullptr) birthDate[i] = new int;
    if(this->isValidDate(day, month, year)) {
        *this->birthDate[0] = day;
        *this->birthDate[1] = month;
        *this->birthDate[2] = year;
    } else std::cout << "[ERROR] Invalid birth date" << std::endl; 
}

void Osoba::setPlaceOfResidence(std::string town, std::string street, std::string country, std::string postalCode) {
    if(placeOfResidence != nullptr) {
        this->placeOfResidence->setTown(town);
        this->placeOfResidence->setStreet(street);
        this->placeOfResidence->setCountry(country);
        this->placeOfResidence->setPostalCode(postalCode);
    } else this->placeOfResidence = new Adres(town, street, country, postalCode);
}

std::string Osoba::getName() {
    if(this->name != nullptr)
        return *this->name;
    else std::cout << "[ERROR] Name is undefined" << std::endl;
    return "[ERROR]";
}

std::string Osoba::getSurname() {
    if(this->surname != nullptr)
        return *this->surname;
    else std::cout << "[ERROR] Surname is undefined" << std::endl;
    return "[ERROR]";
}

int* Osoba::getBirthDate() {
    if(birthDate[0] != nullptr && birthDate[1] != nullptr && birthDate[2] != nullptr)
        return *birthDate;
    else std::cout << "[ERROR] Birthdate is undefined" << std::endl;
    return nullptr;
}

Adres Osoba::getPlaceOfResidence() {
    if(this->placeOfResidence != nullptr)
        return *this->placeOfResidence;
    else std::cout << "[ERROR] Place Of Residence is undefined" << std::endl;
    Adres ret;
    return ret;
}

void Osoba::readName() {
    if(this->name != nullptr)
        std::cout << "Imie: " << this->name << std::endl;
    else std::cout << "[ERROR] Name is undefined" << std::endl;
}

void Osoba::readSurname() {
    if(this->surname != nullptr)
        std::cout << "Nazwisko: " << this->surname << std::endl;
    else std::cout << "[ERROR] Surname is undefined" << std::endl;
}

void Osoba::readBirthDate() {
    if(birthDate[0] != nullptr && birthDate[1] != nullptr && birthDate[2] != nullptr)
        std::cout << "Data urodzenia [DD-MM-YYYY]: " << birthDate[0] << "-" << birthDate[1] << "-" << birthDate[2] << std::endl;
    else std::cout << "[ERROR] Birthdate is undefined" << std::endl;
}

void Osoba::readPlaceOfResidence() {
    if(placeOfResidence != nullptr)
        std::cout << "Miejsce zamieszkania: " << placeOfResidence->getCountry() << " " << placeOfResidence->getTown() << " " << placeOfResidence->getPostalCode() << " " << placeOfResidence->getStreet() << std::endl;
    else std::cout << "[ERROR] Place of Residence is undefined" << std::endl;
}

void Osoba::introduce() {
    if(this->name != nullptr)
        std::cout << "Imie: " << *this->name << std::endl;
    if(this->surname != nullptr)
        std::cout << "Nazwisko: " << *this->surname << std::endl;
    if(this->birthDate[0] != nullptr && this->birthDate[1] != nullptr && this->birthDate[2] != nullptr)
        std::cout << "Data urodzenia [DD-MM-YYYY]: " << *this->birthDate[0] << "-" << *this->birthDate[1] << "-" << *this->birthDate[2] << std::endl; 
    if(this->placeOfResidence != nullptr)
         std::cout << "Miejsce zamieszkania: " << placeOfResidence->getCountry() << " " << placeOfResidence->getTown() << " " << placeOfResidence->getPostalCode() << " " << placeOfResidence->getStreet() << std::endl;
}
#include "Adres.hpp"

Adres::Adres() : town(nullptr), street(nullptr), country(nullptr), postalCode(nullptr) {}

Adres::Adres(std::string town, std::string street, std::string country, std::string postalCode) {
    this->town = new std::string(town);
    this->street = new std::string(street);
    this->country = new std::string(country);
    this->postalCode = new std::string(postalCode);
}

std::string Adres::getTown() {
    if(this->town != nullptr)
        return *this->town;
    return "";
}

std::string Adres::getStreet() {
    if(this->street != nullptr)
        return *this->street;
    return "";
}

std::string Adres::getCountry() {
    if(this->country != nullptr)
        return *this->country;
    return "";
}

std::string Adres::getPostalCode() {
    if(this->postalCode != nullptr)
        return *this->postalCode;
    return "";
}

void Adres::setTown(std::string town) {
    if(this->town == nullptr) this->town = new std::string;
    *this->town = town;
}

void Adres::setStreet(std::string street) {
    if(this->street == nullptr) this->street = new std::string;
    *this->street = street;
}

void Adres::setCountry(std::string country) {
    if(this->country == nullptr) this->country = new std::string;
    *this->country = country;
}

void Adres::setPostalCode(std::string postalCode) {
    if(this->postalCode == nullptr) this->postalCode = new std::string;
    *this->postalCode = postalCode;
}
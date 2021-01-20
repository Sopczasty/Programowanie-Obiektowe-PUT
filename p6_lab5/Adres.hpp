#pragma once

#include <iostream>
#include <time.h>

class Adres {
private:
    std::string *town;
    std::string *street;
    std::string *country;
    std::string *postalCode;

public:
    //Constructors
    Adres();
    Adres(std::string town, std::string street, std::string country, std::string postalCode);

    //Getters
    std::string getTown();
    std::string getStreet();
    std::string getCountry();
    std::string getPostalCode();

    //Setters
    void setTown(std::string town);
    void setStreet(std::string street);
    void setCountry(std::string country);
    void setPostalCode(std::string postalCode);
};
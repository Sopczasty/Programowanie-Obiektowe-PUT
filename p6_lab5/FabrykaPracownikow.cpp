#include "FabrykaPracownikow.hpp"

Osoba* FabrykaPracownikow::create() {
    return new Pracownik("Bilbo", "Baggins", 24, 12, 2000, "Blackburn", "Moore", "England", "782-465");
}
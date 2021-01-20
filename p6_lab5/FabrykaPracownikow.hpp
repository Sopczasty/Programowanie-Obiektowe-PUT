#pragma once
#include "FabrykaOsob.hpp"
#include "Pracownik.hpp"

class FabrykaPracownikow : public FabrykaOsob {
    virtual Osoba* create();
};
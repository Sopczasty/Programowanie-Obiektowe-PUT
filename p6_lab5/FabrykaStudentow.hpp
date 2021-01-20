#pragma once
#include "FabrykaOsob.hpp"
#include "Student.hpp"

class FabrykaStudentow : public FabrykaOsob {
    virtual Osoba* create();
};
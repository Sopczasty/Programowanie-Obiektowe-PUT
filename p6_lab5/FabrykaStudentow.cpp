#include "FabrykaStudentow.hpp"

Osoba* FabrykaStudentow::create() {
    return new Student("Mario", "Merde", 24, 12, 2000, "Blackburn", "Moore", "England", "782-465");
}
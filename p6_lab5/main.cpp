#include <iostream>

#include "Osoba.hpp"
#include "Student.hpp"
#include "Pracownik.hpp"
#include "FabrykaOsob.hpp"
#include "FabrykaPracownikow.hpp"
#include "FabrykaStudentow.hpp"

void foo(Osoba &os) {
    os.introduce();
}

void bar(Osoba *os) {
    os->introduce();
}

void menu() {

    std::map<std::string, FabrykaOsob*> m;
    std::vector<Osoba*> tablicaOsob;
    m["student"] = new FabrykaStudentow();
    m["pracownik"] = new FabrykaPracownikow();
    std::string x = "";
    while(x != "wyjscie") {
        std::cin >> x;
        if(x == "student") {
            tablicaOsob.push_back(m[x]->create());
        } else if(x== "pracownik") {
            tablicaOsob.push_back(m[x]->create());
        } else if(x == "przedstaw") {
            for(Osoba* os : tablicaOsob)
                os->introduce();
        } else std::cout << "Niepoprawna komenda, sprobuj jednej z podanych : pracownik, student, wyjscie, przedstaw" << std::endl;
    }
}

int main() {
    std::cout << "Osoba: " << std::endl;
    Osoba os("Mario", "Merde", 24, 12, 2000, "Blackburn", "Moore", "England", "782-465");
    os.introduce();
    puts("\n");
    std::cout << "Student: " << std::endl;
    Student stud = {"Mario", "Merde", 24, 7, 2000, "Blackburn", "Moore", "England", "782-465"};
    stud.addGrade("Calculus", 4.5);
    stud.addGrade("IT", 4);
    stud.introduce();

    puts("\n");
    std::cout << "Pracownik: " << std::endl;
    Pracownik pracownik("Mario", "Merde", 1, 1, 2000, "Blackburn", "Moore", "England", "782-465");
    pracownik.addSubject("Calculus");
    pracownik.addSubject("IT");
    pracownik.addSubject("Calculus");
    pracownik.removeSubject("IT");
    pracownik.introduce();

    puts("\n");
    std::cout << "zad 8 " << std::endl;
    puts("\n");

    foo(os);

    bar(&os);

    puts("\n");
    std::cout << "Student: " << std::endl;

    foo(stud);
    bar(&stud);

    puts("\n");
    std::cout << "Pracownik: " << std::endl;

    foo(pracownik);
    bar(&pracownik); //w kazdym przypadku wykonuje sie tylko Osoba::introduce()
    //po dodaniu virual printuje sie introduce danej klasy
    puts("\n");
    Pracownik *p1 = new Pracownik;
    Osoba *o1 = static_cast<Osoba *>(p1);
    Osoba *o2 = static_cast<Pracownik *>(o1); //static cast powinien byc castowany na ten sam typ. (mostly downcast)
    Osoba *o3 = new Osoba;
    Pracownik *p2 = static_cast<Pracownik *>(o3);
    Pracownik *p3 = new Pracownik;
    Osoba *o4 = dynamic_cast<Osoba *>(p3);
    //Pracownik *p4 = dynamic_cast<Osoba *>(o4); //dynamic cast jest uzywany w sposób base -> derived (downwards)
    Osoba *o5 = new Osoba;
    Pracownik *p5 = dynamic_cast<Pracownik *>(o5); //p5 jest nullptr przez zly typ klasy 
    if(p5 == nullptr) std::cout << "Blad rzutowania" << std::endl;
    else p5->readSubjects();

    menu();
}
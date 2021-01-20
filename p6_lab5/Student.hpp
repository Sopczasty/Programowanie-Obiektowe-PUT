#pragma once

#include <iostream>
#include <map>

#include "Osoba.hpp"

class Student : public Osoba {
private:
    std::map<std::string, float> *grades;

public:
    Student();
    Student(std::string name, std::string surname, int day, int month, int year);
    Student(std::string name, std::string surname, int day, int month, int year, std::string town, std::string street, std::string country, std::string postalCode);
    Student(const Student &os);
    Student(Student &&os);
    ~Student();
    void addGrade(std::string subject, float grade);
    float getGrades(std::string subject);

    void readGrades();
    void readGrade(std::string subject);
    void introduce();
};
#include "Student.hpp"

Student::Student() : Osoba(), grades(nullptr) {}

Student::Student(std::string name, std::string surname, int day, int month, int year) {
    this->name = new std::string(name);
    this->surname = new std::string(surname);
    for(int i = 0; i < 3; i++)
        this->birthDate[i] = new int;
    setBirthDate(day, month, year); 
    this->placeOfResidence = nullptr;
    this->grades = nullptr;
}

Student::Student(std::string name, std::string surname, int day, int month, int year, std::string town, std::string street, std::string country, std::string postalCode) {
 this->name = new std::string(name);
    this->surname = new std::string(surname);
    for(int i = 0; i < 3; i++)
        this->birthDate[i] = new int;
    setBirthDate(day, month, year); 
    this->placeOfResidence = new Adres(town, street, country, postalCode);
    this->grades = nullptr;
}

Student::Student(const Student &os) : Osoba(os), grades(os.grades) {}

Student::Student(Student &&os) : Osoba(os), grades(std::move(os.grades)) {}

Student::~Student() {
    if(this->grades != nullptr) delete this->grades;
}

void Student::addGrade(std::string subject, float grade) {
    if(this->grades == nullptr) this->grades = new std::map<std::string, float>;
        if(this->grades->find(subject) == this->grades->end())
            this->grades->insert(std::pair<std::string, float>(subject, grade));
        else this->grades->at(subject) = grade;
}

void Student::readGrade(std::string subject) {
    if(this->grades != nullptr)
        if(this->grades->find(subject) != this->grades->end())
            std::cout << "Grade from " << subject << " is: " << this->grades->at(subject);
        else std::cout << "[ERROR] There is no such index as " << subject << std::endl;
}

void Student::readGrades() {
    if(this->grades != nullptr)
        if(!this->grades->empty()) {
            std::cout<< "Grades from all subjects: " << std::endl;
            for(auto& it : *this->grades)
                std::cout << it.first << " " << it.second << std::endl;
        }
}

void Student::introduce() {
    Osoba::introduce();
    readGrades();
}
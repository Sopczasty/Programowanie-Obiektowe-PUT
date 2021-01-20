#include "Pracownik.hpp"

Pracownik::Pracownik() : Osoba(), subjects(nullptr) {}

Pracownik::Pracownik(std::string name, std::string surname, int day, int month, int year) {
    this->name = new std::string(name);
    this->surname = new std::string(surname);
    for(int i = 0; i < 3; i++)
        this->birthDate[i] = new int;
    setBirthDate(day, month, year); 
    this->placeOfResidence = nullptr;
    this->subjects = nullptr;
}

Pracownik::Pracownik(std::string name, std::string surname, int day, int month, int year, std::string town, std::string street, std::string country, std::string postalCode) {
       this->name = new std::string(name);
    this->surname = new std::string(surname);
    for(int i = 0; i < 3; i++)
        this->birthDate[i] = new int;
    setBirthDate(day, month, year); 
    this->placeOfResidence = new Adres(town, street, country, postalCode);
    this->subjects = nullptr;
}
Pracownik::Pracownik(const Pracownik &os) : Osoba(os), subjects(os.subjects) {}

Pracownik::Pracownik(Pracownik &&os) : Osoba(os), subjects(std::move(os.subjects)) {}

Pracownik::~Pracownik() {
    if(this->subjects != nullptr) delete this->subjects;
}

void Pracownik::addSubject(std::string subject) {
    if(this->subjects == nullptr) this->subjects = new std::vector<std::string>;
    if(std::find(this->subjects->begin(), this->subjects->end(), subject) == this->subjects->end())
        this->subjects->push_back(subject);
}

void Pracownik::removeSubject(std::string subject) { 
    if(this->subjects != nullptr)
        if(std::find(this->subjects->begin(), this->subjects->end(), subject) != this->subjects->end())
            this->subjects->erase(std::remove(this->subjects->begin(), this->subjects->end(), subject), this->subjects->end());
}

void Pracownik::readSubjects() {
    if(this->subjects != nullptr)
        if(!this->subjects->empty()) {
            std::cout << "Subjects: " << std::endl; 
            for(std::string s : *this->subjects)
                std::cout << s << std::endl; 
        }
}

void Pracownik::introduce() {
    Osoba::introduce();
    this->readSubjects();
}
#include "ul.hpp"

ul::ul(ul &&Ul): amountOfBees(std::move(Ul.amountOfBees)), name(std::move(Ul.name)), year(std::move(Ul.year)), totalHoney(std::move(Ul.totalHoney)), recentlyMadeHoney(std::move(Ul.recentlyMadeHoney)), Logger(true)  {
    this->log("Wywolanie konstruktora przenoszacego");
    coords[0] = std::move(Ul.coords[0]);
    coords[1] = std::move(Ul.coords[1]);
} // Konstruktor przenoszący

ul::ul(const ul &Ul): Logger(true) {
    log("Wywolanie konstruktora kopiujacego");
    if(Ul.amountOfBees != nullptr) {
    amountOfBees = new int;
    *amountOfBees = Ul.getAmountOfBees();
    } else amountOfBees = nullptr;

    if(Ul.coords[0] != nullptr && Ul.coords[1] != nullptr) {
        coords[0] = new int;
        coords[1] = new int; 
        int* tempCoords = Ul.getHiveCoords();
        *coords[0] = tempCoords[0];
        *coords[1] = tempCoords[1];
    } else {
        coords[0] = nullptr;
        coords[1] = nullptr;
    }

    if(Ul.name != nullptr) {
        name = new std::string;
        *name = Ul.getName();
    } else name = nullptr;

    if(Ul.recentlyMadeHoney != nullptr) {
        recentlyMadeHoney = new float;
        *recentlyMadeHoney = Ul.getRecentlyMadeHoney();
    } else recentlyMadeHoney = nullptr;

    if(Ul.totalHoney != nullptr) {
        totalHoney = new float;
        *totalHoney = Ul.getHoneyMade();
    } else totalHoney = nullptr;

    if(Ul.year != nullptr) {
        year = new int;
        *year = Ul.getYear();
    } else year = nullptr;

} //Konstruktor Kopiujący

ul::ul(std::string name, int x, int y, int amountOfBees): Logger(true) {
    this->log("Wywolanie konstruktora konwertujacego z wszystkimi parametrami");
    this->name = new std::string(name);
    this->coords[0] = new int(x);
    this->coords[1] = new int(y);
    this->amountOfBees = new int(amountOfBees);
} //Konstruktor konwertujacy z wszystkimi parametrami

ul::ul(int bees) : Logger(true) {
    this->log("Wywolanie konstruktora konwertujacego");
    this->amountOfBees = new int;
    *this->amountOfBees = bees;
} //Konstruktor konwertujacy

ul::ul(): amountOfBees(nullptr), name(nullptr), year(nullptr), totalHoney(nullptr), recentlyMadeHoney(nullptr), Logger(true), Stopper() {
    log("Wywolanie konstruktora domyslnego");
    coords[0] = nullptr;
    coords[1] = nullptr;
    this->reset();
}//Konstruktor domyślny

ul::~ul() { 
    log("Wywolanie destruktora");
    if(amountOfBees != nullptr) delete amountOfBees;
    if(coords[0] != nullptr) delete coords[0];
    if(coords[1] != nullptr) delete coords[1];
    if(name != nullptr) delete name;
    if(year != nullptr) delete year;
    if(totalHoney != nullptr) delete totalHoney;
    if(recentlyMadeHoney != nullptr) delete recentlyMadeHoney;
} // Destruktor

void ul::setName(std::string name) {
    start();
    log("Wywolanie setNane");
    if(this->name == nullptr) this->name = new std::string;
    if(isalpha(name[0]) && isupper(name[0])) {
        *this->name = name;
    }
    else
        std::cout << "Name needs to start with upper character" << std::endl;
    stop();
}

void ul::setPosition(int x, int y) {
    start();
    log("Wywolanie setPosition");
    if(coords[0] == nullptr) {
        coords[0] = new int;
        coords[1] = new int;
    }
    *coords[0] = x;
    *coords[1] = y;
    stop();
}

void ul::honeyMade(float amount) {
    start();
    log("Wywolanie honeyMade");
    if(year == nullptr || totalHoney == nullptr || recentlyMadeHoney == nullptr) {
        year = new int;
        *year = 0;
        totalHoney = new float;
        *totalHoney = 0;
        recentlyMadeHoney = new float;
    }
    *totalHoney += amount;
    *year += 1;
    *recentlyMadeHoney = amount;
    stop();
}

int ul::getYear() const {
    start();
    log("Wywolanie getYear");
    return *year;
    stop();
}

float ul::getHoneyMade() const {
    log("Wywolanie totalHoney");
    return *totalHoney;
}

float ul::getRecentlyMadeHoney() const {
    log("Wywolanie getYear");
    return *recentlyMadeHoney;
}

int ul::getAmountOfBees() const {
    log("Wywolanie getAmountOfBees");
    return *amountOfBees;
}

int* ul::getHiveCoords() const {
    log("Wywolanie getHiveCoords");
    return *coords;
}

std::string ul::getName() const {
    log("Wywolanie getName");
    if(name != nullptr)
        return *name;
    return "NULL";
}

float ul::getAverageHoney() const {
    log("Wywolanie getAverageHoney");
    if(*year > 0) {
        return *totalHoney / *year;
    }
    else
        return 0;
}

void ul::changeBeeAmount(int change) {
    log("Wywolanie changeBeeAmount");
    if(amountOfBees == nullptr) {
        amountOfBees = new int;
        *amountOfBees = 50;
    }
    if(*amountOfBees + change > 0 && change < 100 && change > -100) {
            *amountOfBees += change;
    } else std::cout<< "Error, zla ilosc podana" << std::endl;
}

#include <iostream>
#include <vector>
#include <ctype.h>

class Hive {
    public:
    Hive(int startBees){
        if(startBees > 0)
            this->amountOfBees = startBees;
        else
            std::cout<<"There cannot be negative bees!"<<std::endl;
    }

    void setName(std::string name) {
        if(isalpha(name[0]) && isupper(name[0])) {
            this->name = name;
        }
        else
            std::cout << "Name needs to start with upper character" << std::endl;
    }

    void changeStolenPercent(int newPercent) {
        this->percentOfHoneyStolen = newPercent;
    }

    void setPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void honeyMade(float amount) {
        this->Honey.push_back(amount);
        this->changeHappinessLevel();

    }

    int getHappiness() {
        return this->happinessLevel;
    }

    float getRecentlyMadeHoney() {
        return this->Honey[this->Honey.size()-1];
    }

    int getAmountOfBees() {
        return this->amountOfBees;
    }

    auto getHiveCoords() {
        struct result {int x; int y;};
        return result {this->x, this->y};
    }

    std::string getName() {
        return this->name;
    }

    float getAverageHoney() {
        if(this->Honey.size()) {
            float sum = 0;
            for(int i=0; i<this->Honey.size(); i++)
                sum+=this->Honey[i];
            return sum / this->Honey.size(); 
        }
        else
            return 0;
    }

    bool changeBeeAmount(int change) {
        if(this->amountOfBees + change > 0 && change < 100 && change > -100) {
                this->amountOfBees += change;
                return true;
            }
        std::cout<< "Error, zla ilosc podana" << std::endl;
        return false;
    }

    protected:
    int amountOfBees; 
    int x;
    int y;
    std::string name = "";
    std::vector<float> Honey;
    int percentOfHoneyStolen = 50;
    int happinessLevel = 50;

    void changeHappinessLevel() {
        int change = this->defineChangeOfHappiness();
        if(this->happinessLevel + change > 100)
            this->happinessLevel = 100;
        else if (this->happinessLevel + change < 0)
            this->happinessLevel = 0;
        else this->happinessLevel += change;
    }

    int defineChangeOfHappiness() {
        int change;
        if(this->percentOfHoneyStolen < 50) return (50 - this->percentOfHoneyStolen)/2;
        if(this->percentOfHoneyStolen > 50) return (50 - this->percentOfHoneyStolen)/2;
        return 0;
    }

};

int main() {
    
    //Setting values
    class Hive hive = Hive(100);
    hive.setName("Pasieka Zachodnia");
    hive.setPosition(-4, 15);
    hive.honeyMade(153.54);
    hive.changeStolenPercent(30);

    //Reads:
    std::cout << "1. Liczba pszczol: " << hive.getAmountOfBees() << std::endl;
    std::cout << "1. Srednia ilosc wyprodukowanego miodu: "<< hive.getAverageHoney() << std::endl;
    std::cout << "1. Polozenie Ula: " << "x: " << hive.getHiveCoords().x << " y: " << hive.getHiveCoords().y << std::endl;
    std::cout << "1. Nazwa pasieki: " << hive.getName() << std::endl;
    std::cout << "1. Miod wyprodukowany w tym roku: " << hive.getRecentlyMadeHoney() << std::endl;
    std::cout << "1. Poziom szczescia: " << hive.getHappiness() << std::endl;
    //Methods:
    hive.changeBeeAmount(-20);
    hive.honeyMade(32.3);
    std::cout << "2. Poziom szczescia: " << hive.getHappiness() << std::endl;
    
    hive. changeStolenPercent(100);

    hive.honeyMade(13.7);
    std::cout << "2. Liczba pszczol: " << hive.getAmountOfBees() << std::endl;
    std::cout << "2. Srednia ilosc wyprodukowanego miodu: "<< hive.getAverageHoney() << std::endl;
    std::cout << "2. Miod wyprodukowany w tym roku: " << hive.getRecentlyMadeHoney() << std::endl;
    std::cout << "3. Poziom Szczescia: " << hive.getHappiness() << std::endl;
}

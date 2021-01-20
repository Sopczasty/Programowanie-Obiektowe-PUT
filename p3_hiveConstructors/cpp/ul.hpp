#pragma once

#include <iostream>
#include "Logger.hpp"
#include "Stopper.hpp"

class ul: public Logger, public Stopper {
public:
    ul();
    ul(ul &&Ul);
    ul(const ul &Ul);
    ul(std::string name, int x, int y, int amountOfBees);
    ul(int bees);
    ~ul();

    void setName(std::string name);
    void setPosition(int x, int y);
    void honeyMade(float amount);
    void changeBeeAmount(int change);
    
    float getRecentlyMadeHoney() const;
    float getHoneyMade() const;
    float getAverageHoney() const;
    int getYear() const;
    int getAmountOfBees() const;
    int* getHiveCoords() const;
    std::string getName() const;


private:
    int *amountOfBees = 0; 
    int *coords[2] = {0, 0};
    int *year = 0;
    std::string *name = 0;
    float *totalHoney = 0;
    float *recentlyMadeHoney = 0;
};
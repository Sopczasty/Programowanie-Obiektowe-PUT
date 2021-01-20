#include <iostream>

class Towers {
private:
    int id;
    int cost;
    int damage;
    int speed;
    int level;
    float range;
    std::string description;

public:
    virtual void create() = 0;
    virtual void upgrade() = 0;
    virtual void fire(float x, float y) = 0;
};
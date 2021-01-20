#include <iostream>
#include "Towers.hpp"

class BasicTower : public Towers {
private:
    virtual void create();

protected:
    virtual void upgrade();
    virtual void fire(float x, float y);
};
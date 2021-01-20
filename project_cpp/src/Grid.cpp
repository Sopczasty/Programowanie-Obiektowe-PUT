#include "Grid.hpp"

    Grid::Grid(sf::Vector2f coords, int tileSize, sf::Texture *texture) {
        this->coords = coords;
        this->tileSize = tileSize;
        this->type = 0;
        shape.setSize(sf::Vector2f(this->tileSize, this->tileSize));
        shape.setTexture(texture);
        shape.setPosition(this->coords);
    }
    Grid::~Grid() {}

    void Grid::getNewTexture(sf::Texture *texture, int type) { 

    }

    int Grid::getType() {
        return this->type;
    }
    void Grid::placeTower(int id) {
        int x = id;
    }
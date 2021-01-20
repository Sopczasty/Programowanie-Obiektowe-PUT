#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Grid {
public:
    Grid(sf::Vector2f coords, int tileSize, sf::Texture *texture);
    ~Grid();
    int getType();
    sf::RectangleShape shape;

protected:
    float x;
    float y;
    void placeTower(int id);
    void removeTower(int id);

private:
    void getNewTexture(sf::Texture *texture, int type);
    sf::Texture texture;
    sf::Vector2f coords;
    int tileSize;
    int width;
    int height;
    int type;

};
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "Grid.hpp"
#include "Player.hpp"


class Game { 
public:
    Game(int width, int height, int gridSizeX, int gridSizeY, int tileSize);

protected:

private:
    //Methods
    void getTextures();
    void preprocessor();
    void processEvents();
    void update();
    void render();
    void gameLoop();
    void stop();
    void createGrid();
    void createUIBase();
    void draw(sf::RectangleShape shape);    

    //Integers
    int buttonAmount;
    int gridSizeX;
    int gridSizeY;
    int tileSize;

    //Booleans
    bool is_running;
    bool fast_mode;
    bool* buttonStates;

    //Vectors
    std::vector<sf::Texture> textures;

    //SFML Variables
    sf::RenderWindow window;
    sf::Event ev;
    sf::Vector2f resolution;

    //Graphic Objects
    sf::RectangleShape base; // UI Base

    //Objects
    Grid ***grid;
    Player *player;
};
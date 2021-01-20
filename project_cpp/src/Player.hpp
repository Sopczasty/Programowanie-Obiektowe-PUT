#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player {
    public:
        Player(sf::Vector2f resolution, sf::Vector2f UI_location, bool **states, int buttonAmount, sf::RenderWindow &window);
        ~Player();

        void buyTower(int id);
        void sellTower(int id);
        void drawUserInterface();
        void openMenu(int id);
    protected:
        int coins;

    private:
        sf::Font *font;
        sf::Vector2f *resolution;
        sf::Vector2f UI_location;
        sf::RenderWindow *window;
        bool **states;
        int buttonAmount;
        void drawbutton(bool state, sf::Vector2f button, sf::Vector2f size);
        

};
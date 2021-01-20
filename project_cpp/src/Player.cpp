#include "Player.hpp"
#include <iostream>

Player::Player(sf::Vector2f resolution, sf::Vector2f UI_location, bool **states, int buttonAmount, sf::RenderWindow &window) {
    this->resolution = &resolution;
    this->UI_location = UI_location;
    this->states = states;
    this->buttonAmount = buttonAmount;
    this->window = &window;
    this->font = new sf::Font();
    this->font->loadFromFile("fonts/arial.ttf");
}



void Player::drawUserInterface() {
    for(int i = 0; i < buttonAmount/2; i++) {
        for(int j = 0; j < 2; j++) {
            int interspace = (resolution->x - UI_location.x - 2*70)/3;
            this->drawbutton(states[i*(j+1)], sf::Vector2f(UI_location.x + interspace*(j+1) + 70*j, UI_location.y + interspace*(i+1) + 100*i), sf::Vector2f(70, 100));
        }
    }
}

void Player::openMenu(int id) {
    sf::Text text;
    text.setFont(*this->font);
    text.setString(std::to_string(id));
}

void Player::buyTower(int id) {

}
void Player::sellTower(int id) {

}

void Player::drawbutton(bool state, sf::Vector2f button, sf::Vector2f size) {
    sf::RectangleShape shape(size);
    std::cout<<"blabla";
    switch(state) {
        case 0:
            shape.setFillColor(sf::Color(105, 105, 105, 255));
            shape.setPosition(button);
            shape.setOutlineColor(sf::Color::Black);
            shape.setOutlineThickness(1);
            std::cout<<"drawn null\n";
            window->draw(shape);
            break;

        default:
            shape.setFillColor(sf::Color(168, 168, 168, 255));
            shape.setPosition(button);
            shape.setOutlineColor(sf::Color::Black);
            shape.setOutlineThickness(1);
            window-> draw(shape);
            std::cout<<"drawn default\n";
            break;
    }
}
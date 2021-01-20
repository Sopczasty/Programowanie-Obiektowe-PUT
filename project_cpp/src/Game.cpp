#include "Game.hpp"
#include <iostream>

    Game::Game(int width, int height, int gridSizeX, int gridSizeY, int tileSize) {
        //Game Window Settings
        this->window.create(sf::VideoMode(width, height), "Tower Defense", sf::Style::Close | sf::Style::Titlebar);
        this->resolution = sf::Vector2f(width, height);

        //Grid Settings
        this->gridSizeX = gridSizeX;
        this->gridSizeY = gridSizeY;
        this->tileSize = tileSize;

        //Player Settings
        
                 //Player::Player(sf::Vector2f resolution, sf::Vector2f UI_location, bool &states, int buttonAmount, sf::RenderWindow &window)
        //UI Settings
        this->base.setSize(sf::Vector2f(this->resolution.x - this->gridSizeX * this->tileSize, this->resolution.y));
        this->base.setPosition(this->gridSizeX * this->tileSize, 0);
        this->base.setFillColor(sf::Color(169, 169, 169, 100));
        this->base.setOutlineColor(sf::Color::Black);
        this->base.setOutlineThickness(0.5);
        this->buttonAmount = 10;
        this->buttonStates = new bool[buttonAmount];
        for(int i = 0; i < buttonAmount; i++)
            this->buttonStates[i] = false;
        this->buttonStates[3] = true;

        this->player = new Player(sf::Vector2f(this->resolution), sf::Vector2f(resolution.y, 0), &this->buttonStates, this->buttonAmount, this->window);
        preprocessor();
        gameLoop();
    }

    void Game::getTextures() {
        sf::Texture texture;

        if(!texture.loadFromFile("textures/grass.png"))
            std::cout<<"Error while loading texture #1"<<std::endl;
        std::cout<<"Texture #1 loaded"<<std::endl;
        this->textures.push_back(texture);
    }

    void Game::preprocessor() {
        getTextures();
        createGrid();
        window.setFramerateLimit(60);
    }

    void Game::processEvents() {
            while(this->window.pollEvent(ev)) {
                switch(ev.type) { //Event switch
                    case sf::Event::Closed: 
                        window.close();
                        break;
                    case sf::Event::KeyPressed: 
                        switch(ev.key.code) { //Keypresses switch
                            case sf::Keyboard::Escape:
                                window.close();
                                break;
                            default:
                                break;
                        }
                    case sf::Event::MouseButtonPressed: //MouseButton pressed
                        auto mouse = sf::Event::MouseButtonEvent();
                        if(mouse.x < 800) {
                            int type = grid[int(mouse.x/tileSize)][int(mouse.y/tileSize)]->getType();
                            player->openMenu(type);
                        }
                        break;
                }
            }
    }

    void Game::update() {
        
    }

    void Game::render() {
        window.clear();
        for(int i = 0; i < this->gridSizeX; i++)
            for(int j = 0; j < this->gridSizeY; j++) {
                this->draw(grid[i][j]->shape);
            }
        draw(base);
        player->drawUserInterface();
        window.display();
    }

    void Game::gameLoop() {
        while(this->window.isOpen()) {
            processEvents();
            update();  
            render();
        }
    }

    void Game::createGrid() {
        this->grid = new Grid**[gridSizeX];
        for(int i = 0; i < gridSizeX; i++)
            this->grid[i] = new Grid*[gridSizeY];
        for(int i = 0; i < gridSizeX; i++)
            for(int j = 0; j < gridSizeY; j++)
                this->grid[i][j] = new Grid(sf::Vector2f(tileSize*i, tileSize*j), tileSize, &textures[0]);
    }


    void Game::draw(sf::RectangleShape shape) {
        this->window.draw(shape);
    }

    void Game::stop() {
        window.close();
    }

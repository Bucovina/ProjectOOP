#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Enemy.h"
#include "UserInterface.h"
#include "UI_Text.h"

///"Game engine" class

class Game {
private:
    ///Variables
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;

    ///Mouse positions
    sf::Vector2i mousePositionWindow;
    sf::Vector2f mousePositionView;

    ///Game logic
    int coins;
    int score;
    static int click_damage;

    ///Game objects
    Enemy enemy;
    UI_Text NextEnemyButton;
    UserInterface UpgradeButton;

    ///Game background
    sf::Texture backgroundTexture;
    sf::Sprite background;

    ///Private functions
    void initializeVariables();

    void initializeWindow();

    void initializeBackground();

public:
    ///Constructor and Destructor
    Game();

    ~Game();

    ///Operators
    friend std::ostream &operator<<(std::ostream &os, const Game &game);

    static int getClickDamage();

    static void setClickDamage(int clickDamage);

    ///Getter and Setter
    const sf::Vector2f &getMousePositionView() const;

    ///Accessors
    bool runningGame() const;

    ///Functions

    void pollEvent();

    void updateMousePosition();

    void update();

    void render();
};

#endif //MAIN_CPP_GAME_H

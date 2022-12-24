#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <execution>
#include <array>
#include <typeinfo>
#include <memory>
#include "Enemy.h"
#include "UserInterface.h"
#include "UI_Text.h"
#include "Enemy_cub.h"
#include "Enemy_texture.h"

class BackgroundException : public std::exception {
public:
    [[nodiscard]] static const char *background() noexcept { return "Background texture loading error"; }
};

class FontException : public std::exception {
public:
    [[nodiscard]] static const char *font() noexcept { return "Font loading error"; }
};

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
    int hp;
    int coins;
    int score;
    static int click_damage;

    ///Game objects
    std::shared_ptr<Enemy> enemy;
    UI_Text NextEnemyButton;
    UI_Text CoinsScoreUI;
    UserInterface UpgradeButton;
    UserInterface Test;

    ///Game background
    sf::Texture backgroundTexture;
    sf::Sprite background;

    ///Tips
    bool check = false;
    std::array<std::string, 4> text = {"Tip:Click the enemy!", "Tip:Defeat the enemy!",
                                       "Tip:Click!", "Tip:Click click click!"};
    sf::Text tips;
    sf::Font font;

    ///Private functions
    void initializeVariables();

    void initializeWindow();

    void initializeBackground();

    void initializeTips();

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

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
    std::shared_ptr<Enemy> enemyCub=enemy->clone();
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

    Game& operator=(Game other)
    {
        swap(*this,other);
        return *this;
    }

    friend void swap(Game& game1, Game& game2) {
        using std::swap;
        std::swap(game1.window,game2.window);
        std::swap(game1.videoMode,game2.videoMode);
        std::swap(game1.event,game2.event);
        std::swap(game1.mousePositionView,game2.mousePositionView);
        std::swap(game1.mousePositionWindow,game2.mousePositionWindow);
        std::swap(game1.hp,game2.hp);
        std::swap(game1.coins,game2.coins);
        std::swap(Game::click_damage,Game::click_damage);
        std::swap(game1.score,game2.score);
        std::swap(game1.enemy,game2.enemy);
        std::swap(game1.NextEnemyButton,game2.NextEnemyButton);
        std::swap(game1.CoinsScoreUI,game2.CoinsScoreUI);
        std::swap(game1.UpgradeButton,game2.UpgradeButton);
        std::swap(game1.Test,game2.Test);
        std::swap(game1.backgroundTexture,game2.backgroundTexture);
        std::swap(game1.background,game2.background);
        std::swap(game1.check,game2.check);
        std::swap(game1.text,game2.text);
        std::swap(game1.tips,game2.tips);
        std::swap(game1.font,game2.font);
    }

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

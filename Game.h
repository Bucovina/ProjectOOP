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

class TextureException : public std::exception {
public:
    [[nodiscard]] static const char *background() noexcept { return "Enemy texture loading error"; }
};

template <typename T>
class decor{
private:
    T x;
    T y;
    sf::Texture texture;
    sf::Sprite body;
public:
    decor(){
        if (!texture.loadFromFile("banner.png")) {
            throw TextureException();
        }
        this->body.setTexture(texture);
        this->body.setScale(0.25,0.25);
        this->body.setPosition(x, y);
    }

    const sf::Sprite &getBody() const {
        return body;
    }

    void setPosition(T x_,T y_) {
        decor::x = x_;
        decor::y = y_;
        this->body.setPosition(x, y);
    }
};

template <typename T>
void afisare(const T &x){
    std::cout<<x<<'\n';
}

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
    int price=1;
    static int click_damage;
    int nr_click=0;

    ///Game objects
    std::shared_ptr<Enemy> enemy;
    std::array<std::shared_ptr<Enemy>,2> enemies={Enemy_texture().clone(),Enemy_cub().clone()};
    UI_Text NextEnemyButton;
    UI_Text CoinsScoreUI;
    UserInterface UpgradeButton;
    UserInterface Test;
    decor<float> banner1;
    decor<double> banner2;

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

    Game();
public:
    ///Constructor and Destructor

    ~Game();

    Game(const Game&)=delete;

    Game &operator=(const Game&) =delete;

    static Game& start_game(){
        static Game game;
        return game;
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

#ifndef MAIN_CPP_ENEMY_H
#define MAIN_CPP_ENEMY_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Enemy {
private:
    ///Game
    sf::RectangleShape body;

    ///Game logic
    int hp;

public:
    ///Contructor and Destructor
    Enemy();
    ~Enemy();

    ///Operators
    Enemy& operator=(const Enemy& enemy);

    friend std::ostream &operator<<(std::ostream &os, const Enemy &enemy);

    ///Getters
    const sf::RectangleShape &renderEnemy() const;

    ///Functions
    void UpdateEnemy();
};


#endif //MAIN_CPP_ENEMY_H

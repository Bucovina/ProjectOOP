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
    float size;
    int initialHp;
    int currentHp;
    bool alive;

public:
    ///Constructor and Destructor
    Enemy();

    ~Enemy();

    ///Operators
    Enemy &operator=(const Enemy &enemy);

    Enemy(const Enemy &enemy);

    friend std::ostream &operator<<(std::ostream &os, const Enemy &enemy);

    ///Getters and Setters
    const sf::RectangleShape &renderEnemy() const;

    bool getAlive() const;

    int getCurrentHp() const;

    int getInitialHp() const;

    ///Functions
    void DamageEnemy(sf::Vector2f mousePositionView);

    void NextEnemy(sf::Vector2f mousePositionView, const sf::RectangleShape &buttonNext);
};


#endif //MAIN_CPP_ENEMY_H

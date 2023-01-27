#ifndef MAIN_CPP_ENEMY_H
#define MAIN_CPP_ENEMY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <random>
#include <utility>

class Enemy {
protected:
    ///Game logic
    float size;
    int initialHp;
    int currentHp;
    bool alive;

public:
    ///Constructor and Destructor
    Enemy();

    virtual ~Enemy();

    ///Operators
    Enemy(Enemy &&other) = default;

    Enemy &operator=(Enemy &&other) = default;

    Enemy(const Enemy &other) = default;

    Enemy &operator=(const Enemy &other) = default;

    friend std::ostream &operator<<(std::ostream &os, const Enemy &enemy);

    ///Getters and Setters
    virtual void renderEnemy(sf::RenderWindow &window) = 0;

    [[nodiscard]]  bool getAlive() const;

    void setAlive(bool alive);

    [[nodiscard]]  int getCurrentHp() const;

    [[nodiscard]]  int getInitialHp() const;

    void setInitialHp(int initialHp);

    ///Functions
    [[nodiscard]] virtual std::shared_ptr<Enemy> clone() const = 0;

    virtual void DamageEnemy(sf::Vector2f mousePositionView, int click_damage) = 0;

    virtual void
    NextEnemy(sf::Vector2f mousePositionView, const sf::RectangleShape &buttonNext) = 0;
};


#endif //MAIN_CPP_ENEMY_H
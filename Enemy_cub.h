#ifndef GAME_CPP_ENEMY_CUB_H
#define GAME_CPP_ENEMY_CUB_H

#include "Enemy.h"
#include "Enemy_texture.h"

class Enemy_cub : public Enemy {
private:
///Game
    sf::RectangleShape body;

public:
    ///Constructor
    Enemy_cub();

///Getters and Setters
    void renderEnemy(sf::RenderWindow &window) override;

///Functions
    std::shared_ptr<Enemy> clone() const override;

    void DamageEnemy(sf::Vector2f mousePositionView, int click_damage) override;

    void NextEnemy(sf::Vector2f mousePositionView, const sf::RectangleShape &buttonNext) override;
};


#endif //GAME_CPP_ENEMY_CUB_H

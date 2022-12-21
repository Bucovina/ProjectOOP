#ifndef GAME_CPP_ENEMY_TEXTURE_H
#define GAME_CPP_ENEMY_TEXTURE_H

#include "Enemy.h"
#include "Enemy_cub.h"

class Enemy_texture : public Enemy {
private:
///Game
    std::array<std::string, 4> skin={"enemy.png","enemy1.png","enemy2.png","enemy3.png"};
    std::array<std::array<float,2>,4> position={{{80,200},{185,200},{160,300},{60,230}}};
    sf::Texture texture;
    sf::Sprite body;

public:
    ///Constructor
    Enemy_texture();

///Getters and Setters
    void renderEnemy(sf::RenderWindow &window) override;

///Functions
    std::shared_ptr<Enemy> clone() const override;

    void DamageEnemy(sf::Vector2f mousePositionView, int click_damage) override;

    void NextEnemy(sf::Vector2f mousePositionView, const sf::RectangleShape &buttonNext) override;
};


#endif //GAME_CPP_ENEMY_TEXTURE_H

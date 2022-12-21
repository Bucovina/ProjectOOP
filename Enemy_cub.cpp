#include "Enemy_cub.h"

///Constructor
Enemy_cub::Enemy_cub() {
    this->body.setPosition((600 - size) / 2, (800 - size) / 2);
    this->body.setSize(sf::Vector2f(size, size));
    this->body.setFillColor(sf::Color::Red);
    this->body.setOutlineColor(sf::Color::Black);
    this->body.setOutlineThickness(4.f);
    std::cout << "-Enemy_cub a fost creat\n";
}

///Getters and setters
void Enemy_cub::renderEnemy(sf::RenderWindow &window) {
    window.draw(this->body);
}

///Function
std::shared_ptr<Enemy> Enemy_cub::clone() const {
    return std::make_shared<Enemy_cub>(*this);
}

void Enemy_cub::DamageEnemy(sf::Vector2f mousePositionView, int click_damage) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->body.getGlobalBounds().contains(mousePositionView) and this->currentHp > 0) {
            this->currentHp = this->currentHp - click_damage;
        }
        if (this->currentHp <= 0)
            this->alive = false;
    }

}

void Enemy_cub::NextEnemy(sf::Vector2f mousePositionView, const sf::RectangleShape &buttonNext) {
    srand(time(nullptr));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        if (buttonNext.getGlobalBounds().contains(mousePositionView) and this->alive == 0) {
            this->initialHp = rand() % this->initialHp % 5 + this->initialHp;
            this->currentHp = this->initialHp + 1;
            this->size = (float) (rand() % 300 + 20);
            this->body.setSize(sf::Vector2f(size, size));
            this->body.setPosition((600 - size) / 2, (800 - size) / 2);
            this->body.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            this->alive = true;
        }
}


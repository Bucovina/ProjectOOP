#include "Enemy.h"

///Constructor and Destructor
Enemy::Enemy() {
    this->body.setPosition(250.f, 200.f);
    this->body.setSize(sf::Vector2f(100.f, 100.f));
    this->body.setFillColor(sf::Color::Red);
    this->body.setOutlineColor(sf::Color::Black);
    this->body.setOutlineThickness(4.f);
    this->hp = 10;
    this->alive = true;
    std::cout << "Clasa a fost creata\n";
}

Enemy::~Enemy() = default;

///Operators
Enemy &Enemy::operator=(const Enemy &enemy) {
    body = enemy.body;
    hp = enemy.hp;
    alive =enemy.alive;
    return *this;
}


Enemy::Enemy(const Enemy &enemy) {
    body = enemy.body;
    hp = enemy.hp;
    alive =enemy.alive;
}


std::ostream &operator<<(std::ostream &os, const Enemy &enemy) {
    os << " hp: " << enemy.hp << " alive: " << enemy.alive << "\n";
    return os;
}

///Getters and setters
const sf::RectangleShape &Enemy::renderEnemy() const {
    return body;
}

bool Enemy::getAlive() const {
    return alive;
}

void Enemy::setAlive(bool o_alive) {
    Enemy::alive = o_alive;
}

///Function
void Enemy::DamageEnemy(sf::Vector2f mousePositionView) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->body.getGlobalBounds().contains(mousePositionView) and this->hp>0) {
            this->hp = this->hp - 1;
        }
        if (this->hp == 0)
            this->alive = false;
    }
}

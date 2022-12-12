#include "Enemy.h"
#include <random>
#include <ctime>

///Constructor and Destructor
Enemy::Enemy() {
    this->size = 100.f;
    this->body.setPosition((600 - size) / 2, (800 - size) / 2);
    this->body.setSize(sf::Vector2f(size, size));
    this->body.setFillColor(sf::Color::Red);
    this->body.setOutlineColor(sf::Color::Black);
    this->body.setOutlineThickness(4.f);
    this->currentHp = 10;
    this->initialHp = 10;
    this->alive = true;
    std::cout << "Clasa a fost creata\n";
}

Enemy::~Enemy() = default;

///Operators
Enemy &Enemy::operator=(const Enemy &enemy) {
    body = enemy.body;
    initialHp = enemy.initialHp;
    currentHp = enemy.currentHp;
    alive = enemy.alive;
    return *this;
}

Enemy::Enemy(const Enemy &enemy) {
    size = enemy.size;
    body = enemy.body;
    initialHp = enemy.initialHp;
    currentHp = enemy.currentHp;
    alive = enemy.alive;
}

std::ostream &operator<<(std::ostream &os, const Enemy &enemy) {
    os << "hp: " << enemy.currentHp << " alive: " << enemy.alive << "\n";
    return os;
}

///Getters and setters
const sf::RectangleShape &Enemy::renderEnemy() const {
    return body;
}

bool Enemy::getAlive() const {
    return alive;
}

int Enemy::getCurrentHp() const {
    return currentHp;
}

int Enemy::getInitialHp() const {
    return initialHp;
}


///Function
void Enemy::DamageEnemy(sf::Vector2f mousePositionView, int click_damage) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->body.getGlobalBounds().contains(mousePositionView) and this->currentHp > 0) {
            this->currentHp = this->currentHp - click_damage;
        }
        if (this->currentHp <= 0)
            this->alive = false;
    }

}

void Enemy::NextEnemy(sf::Vector2f mousePositionView, const sf::RectangleShape &buttonNext) {
    srand(time(nullptr));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        if (buttonNext.getGlobalBounds().contains(mousePositionView) and this->alive == 0) {
            this->initialHp = rand() % this->initialHp % 5 + this->initialHp;
            this->currentHp = this->initialHp;
            this->size = (float) (rand() % 300 + 20);
            this->body.setSize(sf::Vector2f(size, size));
            this->body.setPosition((600 - size) / 2, (800 - size) / 2);
            this->body.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
            this->alive = true;
        }
}

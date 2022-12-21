#include "Enemy.h"
#include <random>

///Constructor and Destructor
Enemy::Enemy() {
    this->size = 100.f;
    this->currentHp = 10;
    this->initialHp = 10;
    this->alive = false;
    std::cout << "Enemy simplu a fost apelat";
}

Enemy::~Enemy() {
    std::cout << "Sters\n";
}

///Operators
Enemy &Enemy::operator=(const Enemy &enemy) {
    initialHp = enemy.initialHp;
    currentHp = enemy.currentHp;
    alive = enemy.alive;
    return *this;
}

Enemy::Enemy(const Enemy &enemy) {
    size = enemy.size;
    initialHp = enemy.initialHp;
    currentHp = enemy.currentHp;
    alive = enemy.alive;
}

std::ostream &operator<<(std::ostream &os, const Enemy &enemy) {
    os << "hp: " << enemy.currentHp << " alive: " << enemy.alive << "\n";
    return os;
}

bool Enemy::getAlive() const {
    return alive;
}

void Enemy::setAlive(bool halive) {
    Enemy::alive = halive;
}

int Enemy::getCurrentHp() const {
    return currentHp;
}

int Enemy::getInitialHp() const {
    return initialHp;
}

void Enemy::setInitialHp(int initialhp) {
    Enemy::initialHp = initialhp;
}
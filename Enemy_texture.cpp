#include "Enemy_texture.h"

class TextureException : public std::exception {
public:
    [[nodiscard]] static const char *background() noexcept { return "Enemy texture loading error"; }
};

///Constructor
Enemy_texture::Enemy_texture() {
    srand(time(nullptr));
    int random=rand()%4;
    if (!texture.loadFromFile(skin[random])) {
        throw TextureException();
    }
    this->body.setTexture(texture);
    this->body.setPosition(position[random][0], position[random][1]);
    std::cout << "-Enemy_texture a fost creat\n";
}

///Getters and setters
void Enemy_texture::renderEnemy(sf::RenderWindow &window) {
    window.draw(this->body);
}

///Function
std::shared_ptr<Enemy> Enemy_texture::clone() const {
    return std::make_shared<Enemy_texture>(*this);
}

void Enemy_texture::DamageEnemy(sf::Vector2f mousePositionView, int click_damage) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->body.getGlobalBounds().contains(mousePositionView) and this->currentHp > 0) {
            this->currentHp = this->currentHp - click_damage;
        }
        if (this->currentHp <= 0)
            this->alive = false;
    }

}

void Enemy_texture::NextEnemy(sf::Vector2f mousePositionView, const sf::RectangleShape &buttonNext) {
    int random=rand()%4;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        if (buttonNext.getGlobalBounds().contains(mousePositionView) and this->alive == 0) {
            this->initialHp = rand() % this->initialHp % 5 + this->initialHp;
            this->currentHp = this->initialHp;
            if (!texture.loadFromFile(skin[random])) {
                throw TextureException();
            }
            this->body.setTexture(texture);
            this->body.setPosition(position[random][0], position[random][1]);
            this->alive = true;
        }
}
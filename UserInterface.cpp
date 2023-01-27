#include "UserInterface.h"
#include "Game.h"

///Constructor and Destructor
UserInterface::UserInterface() {
    this->button.setPosition(500.f, 635.f);
    this->button.setSize(sf::Vector2f(65.f, 65.f));
    this->button.setFillColor(sf::Color::Yellow);
    this->button.setOutlineColor(sf::Color::Black);
    this->button.setOutlineThickness(4.f);
    std::cout << "Constructor de butoane\n";
}

UserInterface::~UserInterface() = default;

///Operators
std::ostream &operator<<(std::ostream &os, const UserInterface &userInterface) {
    os << "button x: " << userInterface.button.getPosition().x << "button y: " << userInterface.button.getPosition().y;
    return os;
}

///Getter
const sf::RectangleShape &UserInterface::getButton() const {
    return button;
}
///Function

void UserInterface::MoreDamage(sf::Vector2f mousePositionView, int &price, int &coins) {
    if (coins >= price)
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and
            this->button.getGlobalBounds().contains(mousePositionView)) {
            Game::setClickDamage(Game::getClickDamage() + 1);
            coins -= price;
            price *= 2;
        }
}

void UserInterface::Colors(int price, int coins) {
    if (coins >= price)
        this->button.setFillColor(sf::Color::Green);
    else
        this->button.setFillColor(sf::Color::Yellow);
}



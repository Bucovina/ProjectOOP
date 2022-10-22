#include "UserInterface.h"

///Constructor and Destructor
UserInterface::UserInterface() {
    this->button.setPosition(4.f, 696.f);
    this->button.setSize(sf::Vector2f(592.f, 100.f));
    this->button.setFillColor(sf::Color::White);
    this->button.setOutlineColor(sf::Color::Black);
    this->button.setOutlineThickness(4.f);
}

///Getter
const sf::RectangleShape &UserInterface::getButton() const {
    return button;
}

UserInterface::~UserInterface() = default;

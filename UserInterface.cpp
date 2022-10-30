#include "UserInterface.h"

///Constructor and Destructor
UserInterface::UserInterface() {
    this->button.setPosition(4.f, 696.f);
    this->button.setSize(sf::Vector2f(592.f, 100.f));
    this->button.setFillColor(sf::Color::Green);
    this->button.setOutlineColor(sf::Color::Black);
    this->button.setOutlineThickness(4.f);
}
UserInterface::~UserInterface() = default;

///Getter
const sf::RectangleShape &UserInterface::getButton() const {
    return button;
}

///Operators
std::ostream &operator<<(std::ostream &os, const UserInterface &userInterface) {
    os << "button x: " << userInterface.button.getPosition().x<<"button y: "<<userInterface.button.getPosition().y;
    return os;
}



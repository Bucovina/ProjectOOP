#include "UserInterface.h"

///Constructor and Destructor
UserInterface::UserInterface() {
    this->button.setPosition(4.f, 696.f);
    this->button.setSize(sf::Vector2f(592.f, 100.f));
    this->button.setFillColor(sf::Color::Red);
    this->button.setOutlineColor(sf::Color::Black);
    this->button.setOutlineThickness(4.f);

    this->backGround.setPosition(4.f, 696.f);
    this->backGround.setSize(sf::Vector2f(592.f, 100.f));
    this->backGround.setFillColor(sf::Color(191, 191, 191,250));
    this->backGround.setOutlineColor(sf::Color::Black);
    this->backGround.setOutlineThickness(4.f);

    font.loadFromFile("FreeSans-1Zge.otf");
    this->text.setFont(font);
    this->text.setString("Next Enemy!");
    this->text.setFillColor(sf::Color::Black);
    this->text.setCharacterSize(30);
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

const sf::RectangleShape &UserInterface::getBackGround() const {
    return backGround;
}

const sf::Text &UserInterface::getText() const {
    return text;
}

///Function
void UserInterface::setOn() {
    this->button.setPosition(4.f, 696.f);
    this->button.setSize(sf::Vector2f(592.f, 100.f));
    this->button.setFillColor(sf::Color::Cyan);
    this->button.setOutlineColor(sf::Color::Black);
    this->button.setOutlineThickness(4.f);

    this->text.setString("Next Enemy!");
    this->text.setPosition(220.f,725.f);
}

void UserInterface::setOff(int currentHp, int initialHp) {
    this->button.setPosition(4.f, 696.f);
    this->button.setSize(sf::Vector2f((592.f/(float)initialHp)*(float)currentHp, 100.f));
    this->button.setFillColor(sf::Color::Green);
    this->button.setOutlineColor(sf::Color::Black);
    this->button.setOutlineThickness(4.f);

    this->text.setString("");
}

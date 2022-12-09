#include "UI_Text.h"

#include <utility>

///Constructor and Destructor
UI_Text::UI_Text() {
    this->backGround.setPosition(4.f, 746.f);
    this->backGround.setSize(sf::Vector2f(592.f, 50.f));
    this->backGround.setFillColor(sf::Color(191, 191, 191, 250));
    this->backGround.setOutlineColor(sf::Color::Black);
    this->backGround.setOutlineThickness(4.f);

    font.loadFromFile("FreeSans-1Zge.otf");
    this->text.setFont(font);
    this->text.setString("Next Enemy!");
    this->text.setFillColor(sf::Color::Black);
    this->text.setCharacterSize(30);
}

///Getter
const sf::Text &UI_Text::getText() const {
    return text;
}

const sf::RectangleShape &UI_Text::getBackGround() const {
    return backGround;
}


///Function
void UI_Text::setOn() {
    this->button.setPosition(4.f, 746.f);
    this->button.setSize(sf::Vector2f(592.f, 50.f));
    this->button.setFillColor(sf::Color::Cyan);
    this->button.setOutlineColor(sf::Color::Black);
    this->button.setOutlineThickness(4.f);

    this->text.setString("Next Enemy!");
    this->text.setPosition(220.f, 750.f);
}

void UI_Text::setOff(int currentHp, int initialHp) {
    this->button.setPosition(4.f, 746.f);
    this->button.setSize(sf::Vector2f((592.f / (float) initialHp) * (float) currentHp, 50.f));
    this->button.setFillColor(sf::Color::Green);
    this->button.setOutlineColor(sf::Color::Black);
    this->button.setOutlineThickness(4.f);

    std::string string = "HP: ";
    string += std::to_string(currentHp);
    this->text.setPosition(10.f, 700.f);
    this->text.setString(string);
}

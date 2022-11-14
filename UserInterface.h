#ifndef MAIN_CPP_USERINTERFACE_H
#define MAIN_CPP_USERINTERFACE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Enemy.h"

class UserInterface {
private:
    ///UI
    sf::RectangleShape button;
    sf::RectangleShape backGround;
    sf::Text text;
    sf::Font font;

public:
    ///Constructor and Destructor
    UserInterface();

    ~UserInterface();

    ///Operators
    friend std::ostream &operator<<(std::ostream &os, const UserInterface &anInterface);

    ///Getter
    const sf::RectangleShape &getButton() const;

    const sf::RectangleShape &getBackGround() const;

    const sf::Text &getText() const;

    ///Function
    void setOff(int currentHp,int initialHp);

    void setOn();
};
#endif //MAIN_CPP_USERINTERFACE_H
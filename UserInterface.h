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
protected:
    ///UI
    sf::RectangleShape button;

public:
    ///Constructor and Destructor
    UserInterface();

    virtual ~UserInterface();

    ///Operators
    friend std::ostream &operator<<(std::ostream &os, const UserInterface &anInterface);

    ///Getter
    const sf::RectangleShape &getButton() const;

    ///Function
    void MoreDamage(sf::Vector2f mousePositionView,int &price,int &coins);

    void Colors(int price,int coins);
};

#endif //MAIN_CPP_USERINTERFACE_H
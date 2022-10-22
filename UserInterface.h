#ifndef MAIN_CPP_USERINTERFACE_H
#define MAIN_CPP_USERINTERFACE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class UserInterface {
private:
    ///UI
    sf::RectangleShape button;

public:
    ///Constructor and Destructor
    UserInterface();

    ~UserInterface();

    ///Operators


    ///Getter
    const sf::RectangleShape &getButton() const;
};


#endif //MAIN_CPP_USERINTERFACE_H
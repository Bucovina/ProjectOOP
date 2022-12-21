#ifndef GAME_CPP_UI_TEXT_H
#define GAME_CPP_UI_TEXT_H

#include "UserInterface.h"

class UI_Text : public UserInterface {
private:
    ///UI
    sf::Text text;
    sf::Font font;
    sf::RectangleShape backGround;

    ///Game logic
    bool check = false;

public:
    ///Constructor and Destructor
    UI_Text();

    ///Getter
    const sf::Text &getText() const;

    const sf::RectangleShape &getBackGround() const;

    ///Function
    void setOff(int currentHp, int initialHp);

    void setOn();

    void updateCoinsScore(int coins, int score);
};


#endif //GAME_CPP_UI_TEXT_H

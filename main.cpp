#include "Game.h"

int Game::click_damage = 1;

int main() {
    ///Initialize Game
    Game game;
    ///Game loop
    while (game.runningGame()) {
        ///Update
        game.update();

        ///Render
        game.render();
    }
    return 0;
}
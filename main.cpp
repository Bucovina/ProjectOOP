#include "Game.h"

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
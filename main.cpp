#include "Game.h"

int Game::click_damage = 1;

int main() {
    srand(time(nullptr));
    ///Initialize Game
    try {
        Game game;
        ///Game loop
        while (game.runningGame()) {
            ///Update
            game.update();

            ///Render
            game.render();
        }
    }catch (FontException &err) {
        std::cout << err.font() << "\n";
    }
    catch (BackgroundException &err) {
        std::cout << err.background() << "\n";
    }
        return 0;
}
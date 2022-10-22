#include "Game.h"
///#include "Enemy.h"

///Private functions
void Game::initializeVariables() {
    ///Window
    this->window = nullptr;

    ///Game logic
    this->coins = 0;
    this->score = 0;
}

void Game::initializeWindow() {
    this->videoMode.height = 800;
    this->videoMode.width = 600;

    this->window = new sf::RenderWindow(this->videoMode, "Clicker-Game", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

///Constructor and Destructor
Game::Game() {
    this->initializeVariables();
    this->initializeWindow();
    enemy = new Enemy{};
}

Game::~Game() {
    delete this->window;
}

///Operators
std::ostream &operator<<(std::ostream &os, const Game &game) {
    os << "coins: " << game.coins << " score: " << game.score << " enemy: " << game.enemy;
    return os;
}

///Accessors
bool Game::runningGame() const {
    return this->window->isOpen();
}

///Functions
void Game::pollEvent() {
    ///Event polling
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
            default:
                break;
        }
    }
}

///Mouse position relative to the window/ view
void Game::updateMousePosition() {
    this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
    this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
    ///std::cout<<mousePositionWindow.x<<" "<<mousePositionWindow.y<<"\n";
}

void Game::update() {
    this->pollEvent();
    this->updateMousePosition();
    enemy->UpdateEnemy(this->mousePositionView);
    std::cout << *enemy;
}

void Game::render() {
    ///Clear old frame
    this->window->clear(sf::Color::White);
    ///Draw game aka render objects
    if (enemy->getAlive())
        this->window->draw(enemy->renderEnemy());
    this->window->draw(UI.getButton());
    ///Display what was drawn
    this->window->display();
}
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

void Game::initializeBackground() {
    if (!this->backgroundTexture.loadFromFile("background.jpg")) {
        throw BackgroundExceprion{};
    }
    this->background.setTexture(this->backgroundTexture);
}

void Game::initializeTips() {
    if (!font.loadFromFile("textfont.otf")) {
        throw FontException();
    }
    this->tips.setFont(font);
    this->tips.setString(text[rand()%4]);
    this->tips.setFillColor(sf::Color::White);
    this->tips.setCharacterSize(30);
    this->tips.setPosition(0.f, 100.f);
}

///Constructor and Destructor
Game::Game() {
    this->initializeVariables();
    try {
        this->initializeBackground();
    } catch (BackgroundExceprion& err) {
        std::cout <<err.background()<< "\n";
    }
    this->initializeWindow();
    this->initializeTips();
}

Game::~Game() {
    delete this->window;
}

///Operators
std::ostream &operator<<(std::ostream &os, const Game &game) {
    os << "coins: " << game.coins << " score: " << game.score << " enemy: " << game.enemy;
    return os;
}

///Getter and Setter
const sf::Vector2f &Game::getMousePositionView() const {
    return mousePositionView;
}

int Game::getClickDamage() {
    return click_damage;
}

void Game::setClickDamage(int clickDamage) {
    click_damage = clickDamage;
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
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    this->enemy.DamageEnemy(this->getMousePositionView(), click_damage);
                    std::cout << enemy;
                    this->enemy.NextEnemy(this->getMousePositionView(), this->NextEnemyButton.getButton());
                    this->UpgradeButton.MoreDamage(this->getMousePositionView());
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left) {
                }
            default:
                break;
        }
    }
}

///Mouse position relative to the window/ view
void Game::updateMousePosition() {
    this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
    this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
    ///std::cout<<mousePositionWindow.x<<" "<<mousePositionWindow.y<<"\n";                      ///Position testing
}

void Game::update() {
    this->pollEvent();
    this->updateMousePosition();
    if (enemy.getAlive() == 0)
        this->NextEnemyButton.setOn();
    else
        this->NextEnemyButton.setOff(this->enemy.getCurrentHp(), this->enemy.getInitialHp());
}

void Game::render() {
    ///Clear old frame
    this->window->clear(sf::Color::White);
    ///Draw game aka render objects
    this->window->draw(background);
    if (enemy.getAlive())
        this->window->draw(enemy.renderEnemy());
    this->window->draw(NextEnemyButton.getBackGround());
    this->window->draw(NextEnemyButton.getButton());
    this->window->draw(NextEnemyButton.getText());
    this->window->draw(UpgradeButton.getButton());
    this->window->draw(tips);
    ///Display what was drawn
    this->window->display();
}


///Game(const Game&) = delete;
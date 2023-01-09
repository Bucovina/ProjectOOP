#include "Game.h"
///#include "Enemy.h"

///Private functions
void Game::initializeVariables() {
    ///Window
    this->window = nullptr;
    initializeWindow();
    ///Game logic
    this->coins = 0;
    this->score = 0;
    enemy = std::make_shared<Enemy_texture>();
    enemy->setAlive(true);

    auto *co = dynamic_cast<UI_Text *>(&Test);
    std::cout << "dynamic_cast test: ";
    co->dynamic();
}

void Game::initializeWindow() {
    this->videoMode.height = 800;
    this->videoMode.width = 600;

    this->window = new sf::RenderWindow(this->videoMode, "Clicker-Game", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(30);
}

void Game::initializeBackground() {
    if (!this->backgroundTexture.loadFromFile("background.jpg")) {
        throw BackgroundException{};
    }
    this->background.setTexture(this->backgroundTexture);
}

void Game::initializeTips() {
    if (!font.loadFromFile("textfont.otf")) {
        throw FontException();
    }
    this->tips.setFont(font);
    this->tips.setString(text[rand() % 4]);
    this->tips.setFillColor(sf::Color::White);
    this->tips.setCharacterSize(30);
    this->tips.setPosition(5.f, 56.f);
}

///Constructor and Destructor
Game::Game() {
    this->initializeVariables();
    this->initializeBackground();
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

                    hp = enemy->getInitialHp();
                    if (this->enemy->getAlive()) {
                        this->enemy->DamageEnemy(this->getMousePositionView(), click_damage);
                        this->check = true;
                        if (!this->enemy->getAlive()) {
                            this->coins += enemy->getInitialHp() / 10;
                            this->score += enemy->getInitialHp();
                            enemy = enemies[rand()%enemies.size()];
                            enemy->setInitialHp(hp);
                        }
                    }
                    this->enemy->NextEnemy(this->getMousePositionView(), this->NextEnemyButton.getButton());
                    this->UpgradeButton.MoreDamage(this->getMousePositionView());
                }
                break;
            case sf::Event::MouseButtonReleased: {

            }
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
    ///std::cout<<mousePositionWindow.x<<" "<<mousePositionWindow.y<<"\n";                      ///Position testing
}

void Game::update() {
    this->pollEvent();
    this->updateMousePosition();

    if (enemy->getAlive() == 0)
        this->NextEnemyButton.setOn();
    else
        this->NextEnemyButton.setOff(this->enemy->getCurrentHp(), this->enemy->getInitialHp());
    this->CoinsScoreUI.updateCoinsScore(coins, score);
}

void Game::render() {
    ///Clear old frame
    this->window->clear(sf::Color::White);
    ///Draw game aka render objects
    this->window->draw(background);
    if (enemy->getAlive())
        enemy->renderEnemy(*window);
    this->window->draw(NextEnemyButton.getBackGround());
    this->window->draw(NextEnemyButton.getButton());
    this->window->draw(NextEnemyButton.getText());
    this->window->draw(CoinsScoreUI.getButton());
    this->window->draw(CoinsScoreUI.getText());
    this->window->draw(UpgradeButton.getButton());
    if (check == 0)
        this->window->draw(tips);
    ///Display what was drawn
    this->window->display();
}
///Game(const Game&) = delete;
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
// #include <chrono>
// #include <thread>

class SomeClass {
public:
    explicit SomeClass(int) {}
};

SomeClass *getC() {
    return new SomeClass{2};
}

int main() {
    SomeClass *c = getC();
    std::cout << c << "\n";
    delete c;

    sf::RenderWindow window;
    window.create(sf::VideoMode({800, 700}), "My Window", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);

    while(window.isOpen()) {
        sf::Event e;
        while(window.pollEvent(e)) {
            switch(e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
                break;
            case sf::Event::KeyPressed:
                std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                break;
            default:
                break;
            }
        }
        // using namespace std::chrono_literals;
        // std::this_thread::sleep_for(8000ms);

        window.clear();
        window.display();
    }

    return 0;
}

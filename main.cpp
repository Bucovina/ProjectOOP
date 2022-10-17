#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
    ///Window
    sf::RenderWindow window(sf::VideoMode(800,600),"ProjectPOO",sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;

    ///Game loop
    while(window.isOpen())
    {
        ///Event polling
        while(window.pollEvent( event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
                default:
                    break;
            }
        }

        ///Update

        ///Render
        window.clear(sf::Color::Magenta); ///Clear old frame
        ///Drawing zone

        window.display(); ///Render after everything is finished drawing
    }
    return 0;
}
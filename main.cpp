#include <iostream>
#include <SFML/Window.hpp>

int main() {
    sf::Window main_display;
    main_display.create(sf::VideoMode({800 , 600}), "Chapter 2: and one to burn it", sf::Style::Default, sf::State::Windowed);
    while(main_display.isOpen()) {
        while(const std::optional event = main_display.pollEvent()) {
            if(event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) { main_display.close(); }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) { std::cout << "left" << std::endl; }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) { std::cout << "right" << std::endl; }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) { std::cout << "down" << std::endl; }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) { std::cout << "up" << std::endl; }
        }
    }
}
namespace chapter2 {}

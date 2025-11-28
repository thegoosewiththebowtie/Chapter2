#include <iostream>
#include <SFML/Window.hpp>

#include "src/common.h"
#include "src/initializer.h"

int main() {
    chapter2::initializer::Initializer::xctInitConfig();
    sf::Window main_display;
    main_display.create(sf::VideoMode({800 , 600}), "Chapter 2: and one to burn it", sf::Style::Default, sf::State::Windowed);
    while(main_display.isOpen()) {
        while(const std::optional event = main_display.pollEvent()) {
            if(event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) { main_display.close(); }
            if(event->is<sf::Event::KeyPressed>()) {

            }
        }
        if(chapter2::common::gxctIsKeyPressed(chapter2::common::eMainKeys::LEFT)) { std::cout << "left" << std::endl; }
        if(chapter2::common::gxctIsKeyPressed(chapter2::common::eMainKeys::RIGHT)) { std::cout << "right" << std::endl; }
        if(chapter2::common::gxctIsKeyPressed(chapter2::common::eMainKeys::DOWN)) { std::cout << "down" << std::endl; }
        if(chapter2::common::gxctIsKeyPressed(chapter2::common::eMainKeys::UP)) { std::cout << "up" << std::endl; }
        if(chapter2::common::gxctIsKeyPressed(chapter2::common::eMainKeys::PROCEED)) { std::cout << "proceed" << std::endl; }
        if(chapter2::common::gxctIsKeyPressed(chapter2::common::eMainKeys::BACK)) { std::cout << "back" << std::endl; }
        if(chapter2::common::gxctIsKeyPressed(chapter2::common::eMainKeys::MENU)) { std::cout << "menu" << std::endl; }
    }
}

namespace chapter2 {}

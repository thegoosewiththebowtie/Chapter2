/*[≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
/*[≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡Created by Lizzie on TE259|11|29≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
#include <iostream>
#include <SFML/Window.hpp>

#include "src/totw_vas_initializer.hpp"
#include "src/cmmn/totw_data_structs.hpp"
#include "src/ctrl/totw_invoker.hpp"

int main() {
    ToTW_VAS::ToTW_VasInitializer::Initializer::xctInitConfig();
    ToTW_VAS::CMMN::sGlobal::_main_display.create(sf::VideoMode({800 , 600})
                                                       , L"Vessel Access System\u2122 | powered by ToTW: Connect\u00AE "
                                                       , sf::Style::Default
                                                       , sf::State::Windowed);
    ToTW_VAS::CMMN::sGlobal::_main_display.setKeyRepeatEnabled(false);
    while(ToTW_VAS::CMMN::sGlobal::_main_display.isOpen()) {
        while(std::optional<sf::Event> event = ToTW_VAS::CMMN::sGlobal::_main_display.pollEvent()) {
            if (!event.has_value()){continue;}
            if(event.value().is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                ToTW_VAS::CMMN::sGlobal::_main_display.close();
            }
            if (event.value().is<sf::Event::KeyPressed>()) {
                ToTW_VAS::CTRL::Invoker::xctSelectCheckRunEvent(event.value().getIf<sf::Event::KeyPressed>());
            }
            if (event.value().is<sf::Event::KeyReleased>()) {
                ToTW_VAS::CTRL::Invoker::xctSelectCheckRunEvent(event.value().getIf<sf::Event::KeyReleased>());
            }
        }
    }
}

namespace ToTW_VAS {
}
/*[≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */

/*[≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
/*[≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡Created by Lizzie on TE259|11|29≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
#pragma once
#include <utility>
#include "totw_enums.hpp"
#include "totw_room.hpp"
#include "unordered_map"
#include "vector"
#include "../../lib/json.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Window.hpp"
namespace ToTW_VAS::CMMN {
    using key_TD = sf::Keyboard::Key;
    struct sState {
        bool _is_holdable_key[static_cast<int>(eMainKeys::SIZE)] = {false // PROCEED
                                                                  , false // BACK
                                                                  , false // MENU
                                                                  , false // LEFT
                                                                  , false  // RIGHT
                                                                  , false  // UP
                                                                  , false// DOWN
                                                                   ,};
        eControlState                         _control_state = eControlState::MAIN_MENU;
        std::unique_ptr<ToTW_ROOM_BASE> _current_room  = nullptr;
    };
    struct sConfig {
        //[CONTROL]
        std::array<std::vector<sf::Keyboard::Key> , static_cast<int>(eMainKeys::SIZE)> _keys{std::vector{key_TD::Enter , key_TD::Z} // PROCEED
                                                                                           , std::vector{key_TD::RShift , key_TD::LShift , key_TD::X} // BACK
                                                                                           , std::vector{key_TD::RControl
                                                                                                       , key_TD::LControl
                                                                                                       , key_TD::C} // MENU
                                                                                           , std::vector{key_TD::Left , key_TD::A} // LEFT
                                                                                           , std::vector{key_TD::Right , key_TD::D}  // RIGHT
                                                                                           , std::vector{key_TD::Up , key_TD::W} // UP
                                                                                           , std::vector{key_TD::Down , key_TD::S}}; // DOWN
        //[VIDEO]
        bool _vsync      = true;
        bool _fullscreen = false;
        bool _autorun    = false;
        //[AUDIO]
        uint32_t _global_volume = 100;
        //[UI]
        std::string _color1 = "FFFFFF";
        std::string _color2 = "000000";
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(sConfig, _keys, _vsync, _fullscreen, _autorun, _global_volume);

    struct sSave {
        std::string _location;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(sSave, _location)
}

/*[≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */

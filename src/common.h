/* [≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
#pragma once
#include <utility>

#include "iostream"
#include "unordered_map"
#include "vector"
#include "../lib/json.hpp"
#include "SFML/Window/Keyboard.hpp"

namespace chapter2::common {
    enum class eMainKeys { PROCEED , BACK , MENU , LEFT , RIGHT , UP , DOWN , };
    using key_TD = sf::Keyboard::Key;
    class FatalMistake final : public std::exception {
        std::string message_;
        void        xctAct() const { std::cerr << message_ << std::endl; }
        public:
            explicit                  FatalMistake(std::string arg_message) : message_(std::move(arg_message)) { xctAct(); }
            [[nodiscard]] const char* what() const noexcept override { return message_.c_str(); }
    };
    struct sConfig {
        //[CONTROL]
        std::unordered_map<eMainKeys , std::vector<sf::Keyboard::Key>> _keys{{eMainKeys::PROCEED , {key_TD::Enter , key_TD::Z}}
                                                                           , {eMainKeys::BACK , {key_TD::RShift , key_TD::LShift , key_TD::X}}
                                                                           , {eMainKeys::MENU , {key_TD::RControl , key_TD::LControl , key_TD::C}}
                                                                           , {eMainKeys::LEFT , {key_TD::Left, key_TD::A}}
                                                                           , {eMainKeys::RIGHT , {key_TD::Right, key_TD::D}}
                                                                           , {eMainKeys::UP , {key_TD::Up, key_TD::W}}
                                                                           , {eMainKeys::DOWN , {key_TD::Down, key_TD::S}}};
        //[VIDEO]
        bool _vsync      = true;
        bool _fullscreen = false;
        bool _autorun    = false;
        //[AUDIO]
        uint32_t _global_volume = 100;
        //[UI]
        std::string color1 = "FFFFFF";
        std::string color2 = "000000";
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(sConfig, _keys, _vsync, _fullscreen, _autorun, _global_volume);
    struct sSave {
        std::string _location;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(sSave, _location);
    struct sState {
        bool _is_holdable_key[static_cast<size_t>(7)] = {
            false,  // PROCEED (menu confirm)
            false,  // BACK
            false,  // MENU
            false,   // LEFT (movement)
            false,   // RIGHT
            false,   // UP
            false,   // DOWN
        };
    };
    struct sGlobalStuff {
        static sConfig _config;
        static sSave _save;
    };
    inline bool gxctIsKeyPressed(const eMainKeys arg_key) {
        return std::any_of(
            sGlobalStuff::_config._keys[arg_key].begin(),
            sGlobalStuff::_config._keys[arg_key].end(),
            [](auto arg_check_key) { return sf::Keyboard::isKeyPressed(arg_check_key); }
        );
    }
}
/* [≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */

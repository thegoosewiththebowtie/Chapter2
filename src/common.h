/* [≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
#pragma once
#include <utility>

#include "iostream"
#include "stdexcept"
#include "unordered_map"
#include "vector"
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
                                                                           , {eMainKeys::LEFT , {key_TD::Left}}
                                                                           , {eMainKeys::RIGHT , {key_TD::Right}}
                                                                           , {eMainKeys::UP , {key_TD::Up}}
                                                                           , {eMainKeys::DOWN , {key_TD::Down}}};
        //[VIDEO]
        bool _vsync      = true;
        bool _fullscreen = false;
        bool _autorun    = false;
        //[AUDIO]
        uint32_t _global_volume = 100;
        //[UI]
        std::string color1 = "FFFFFF";
        std::string color2 = "000000";

        template<typename tValueType>
        void xctSet(const std::string& arg_group , const std::string& arg_key , tValueType arg_value);
    };
}
/* [≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */

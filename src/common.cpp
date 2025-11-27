/* [≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
//
// Created by Vlada on 11/27/2025.
//

#include "common.h"

namespace chapter2::common {
    template<typename tValueType>
    void sConfig::xctSet(const std::string& arg_group , const std::string& arg_key , tValueType arg_value) {
        switch(arg_group[0]) {
            case 'c' : if(!std::is_same_v<tValueType , std::vector<sf::Keyboard::Key>>) { throw FatalMistake(arg_group); }
                switch(arg_key[0]) {
                    case 'p' : _keys[eMainKeys::PROCEED] = arg_value;
                        break;
                    case 'b' : _keys[eMainKeys::BACK] = arg_value;
                        break;
                    case 'm' : _keys[eMainKeys::MENU] = arg_value;
                        break;
                    case 'l' : _keys[eMainKeys::LEFT] = arg_value;
                        break;

                    case 'r' : _keys[eMainKeys::RIGHT] = arg_value;
                        break;
                    case 'u' : _keys[eMainKeys::UP] = arg_value;
                        break;
                    case 'd' : _keys[eMainKeys::DOWN] = arg_value;
                        break;
                    default : throw FatalMistake(arg_key);
                }
                break;
            case 'v' : switch(arg_key[0]) {
                    case 'v' : _vsync = arg_value;
                        break;
                    case 'f' : _fullscreen = arg_value;
                        break;
                    case 'a' : _autorun = arg_value;
                        break;
                    default : throw FatalMistake(arg_key);
                }
                break;
            case 'a' : switch(arg_key[0]) {
                    case 'g' : _global_volume = arg_value;
                        break;
                    default : throw FatalMistake(arg_key);
                }
            case 'u' : break;
            default : throw FatalMistake(arg_group);
        }
    }
}
/* [≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */

/*[≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
/*[≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡Created by Lizzie on TE259|11|29≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
#pragma once
#include "../cmmn/totw_data_structs.hpp"
#include "../cmmn/totw_global.hpp"

namespace ToTW_VAS::CTRL {
    class Invoker {
        static void xctRunEvent(int arg_mainkeys , const bool arg_uninvoke) {
            switch(static_cast<CMMN::eMainKeys>(arg_mainkeys)) {
                case CMMN::eMainKeys::PROCEED : CMMN::sGlobal::_control.xctInvokeProceed(arg_uninvoke);
                    break;
                case CMMN::eMainKeys::BACK : CMMN::sGlobal::_control.xctInvokeBack(arg_uninvoke);
                    break;
                case CMMN::eMainKeys::MENU : CMMN::sGlobal::_control.xctInvokeMenu(arg_uninvoke);
                    break;
                case CMMN::eMainKeys::LEFT : CMMN::sGlobal::_control.xctInvokeLeft(arg_uninvoke);
                    break;
                case CMMN::eMainKeys::RIGHT : CMMN::sGlobal::_control.xctInvokeRight(arg_uninvoke);
                    break;
                case CMMN::eMainKeys::UP : CMMN::sGlobal::_control.xctInvokeUp(arg_uninvoke);
                    break;
                case CMMN::eMainKeys::DOWN : CMMN::sGlobal::_control.xctInvokeDown(arg_uninvoke);
                    break;
                case CMMN::eMainKeys::SIZE : throw CMMN::FatalMistake("OUT OF RANGE KEY");
            }
        }

        template<typename tKeyAct> requires std::is_same_v<tKeyAct , sf::Event::KeyPressed> || std::is_same_v<tKeyAct , sf::Event::KeyReleased>
        static bool xctCheckEvent(const tKeyAct* arg_event , const size_t arg_key_index) {  // eMainKeys
            const auto& check_keys = CMMN::sGlobal::_config->_keys[arg_key_index];
            for(sf::Keyboard::Key check_key : check_keys) { if(arg_event->code == check_key) { return true; } } // NOLINT(*-use-anyofallof)
            return false;
        }

        template<typename tKeyAct> requires std::is_same_v<tKeyAct , sf::Event::KeyPressed> || std::is_same_v<tKeyAct , sf::Event::KeyReleased>
        static void xctCheckRunEvent(const tKeyAct* arg_event , int i) {
            if(xctCheckEvent(arg_event, i)) { xctRunEvent(i, std::is_same_v<tKeyAct , sf::Event::KeyReleased>); }
        }
        public:
            template<typename tKeyAct> requires std::is_same_v<tKeyAct , const sf::Event::KeyPressed*> || std::is_same_v<
                tKeyAct , const sf::Event::KeyReleased*>
            static void xctSelectCheckRunEvent(tKeyAct arg_event) {
                for(int i = 0 ; i < static_cast<int>(CMMN::eMainKeys::SIZE) ; ++i) { xctCheckRunEvent(arg_event, i); }
            }
    };
}
/*[≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */

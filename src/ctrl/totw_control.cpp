/*[≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
/*[≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡Created by Lizzie on TE259|11|28≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
#include "totw_control.hpp"
#include "iostream"

namespace ToTW_VAS::CTRL {
    void Control::xctInvokeProceed(bool uninvoke) {
        std::cout << (uninvoke ? "un" : "") << "proceed" << std::endl;
    }

    void Control::xctInvokeBack(bool uninvoke) {
        std::cout <<(uninvoke ? "un" : "") << "back" << std::endl;
    }

    void Control::xctInvokeMenu(bool uninvoke) {
        std::cout <<(uninvoke ? "un" : "") << "menu" << std::endl;
    }

    void Control::xctInvokeLeft(bool uninvoke) {
        std::cout <<(uninvoke ? "un" : "") << "left" << std::endl;
    }

    void Control::xctInvokeRight(bool uninvoke) {
        std::cout << (uninvoke ? "un" : "") <<"right" << std::endl;
    }

    void Control::xctInvokeUp(bool uninvoke) {
        std::cout << (uninvoke ? "un" : "") <<"up" << std::endl;
    }

    void Control::xctInvokeDown(bool uninvoke) {
        std::cout << (uninvoke ? "un" : "") <<"down" << std::endl;
    }
}
/*[≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */

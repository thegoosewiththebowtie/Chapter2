/* [≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
//
// Created by Vlada on 11/27/2025.
//
#include "initializer.h"
#include <filesystem>
#include <shlobj.h>
#include <windows.h>

#include "fstream"

namespace chapter2::initializer {
    std::string Initializer::xctGetConfigPath() {
        CHAR path[MAX_PATH];
        // CSIDL_LOCAL_APPDATA
        if(!SUCCEEDED(SHGetFolderPathA(nullptr, CSIDL_APPDATA, nullptr, 0, path))) {
            throw common::FatalMistake("config file is not configured. somehow");// Fallback
        }
        std::string retpath = std::string(path) + R"(\ToTW org\Chapter 2\)";
        std::filesystem::create_directories(retpath);
        return retpath;
    }

    void Initializer::xctInitConfig() {
            const std::string config_path = xctGetConfigPath();
            std::filesystem::create_directories(config_path + "config\\");
            std::filesystem::create_directories(config_path + "logs\\");
            std::filesystem::create_directories(config_path + "cache\\");
            std::filesystem::create_directories(config_path + "saves\\");
    }

    common::sConfig Parser::xctGetConfig(std::string arg_path) {
        common::sConfig retconfig;
        std::ifstream   file(arg_path);
        std::string       line;
        while(std::getline(file, line)) {
            if (line.empty() || line[0] == '#' ) {
                continue;
            }
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = trim(line.substr(0, pos));
                std::string value = trim(line.substr(pos + 1));
            }
        }
    }
    void            Parser::xctWriteConfig(common::sConfig arg_config , std::string arg_path) {}
}
/* [≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */

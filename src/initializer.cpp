/* [≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
//
// Created by Vlada on 11/27/2025.
//
#include "initializer.h"
#include <shlobj.h>
#include <windows.h>

#include "fstream"
#include "../lib/json.hpp"

namespace chapter2::initializer {
    std::filesystem::path Initializer::xctGetDataPath() {
        CHAR path[MAX_PATH];
        // CSIDL_LOCAL_APPDATA
        if(!SUCCEEDED(SHGetFolderPathA(nullptr, CSIDL_APPDATA, nullptr, 0, path))) {
            throw common::FatalMistake("config file is not configured. somehow");// Fallback
        }
         std::filesystem::path retpath =  std::filesystem::path(path) / "ToTW org"/ "Chapter 2";
        std::filesystem::create_directories(retpath);
        return retpath;
    }

    void Initializer::xctInitConfig() {
        const  std::filesystem::path data_path = xctGetDataPath();
        std::filesystem::create_directories(data_path / "config");
        std::filesystem::create_directories(data_path / "logs");
        std::filesystem::create_directories(data_path / "cache");
        std::filesystem::create_directories(data_path / "saves");
        const std::filesystem::path config_path = data_path / "config" / "config.json";
        if(std::filesystem::exists(config_path)) {
            common::sGlobalStuff::_config = Parser::xctGetConfig(config_path);
        } else {
            common::sGlobalStuff::_config = {};
            Parser::xctWriteConfig(common::sGlobalStuff::_config , config_path);
        }
    }

    common::sConfig Parser::xctGetConfig (const std::filesystem::path& arg_path) {
        std::ifstream in_file(arg_path);
        const nlohmann::json read_json = nlohmann::json::parse(in_file);
        return read_json.get<common::sConfig>();
    }

    void Parser::xctWriteConfig(const common::sConfig& arg_config , const std::filesystem::path& arg_path) {
        const nlohmann::json write_json = arg_config;
        std::ofstream out_file{arg_path};
        out_file << write_json.dump();
    }

    common::sSave Parser::xctGetSaveFile(const std::filesystem::path& arg_path) {
        std::ifstream in_file(arg_path);
        const nlohmann::json read_json = nlohmann::json::parse(in_file);
        return read_json.get<common::sSave>();
    }
    void            Parser::xctWriteSaveFile(const common::sSave& arg_save , const std::filesystem::path& arg_path) {
        const nlohmann::json write_json = arg_save;
        std::ofstream out_file{arg_path};
        out_file << write_json.dump();
    }

}
/* [≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */

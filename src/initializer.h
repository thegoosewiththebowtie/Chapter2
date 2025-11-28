/* [≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */
#pragma once
#include <filesystem>
#include "common.h"
#include "bits/fs_path.h"

namespace chapter2::initializer {
    class Initializer {
        public:
            static std::filesystem::path xctGetDataPath();
            static void                  xctInitConfig();
    };
    class Parser {
        public:
            static common::sConfig xctGetConfig(const std::filesystem::path& arg_path);
            static void            xctWriteConfig(const common::sConfig& arg_config , const std::filesystem::path& arg_path);
            static common::sSave   xctGetSaveFile(const std::filesystem::path& arg_path);
            static void            xctWriteSaveFile(const common::sSave& arg_save , const std::filesystem::path& arg_path);
    };
}
/* [≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡▲≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡] */

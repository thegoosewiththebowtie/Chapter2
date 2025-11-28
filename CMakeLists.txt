cmake_minimum_required(VERSION 3.31)
project(Chapter2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
                     GIT_REPOSITORY https://github.com/SFML/SFML.git
                     GIT_TAG 3.0.2
                     GIT_SHALLOW ON
                     EXCLUDE_FROM_ALL
                     SYSTEM)
FetchContent_MakeAvailable(SFML)
include_directories(lib)
add_executable(Chapter2 main.cpp
               src/initializer.cpp
               src/initializer.h
               src/common.cpp
               src/common.h)
target_compile_features(Chapter2 PRIVATE cxx_std_23)
target_link_libraries(Chapter2 PRIVATE SFML::Graphics)

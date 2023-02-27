cmake_minimum_required(VERSION 3.1...3.24)

project(
    Feather-Engine
    VERSION 1.0
    LANGUAGES CXX
)

set (CMAKE_CXX_STANDARD 20)

set(SOURCES
    feather/components/component.cpp
    feather/components/drawable.cpp
    feather/components/sprite.cpp
    feather/components/transform.cpp
    feather/entities/entity.cpp
    feather/systems/componentsystem.cpp
    feather/systems/entitymanager.cpp
    feather/main.cpp
    feather/resourcemanager.cpp
    feather/vector.cpp
    feather/window.cpp
)

find_library(LIB_IMAGE SDL2_image ./lib/Unix/lib_image)
find_library(LIB_MIXER SDL2_mixer ./lib/Unix/lib_mixer)
find_library(LIB_TTF SDL2_ttf ./lib/Unix/lib_ttf)

find_path(LIB_INCLUDES SDL_image.h ./include/Unix/SDL2)
message(${LIB_INCLUDES})
include_directories(${LIB_INCLUDES})

add_executable(game 
    ${SOURCES}
)

target_include_directories(game
    PRIVATE
        ${PROJECT_SOURCE_DIR}/feather/
        $(PROJECT_SOURCE_DIR)/
)

target_link_libraries(game
    SDL2
    ${LIB_IMAGE}
    ${LIB_MIXER}
    ${LIB_TTF}
)

cmake_minimum_required(VERSION 3.1...3.24)

project(
    Feather-Engine
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

option(DEBUG_ON "Enables DEBUG_MODE macro" ON)
option(DEBUG_TO_FILE "If DEBUG_MODE is on, outputs stream to file Log.txt" OFF)

if(DEBUG_ON)
add_compile_definitions(DEBUG_MODE)
if(DEBUG_TO_FILE)
add_compile_definitions(LOG_TO_FILE)
endif()
endif()


set(SOURCES
    include/Feather/Components/AnimationComponent.cpp
    include/Feather/Components/Component.cpp
    include/Feather/Components/Drawable.cpp
    include/Feather/Components/KeyboardControl.cpp
    include/Feather/Components/SoundEmitter.cpp
    include/Feather/Components/Sprite.cpp
    include/Feather/Components/Transform.cpp
    include/Feather/Components/Velocity.cpp
    include/Feather/Components/Collider.cpp
    include/Feather/Debug/Debug.cpp
    include/Feather/Entities/Entity.cpp
    include/Feather/Systems/AnimationSystem.cpp
    include/Feather/Systems/ComponentSystem.cpp
    include/Feather/Systems/EntityManager.cpp
    include/Feather/Systems/InputManager.cpp
    include/Feather/Systems/KeyboardControlSystem.cpp
    include/Feather/Systems/MovementSystem.cpp
    include/Feather/Systems/RenderSystem.cpp
    include/Feather/Systems/CollisionSystem.cpp
    include/Feather/Windows/View.cpp
    include/Feather/Windows/Window.cpp
    include/Feather/Main.cpp
    include/Feather/ResourceManager.cpp
    include/Feather/Game.cpp
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
        ${PROJECT_SOURCE_DIR}/include/
)

target_link_libraries(game
    SDL2
    ${LIB_IMAGE}
    ${LIB_MIXER}
    ${LIB_TTF}
)

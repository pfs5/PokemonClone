cmake_minimum_required(VERSION 3.6)
project(GameEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp settings/Settings.h game_objects/GameObject.cpp game_objects/GameObject.h game_objects/TestObject.cpp game_objects/TestObject.h maps/Map.cpp maps/Map.h game_objects/Character.cpp game_objects/Character.h game_objects/MainCharacter.cpp game_objects/MainCharacter.h colliders/Collider.h)
add_executable(GameEngine ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(GameEngine ${SFML_LIBRARIES})
endif()
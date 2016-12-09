//
// Created by patrik on 07.12.16..
//

#ifndef GAMEENGINE_SETTINGS_H
#define GAMEENGINE_SETTINGS_H

class Settings {
public:
    // Paths
    static std::string PROJECT_DIR() {return "/home/patrik/Source/C++/GameEngine/";}
    static const std::string MAP_TYPE() {return ".png";}

    // Window
    static const unsigned int WINDOW_WIDTH() {return 600;}
    static const unsigned int WINDOW_HEIGHT() {return 600;}
    static const std::string WINDOW_TITLE() {return "Game";}

    // Graphics
    static const int UPS() {return 100;}
    static const float GAME_SPEED() {return 10;}
    static const int BASE() {return 16;}
    static const int SCALE() {return 2;}
};

#endif //GAMEENGINE_SETTINGS_H

//
// Created by patrik on 09.12.16..
//

#ifndef GAMEENGINE_MAP_H
#define GAMEENGINE_MAP_H

#include <string>
#include <SFML/Graphics/Sprite.hpp>

class Map {
public:
    void loadMap(std::string name);
private:
    sf::Sprite _map;
};


#endif //GAMEENGINE_MAP_H

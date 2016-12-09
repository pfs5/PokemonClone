//
// Created by patrik on 09.12.16..
//

#ifndef GAMEENGINE_MAP_H
#define GAMEENGINE_MAP_H

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Map {
public:
    void loadMap(std::string name);
    void draw(sf::RenderWindow &window);
private:
    sf::Texture _mapTexture;
    sf::Sprite _mapSprite;
};


#endif //GAMEENGINE_MAP_H

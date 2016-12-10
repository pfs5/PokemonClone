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
    void drawTop(sf::RenderWindow &window);
    void drawBottom(sf::RenderWindow &window);
private:
    sf::Texture _mapTextureTop;
    sf::Sprite _mapSpriteTop;

    sf::Texture _mapTextureBottom;
    sf::Sprite _mapSpriteBottom;
};


#endif //GAMEENGINE_MAP_H

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
    static unsigned short getColorData(unsigned int color);

    void loadMap(std::string name);
    void drawTop(sf::RenderWindow &window);
    void drawBottom(sf::RenderWindow &window);

    bool checkCollision(sf::Vector2f pos1, sf::Vector2f pos2);
private:
    sf::Texture _mapTextureTop;
    sf::Sprite _mapSpriteTop;

    sf::Texture _mapTextureBottom;
    sf::Sprite _mapSpriteBottom;

    std::vector<std::vector<unsigned short>> _mapData;

    void loadMapData(std::string name);

};


#endif //GAMEENGINE_MAP_H

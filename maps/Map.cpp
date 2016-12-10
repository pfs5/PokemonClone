//
// Created by patrik on 09.12.16..
//

#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "Map.h"
#include "../settings/Settings.h"

void Map::loadMap(std::string name) {
    std::string pathTop = Settings::PROJECT_DIR() + std::string("resources/maps/") + name + std::string("_top") +
                          Settings::MAP_TYPE();
    std::string pathBottom = Settings::PROJECT_DIR() + std::string("resources/maps/") + name + std::string("_bottom") +
                             Settings::MAP_TYPE();

    // Load texture
    if (!_mapTextureTop.loadFromFile(pathTop)) {
        std::cerr << "Failed to load top map \"" + name + "\"." << std::endl;
        return;
    }
    if (!_mapTextureBottom.loadFromFile(pathBottom)) {
        std::cerr << "Failed to load top map \"" + name + "\"." << std::endl;
        return;
    }

    // Init sprite
    _mapSpriteTop.setTexture(_mapTextureTop);
    _mapSpriteTop.setScale(Settings::SCALE(), Settings::SCALE());

    _mapSpriteBottom.setTexture(_mapTextureBottom);
    _mapSpriteBottom.setScale(Settings::SCALE(), Settings::SCALE());

    std::cerr << "Successfully loaded map \"" + name + "\"." << std::endl;

}

void Map::drawTop(sf::RenderWindow &window) {
    window.draw(_mapSpriteTop);
}

void Map::drawBottom(sf::RenderWindow &window) {
    window.draw(_mapSpriteBottom);
}

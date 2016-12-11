//
// Created by patrik on 09.12.16..
//

#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "Map.h"
#include "../settings/Settings.h"

unsigned short Map::getColorData(unsigned int color) {
    switch (color) {
        case 255:
            return 1;           // collision
        default:
            return 0;           // no data

    }
}

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

    loadMapData(name);

    std::cerr << "Successfully loaded map \"" + name + "\"." << std::endl;
}

void Map::loadMapData(std::string name) {
    std::string pathData = Settings::PROJECT_DIR() + std::string("resources/maps/") + name + std::string("_data") +
                           Settings::MAP_TYPE();
    sf::Image image;
    if (!image.loadFromFile(pathData)) {
        std::cerr << "Failed to load data map \"" + name + "\"." << std::endl;
    }

    //Create data map
    sf::Vector2u size = image.getSize();
    for (unsigned int y = 0; y < size.y; y += Settings::BASE()) {
        std::vector<unsigned short> row;
        for (unsigned int x = 0; x < size.x; x += Settings::BASE()) {
            // TODO
            sf::Color pixel = image.getPixel(x, y);
            row.push_back(Map::getColorData(pixel.toInteger()));
            std::cout << pixel.toInteger() << std::endl;
        }
        _mapData.push_back(row);
    }
}

void Map::drawTop(sf::RenderWindow &window) {
    window.draw(_mapSpriteTop);
}

void Map::drawBottom(sf::RenderWindow &window) {
    window.draw(_mapSpriteBottom);
}


bool Map::checkCollision(sf::Vector2f pos1, sf::Vector2f pos2) {
    int coeff = Settings::SCALE() * Settings::BASE();

    unsigned int x1 = (unsigned int) (pos1.x / coeff);
    unsigned int y1 = (unsigned int) (pos1.y / coeff);

    unsigned int x2 = (unsigned int) (pos2.x / coeff);
    unsigned int y2 = (unsigned int) (pos2.y / coeff);

    return (_mapData[y1][x1] == 1) || (_mapData[y2][x2] == 1);
}



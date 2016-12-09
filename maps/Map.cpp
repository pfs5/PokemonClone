//
// Created by patrik on 09.12.16..
//

#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "Map.h"
#include "../settings/Settings.h"

void Map::loadMap(std::string name) {
    std::string path = Settings::PROJECT_DIR() + std::string("resources/maps/") + name + Settings::MAP_TYPE();

    // Load texture
    if (!_mapTexture.loadFromFile(path)) {
        std::cerr << "Failed to load map \"" + name + "\"." << std::endl;
        return;
    }

    // Init sprite
    _mapSprite.setTexture(_mapTexture);
    _mapSprite.setScale(Settings::SCALE(), Settings::SCALE());

    std::cerr << "Successfully loaded map \"" + name + "\"." << std::endl;

}

void Map::draw(sf::RenderWindow &window) {
    window.draw(_mapSprite);
}

//
// Created by patrik on 09.12.16..
//

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include "Character.h"
#include "../settings/Settings.h"

Character::Character(std::string name) {
    _label = name;

    // Load sprite
    std::string path = Settings::PROJECT_DIR() + std::string("resources/sprites/") + name + Settings::MAP_TYPE();

    // Load texture
    if (!_charTexture.loadFromFile(path)) {
        std::cerr << "Failed to load character \"" + name + "\"." << std::endl;
        return;
    }

    // Init sprite
    _charSprite.setTexture(_charTexture);
    _charSprite.setScale(Settings::SCALE(), Settings::SCALE());
    _charSprite.setTextureRect(sf::IntRect(0, 0, sizeX, sizeY));

    // Set direction
    _direction = Down;
    _counter = 0;

    std::cerr << "Successfully loaded character \"" + name + "\"." << std::endl;

}

void Character::input() {

}

void Character::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        move(Up);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        move(Left);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        move(Down);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        move(Right);
    }
}

void Character::draw(sf::RenderWindow *window) {
    window->draw(_charSprite);
}

void Character::move(Character::Direction dir) {
    // Changing direction
    if (_direction != dir) {
        _counter = 1;
    } else {
        _counter++;
        _counter %= 3;
    }
    _charSprite.setTextureRect(sf::IntRect(_counter * sizeX, getDirectionIndex(dir) * sizeY, sizeX, sizeY));

    _direction = dir;

    // Moving
    switch (dir) {
        case Up:
            _charSprite.move(0, -Settings::GAME_SPEED());
            break;
        case Down:
            _charSprite.move(0, Settings::GAME_SPEED());
            break;
        case Left:
            _charSprite.move(-Settings::GAME_SPEED(), 0);
            break;
        case Right:
            _charSprite.move(Settings::GAME_SPEED(), 0);
            break;
    }
}

int Character::getDirectionIndex(Character::Direction dir) {
    switch (dir) {
        case Down:
            return 0;
        case Up:
            return 1;
        case Right:
            return 2;
        case Left:
            return 3;
    }
}

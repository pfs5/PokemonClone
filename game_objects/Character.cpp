//
// Created by patrik on 09.12.16..
//

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include "Character.h"
#include "../settings/Settings.h"

Character::Character(std::string name, sf::Vector2f startPosition) {
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
    _charSprite.setTextureRect(sf::IntRect(1 * sizeX, 0, sizeX, sizeY));
    _charSprite.setPosition(startPosition.x * Settings::SCALE(),
                            (startPosition.y - (sizeY - sizeX)) * Settings::SCALE());

    // Set direction
    _direction = Down;
    _counter = 0;

    _moving = false;
    _turning = false;
    _moveCounter = 0;
    _moveState = 1;

    _lastPosition = getPosition();

    std::cerr << "Successfully loaded character \"" + name + "\"." << std::endl;

}

void Character::input() {

}

void Character::update() {
    _lastPosition = getPosition();
    if (_moving) {
        move(_direction);
    }
}

void Character::draw(sf::RenderWindow *window) {
    window->draw(_charSprite);
}

void Character::move(Character::Direction dir) {
    _charSprite.setTextureRect(sf::IntRect((1 - _counter) * sizeX, getDirectionIndex(dir) * sizeY, sizeX, sizeY));

    _direction = dir;

    // Moving
    float moveStep = Settings::BASE() / Settings::GAME_SPEED() * Settings::SCALE();

    if (!_turning) {
        switch (dir) {
            case Up:
                _charSprite.move(0, -moveStep);
                break;
            case Down:
                _charSprite.move(0, moveStep);
                break;
            case Left:
                _charSprite.move(-moveStep, 0);
                break;
            case Right:
                _charSprite.move(moveStep, 0);
                break;
        }
    }

    _moveCounter += (Settings::BASE() / Settings::GAME_SPEED());
    if (_moveCounter >= Settings::BASE()) {
        // Reset sprite to stop view
        _counter = 0;
        _charSprite.setTextureRect(sf::IntRect((1 - _counter) * sizeX, getDirectionIndex(dir) * sizeY, sizeX, sizeY));

        _moving = false;
    }
}

void Character::startMove(Direction dir) {
    if (dir != _direction) {
        _turning = true;
        _counter = 0;
    } else {
        _turning = false;
        _counter = _moveState;
    }
    _turning = dir != _direction;


    _moveCounter = 0;
    _direction = dir;

    _moving = true;
    _moveState *= -1;
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

sf::Vector2f Character::getPosition() {
    return _charSprite.getPosition();
}

void Character::undo() {
    _charSprite.setPosition(_lastPosition);
}

bool Character::checkCollision(Collider &other) {
    // TODO
    return false;
}


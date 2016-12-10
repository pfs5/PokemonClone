//
// Created by patrik on 09.12.16..
//

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include "MainCharacter.h"
#include "../settings/Settings.h"

MainCharacter::MainCharacter(const std::string &name, sf::Vector2f startPosition) : Character(name, startPosition) {
}

void MainCharacter::update() {
    if (_moving) {
        Character::update();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        startMove(Up);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        startMove(Left);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        startMove(Down);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        startMove(Right);
    }
}

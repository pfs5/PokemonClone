//
// Created by patrik on 09.12.16..
//

#include <iostream>
#include "MainCharacter.h"
#include "../settings/Settings.h"

MainCharacter::MainCharacter(const std::string &name) : Character(name) {
    // Set center position
    _charSprite.setPosition(Settings::WINDOW_WIDTH() / 2 - sizeX / 2, Settings:: WINDOW_HEIGHT() / 2 - sizeY / 2);
}

void MainCharacter::update() {
    Character::update();
}

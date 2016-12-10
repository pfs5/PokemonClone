//
// Created by patrik on 09.12.16..
//

#ifndef GAMEENGINE_MAINCHARACTER_H
#define GAMEENGINE_MAINCHARACTER_H


#include "Character.h"

class MainCharacter: public Character {
public:
    MainCharacter(const std::string &name, sf::Vector2f startPosition);
    void update();
};


#endif //GAMEENGINE_MAINCHARACTER_H

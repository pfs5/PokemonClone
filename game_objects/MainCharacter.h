//
// Created by patrik on 09.12.16..
//

#ifndef GAMEENGINE_MAINCHARACTER_H
#define GAMEENGINE_MAINCHARACTER_H


#include "Character.h"

class MainCharacter: public Character {
public:
    MainCharacter(const std::string &name);
    void update();
};


#endif //GAMEENGINE_MAINCHARACTER_H

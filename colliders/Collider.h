//
// Created by patrik on 11.12.16..
//

#ifndef GAMEENGINE_COLLIDER_H
#define GAMEENGINE_COLLIDER_H

#include <SFML/Window.hpp>

class Collider {
public:
    virtual void undo()=0;

    virtual bool checkCollision(Collider &other)=0;

    virtual sf::Vector2f getPosition()=0;
};

#endif //GAMEENGINE_COLLIDER_H

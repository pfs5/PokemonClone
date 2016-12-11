//
// Created by patrik on 07.12.16..
//

#ifndef GAMEENGINE_GAMEOBJECT_H
#define GAMEENGINE_GAMEOBJECT_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "../colliders/Collider.h"

class GameObject: public Collider {
public:
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;

    virtual void undo()=0;
    virtual bool checkCollision(Collider &other)=0;
    virtual sf::Vector2f getPosition()=0;

    virtual unsigned int getSizeX()=0;
    virtual unsigned int getSizeY()=0;

    std::string getLabel() {return _label;}
protected:
    sf::Vector2f _position;
    std::string _label;
};


#endif //GAMEENGINE_GAMEOBJECT_H

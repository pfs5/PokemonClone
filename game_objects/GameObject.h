//
// Created by patrik on 07.12.16..
//

#ifndef GAMEENGINE_GAMEOBJECT_H
#define GAMEENGINE_GAMEOBJECT_H


#include <SFML/Graphics/RenderWindow.hpp>

class GameObject {
public:
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;

    std::string getLabel() {return _label;}
protected:
    sf::Vector2f _position;
    std::string _label;
};


#endif //GAMEENGINE_GAMEOBJECT_H

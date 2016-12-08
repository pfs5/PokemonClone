//
// Created by patrik on 07.12.16..
//

#ifndef GAMEENGINE_TESTOBJECT_H
#define GAMEENGINE_TESTOBJECT_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "GameObject.h"
#include "../settings/Settings.h"

class TestObject : public GameObject {
private:
    sf::RectangleShape _rectangle;
    float _jumpPower;
    float _stepSize;

private:
    void getInput();

public:
    TestObject();

    TestObject(float x, float y);

    void update();

    void draw(sf::RenderWindow *window);

    void input();
};

#endif //GAMEENGINE_TESTOBJECT_H

//
// Created by patrik on 07.12.16..
//

#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "GameObject.h"
#include "TestObject.h"

sf::RectangleShape _rectangle;
sf::Vector2f _speed;

TestObject::TestObject() {
    TestObject(0, 0);
}

TestObject::TestObject(float x, float y) {
    // Transform
    _position = {x, y};

    _rectangle.setSize({30, 30});
    _rectangle.setFillColor(sf::Color::Green);

    _speed = {0, 0};
    _jumpPower = 7;
    _stepSize = 2;
}

void TestObject::input() {

}

void TestObject::update() {
    getInput();

    // Translate
    _speed += GRAVITY;
    _position += _speed;

    // Move
    _rectangle.setPosition(_position);
}

void TestObject::draw(sf::RenderWindow *window) {
    window->draw(_rectangle);
}

void TestObject::getInput() {
    // Jump
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _speed.y = -_jumpPower;
    }

    // Up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

    }
    // Down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

    }
    // Left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _position.x = _position.x - _stepSize;
    }
    // Right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _position.x = _position.x + _stepSize;
    }
}
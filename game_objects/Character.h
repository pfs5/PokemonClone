//
// Created by patrik on 09.12.16..
//

#ifndef GAMEENGINE_CHARACTER_H
#define GAMEENGINE_CHARACTER_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"

class Character: public GameObject {
public:
    Character(std::string name);
    void input();
    void update();
    void draw(sf::RenderWindow *window);

protected:
    static const int sizeX = 16;
    static const int sizeY = 19;

    sf::Texture _charTexture;
    sf::Sprite _charSprite;

    enum Direction {Up, Down, Left, Right};
    Direction _direction;
    int _counter;

    void move(Direction dir);
    int getDirectionIndex(Direction dir);
};


#endif //GAMEENGINE_CHARACTER_H

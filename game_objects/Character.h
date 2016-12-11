//
// Created by patrik on 09.12.16..
//

#ifndef GAMEENGINE_CHARACTER_H
#define GAMEENGINE_CHARACTER_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"
#include "../colliders/Collider.h"

class Character : public GameObject {
public:
    Character(std::string name, sf::Vector2f initPosition);

    void input();

    void update();

    void draw(sf::RenderWindow *window);

    sf::Vector2f getPosition();

    unsigned int getSizeX() {return sizeX;}
    unsigned int getSizeY() {return sizeY;}

    // Collider methods
    void undo();
    bool checkCollision(Collider &other);

protected:
    static const int sizeX = 16;
    static const int sizeY = 19;

    // Drawing
    sf::Texture _charTexture;
    sf::Sprite _charSprite;

    // Movement
    enum Direction {
        Up, Down, Left, Right
    };
    Direction _direction;
    int _counter;           // sprite counter
    float _moveCounter;     // move sequence counter
    int _moveState;         // moving sprite select

    // Position saving
    sf::Vector2f _lastPosition;

    // Flags
    bool _turning;          // turning flag
    bool _moving;           // movement flag

    // Functions
    void move(Direction dir);

    void startMove(Direction dir);

    int getDirectionIndex(Direction dir);

};


#endif //GAMEENGINE_CHARACTER_H

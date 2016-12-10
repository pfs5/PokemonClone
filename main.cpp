#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

#include "settings/Settings.h"
#include "game_objects/GameObject.h"
#include "maps/Map.h"
#include "game_objects/Character.h"
#include "game_objects/MainCharacter.h"

enum Direction {
    Up, Down, Left, Right
};

// Global variables
Map gameMap;                                // current map
std::vector<GameObject *> gameObjects;      // game objects
sf::RenderWindow *window;                   // main window
sf::View *view;                             // current view

bool moving;                                // movement flag
bool turning;                               // turning flag
float moveCounter;                          // movement counter
Direction direction;                        // movement direction

void Setup() {
    // Setup window
    sf::Vector2i centerWindow(sf::VideoMode::getDesktopMode().width / 2 - Settings::WINDOW_WIDTH() / 2,
                              sf::VideoMode::getDesktopMode().height / 2 - Settings::WINDOW_HEIGHT() / 2);
    window = new sf::RenderWindow(sf::VideoMode(Settings::WINDOW_WIDTH(), Settings::WINDOW_HEIGHT()),
                                  Settings::WINDOW_TITLE(),
                                  sf::Style::Titlebar | sf::Style::Close);
    window->setPosition(centerWindow);

    // Initiate test game objects
    sf::Vector2f mainCharPosition = {20*Settings::BASE(), 30*Settings::BASE()};
    MainCharacter *mainCharacter = new MainCharacter("char1", mainCharPosition);
    gameObjects.push_back(mainCharacter);

    // Load map
    gameMap.loadMap("route1");
    direction = Down;

    // Setup view
    view = new sf::View(sf::FloatRect(0, 0, Settings::WINDOW_WIDTH(), Settings::WINDOW_HEIGHT()));
    view->setCenter(mainCharacter->getPosition());
    window->setView(*view);
    moving = false;
}

void move(Direction dir) {
    turning = direction != dir;

    direction = dir;
    moving = true;
    moveCounter = 0;
}

void updateView() {

    if (moving) {
        // Move
        float moveStep = Settings::BASE() / Settings::GAME_SPEED() * Settings::SCALE();
        if (!turning) {
            switch (direction) {
                case Up:
                    view->move(0, -moveStep);
                    break;
                case Down:
                    view->move(0, moveStep);
                    break;
                case Left:
                    view->move(-moveStep, 0);
                    break;
                case Right:
                    view->move(moveStep, 0);
                    break;
            }
        }
        window->setView(*view);

        // Increase counter and check
        moveCounter += (Settings::BASE() / Settings::GAME_SPEED());
        if (moveCounter >= Settings::BASE()) {
            moving = false;
        }

        return;
    }

    // Get input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        move(Up);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        move(Left);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        move(Down);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        move(Right);
    }
}

void Input() {

}

void Update() {
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->update();
    }

    updateView();
}

void Draw() {
    // Draw background map
    gameMap.drawBottom(*window);

    // Draw game objects
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->draw(window);
    }

    // Draw top map
    gameMap.drawTop(* window);
}


int main() {
    Setup();

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / Settings::UPS());

    while (window->isOpen()) {
        sf::Event event;

        // Event loop
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
            }
        }

        window->clear();

        Input();

        while (accumulator > ups) {
            accumulator -= ups;
            Update();
        }

        Draw();
        window->display();

        accumulator += clock.restart();
    }

    return 0;
}
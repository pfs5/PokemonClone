#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

#include "settings/Settings.h"
#include "game_objects/GameObject.h"
#include "game_objects/TestObject.h"

// Settings
std::string RESOURCES_PATH;
int WINDOW_WIDTH;
int WINDOW_HEIGHT;
std::string WINDOW_TITLE;
sf::Vector2f GRAVITY;
int UPS;

// Global variables
std::vector<GameObject *> gameObjects;      // game objects
sf::RenderWindow *window;                   // main window
sf::View *view;                             // current view

void setupGlobal() {
    // Init global TODO
    RESOURCES_PATH = "../resources/";
    WINDOW_WIDTH = 500;
    WINDOW_HEIGHT = 500;
    WINDOW_TITLE = "Game";

    GRAVITY = {0, 0.3};

    UPS = 100;
}

void Setup() {
    setupGlobal();

    // Setup window
    sf::Vector2i centerWindow(sf::VideoMode::getDesktopMode().width / 2 - WINDOW_WIDTH / 2,
                              sf::VideoMode::getDesktopMode().height / 2 - WINDOW_HEIGHT / 2);
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE,
                                  sf::Style::Titlebar | sf::Style::Close);
    window->setPosition(centerWindow);

    // Setup view
    view = new sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
    window->setView(*view);

    // Initiate test game objects
    gameObjects.push_back(new TestObject(100, 100));
}

void Input() {

}

void Update() {
    for (int i=0; i<gameObjects.size(); i++) {
        gameObjects[i]->update();
    }
}

void Draw() {
    for (int i=0; i<gameObjects.size(); i++) {
        gameObjects[i]->draw(window);
    }
}


int main() {
    Setup();

    clock_t start;
    clock_t end;
    int period = (int) CLOCKS_PER_SEC / UPS;

    start = clock();
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

        end = clock();
        if ((int)(end - start) > period) {
            Update();
            start = end;
        }
        Draw();

        window->display();
    }

    return 0;
}
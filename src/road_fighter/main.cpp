#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <zconf.h>
#include "../road_fighter_sfml/EntityFactorySFML.h"
#include "../road_fighter_sfml/GameSFML.h"
#include <time.h>
#include <thread>

using namespace std;
using namespace chrono;
using namespace road_fighter_SFML;

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    shared_ptr<sf::RenderWindow> window = make_shared<sf::RenderWindow>(sf::VideoMode(1280, 960, desktop.bitsPerPixel), "Road Fighter");
//    sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "SFML works!", sf::Style::Fullscreen);

    road_fighter::Transformation::getInstance().setResolution(1280, 960);
    GameSFML g(window);

    steady_clock::time_point fpsTimer(steady_clock::now());
    duration<double, ratio<1, 60>> FPS{};
//    microseconds loopTime{};

    while (window->isOpen())
    {
        FPS = duration_cast<duration<int32_t, ratio<1, 60>>>(steady_clock::now() - fpsTimer);
        if (FPS.count() >= 1) {
            fpsTimer = steady_clock::now();
            window->clear();
            g.drawEntities();
            window->display();
            g.handleInput();
            g.handleMovement();
            g.spawnPassableCar();
            g.checkCollisions();
            g.cleanEntities();
            g.checkEnd();
            unique_ptr<sf::Event> event = make_unique<sf::Event>(sf::Event());
            while (window->pollEvent(*event))
            {
                if (event->type == sf::Event::Closed)
                    window->close();
                if (event->type == sf::Event::KeyPressed) {
                    if (event->key.code == sf::Keyboard::Escape) {
                        window->close();
                    }
                }
            }
        }
    }
    return 0;
}

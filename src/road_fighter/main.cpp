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

//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);

    steady_clock::time_point fpsTimer(steady_clock::now());
//    duration<int32_t, ratio<1, 60>> FPS{};
    window->setVerticalSyncEnabled(false);
//    microseconds loopTime{};

//    sf::Texture bgTexture;
//    bgTexture.loadFromFile("../graphics/Background.png");
//    sf::Sprite background;
//    background.setTexture(bgTexture);
//    sf::Sprite background2 = background;
//    background2.move(0, -960);
//    window->setView(view);
//    sf::Vector2f oldSize = static_cast<sf::Vector2f>(background.getTexture()->getSize());
//    sf::Vector2f newSize(static_cast<float>(1280), static_cast<float>(960));
//    background.setScale(newSize.x/oldSize.x, newSize.y/oldSize.y);

    while (window->isOpen())
    {
//        if (background.getPosition().y >= 960) {
//            background.setPosition(0, -960);
//        }
//        if (background2.getPosition().y >= 960) {
//            background2.setPosition(0, -960);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//            background.move(0, 0.03f);
//            background2.move(0, 0.03f);
//        }

//        FPS = duration_cast<duration<int32_t, ratio<1, 60>>>(steady_clock::now() - fpsTimer);
//        if (FPS.count() >= 1)
//        {
        fpsTimer = steady_clock::now();
        window->clear();
        g.drawEntities();
        window->display();
        g.handleInput();
        g.handleMovement();
        g.spawnPassableCar();
        g.checkCollisions();
        g.cleanEntities();
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window->close();
                }
            }
        }
        this_thread::sleep_until(fpsTimer + duration<double>(1/60.0));
//        }
    }
    return 0;
}

#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include "../road_fighter_sfml/EntityFactorySFML.h"
#include "../road_fighter_sfml/GameSFML.h"
#include <thread>

using namespace std;
using namespace chrono;
using namespace road_fighter_SFML;

int main() {
    // Create SFML window
    shared_ptr<sf::RenderWindow> window = make_shared<sf::RenderWindow>(sf::VideoMode(1280, 960), "Road Fighter");

    // Set resolution for correct transformations
    road_fighter::Transformation::getInstance().setResolution(1280, 960);

    // Pass window to game (for draw calls)
    GameSFML g(window);

    // Timer for framerate lock
    steady_clock::time_point fpsTimer(steady_clock::now());
    duration<double, ratio<1, 60>> FPS{};

    using frames = duration<int64_t, ratio<1, 62>>;
    auto nextFrame = steady_clock::now() + frames{0};

    // Main game loop
    while (window->isOpen())
    {
        // Perform intersection test

        // Lock framerate to 60FPS (one tick every 1/60th of a second)
        FPS = duration_cast<duration<int32_t, ratio<1, 60>>>(steady_clock::now() - fpsTimer);
        if (FPS.count() > 0) {
            nextFrame += frames{1};
            fpsTimer = steady_clock::now();
            window->clear();
            g.drawEntities();
            window->display();
            g.executeTick();

            // Event for checking on application close (close with escape or close button)
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
            // Sleep for duration to reduce cpu load, although very rarely causes slight hitching
            this_thread::sleep_until(nextFrame);
        }
    }
    return 0;
}

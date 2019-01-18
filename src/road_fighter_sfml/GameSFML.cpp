//
// Created by sam on 28.12.18.
//

#include "GameSFML.h"

using namespace road_fighter_SFML;

void GameSFML::handleInput()
{
        // Spawn bullet when space is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                spawnBullet();
        }
        // Handle all other input
        handleInputWorld();
}

GameSFML::GameSFML(const shared_ptr<sf::RenderWindow>& w)
    : Game(static_pointer_cast<road_fighter::EntityFactory>(make_shared<EntityFactorySFML>(w)))
{
}
//
// Created by sam on 28.12.18.
//

#include "GameSFML.h"

using namespace road_fighter_SFML;

void GameSFML::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        spawnBullet();
    }
    handleInputWorld();
}

GameSFML::GameSFML(const shared_ptr<sf::RenderWindow>& w) : Game(static_pointer_cast<road_fighter::EntityFactory>(make_shared<EntityFactorySFML>(w))) {}
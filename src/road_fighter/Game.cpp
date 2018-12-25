//
// Created by sam on 11.12.18.
//

#include "Game.h"

using namespace road_fighter;

Game::Game(shared_ptr<EntityFactory> &f) : factory(f), world(factory->createWorld()) {
    world->setPlayer(factory->createPlayerCar());
}

void Game::drawEntities() {
    world->draw();
}

void Game::handleInput() {
    world->handleInput();
}

void Game::handleMovement() {
    world->handleMovement();
}

void Game::spawnPassableCar() {
    double rnd = Random::getInstance().getRandom(0, 1);
    if (rnd < 1/300.0) {
        world->addEntity(factory->createPassableCar());
    }
}

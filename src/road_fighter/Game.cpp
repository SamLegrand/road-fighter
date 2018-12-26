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

void Game::checkCollisions() {
    world->checkCollisions();
}

void Game::spawnPassableCar() {
    double rnd = Random::getInstance().getRandom(0, 1);
    unsigned int counter = 0;
    if (rnd < 1/300.0) {
        while (++counter < 3 && !world->addPassableCar(factory->createPassableCar()));
    }
}

void Game::spawnBullet() {
    world->spawnBullet(factory->createBullet());
}

void Game::cleanEntities() {
    world->cleanEntities();
}
